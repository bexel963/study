class Tv {
	boolean power;
	int channel;
	
	void power() {
		power = !power;
	}
	void channelUp() {
		++channel;
	}
	void channelDown() {
		--channel;
	}
}

class CaptionTv extends Tv {
	boolean caption;
	
	void displayCaption(String text) {
		if(caption) {
			System.out.println(text);
		}
	}
}


// Shape, Point, Circle, Triangle

class Shape {
	String color = "black";
	void draw() {
		System.out.printf("[color=%s]\n", color);
	}
}
class Point {
	int x, y;
	
	Point(){
		this(0, 0);
	}
	Point(int x, int y){
		super();	// 컴파일러가 자동으로 넣어줌. 조상이 Object클래스라 Object()를 의미한다.
		this.x = x;
		this.y = y;
	}
	String getXY() {
		return "("+ x +", "+ y +")";
	}
}
class Point3D extends Point {
	int z;
	
	Point3D() {
		this(100, 200, 300);
	}
	Point3D(int x, int y, int z){
//		super();// 이거 생략하면 컴파일러가 자동으로 추가해준다. -> 이때 부모 기본생성자 안 만들어져 있으면 컴파일에러!
		super(x, y);
		this.z = z;
	}
	String getXY() {
		return super.getXY() + ", z : " + z;
	}
}
class Circle extends Shape {
	Point center = new Point();
	int r;
	
	Circle() {
		this(new Point(0, 0), 100);
	}
	Circle(Point center, int r){
		this.center = center;
		this.r = r;
	}
	void draw() {
		System.out.printf("[center=(%d, %d), r=%d, color=%s\n", center.x, center.y, r, color);
	}
}
class Triangle extends Shape {
	Point[] point = new Point[3];
	
	Triangle(Point[] p) {
		this.point = p;
	}
	void draw() {
		System.out.printf("[p1=%s, p2=%s, p3=%s, color=%s\n", point[0].getXY(), point[1].getXY(), point[2].getXY(), color);
	}
}

// Card, Deck

class Card {
	static final int KIND_MAX = 4;
	static final int NUM_MAX = 13;
	static final int SPADE = 4;
	static final int DIAMOND = 3;
	static final int HEART = 2;
	static final int CLOVER= 1;
	
	int kind, number;
	
	Card() {
		this(SPADE, 1);
	}
	Card(int kind, int number) {
		this.kind = kind;
		this.number = number;
	}
	public String toString() {
		String[] kinds = { "", "CLOVER", "HEART", "DIAMOND", "SPADE" };
		String numbers = "0123456789XJQK";
		return "kind : " + kinds[this.kind] + ", number : " + numbers.charAt(this.number);
	}
}

class Deck {
	final int CARD_NUM = 52;
	Card[] cardArr = new Card[CARD_NUM];
	
	Deck() {
		int i = 0;
		
		for(int k=Card.KIND_MAX ; k>0 ; k--) {
			for(int n=0 ; n<Card.NUM_MAX ; n++) {
				cardArr[i++] = new Card(k, n+1);
			}
		}
	}
	
	Card pick(int index) {
		return cardArr[index];
	}
	Card pick() {
		int index = (int)(Math.random()*CARD_NUM);
		return pick(index);
	}
	void shuffle() {
		for(int i=0 ; i<cardArr.length ; i++) {
			int r = (int)(Math.random()*CARD_NUM);
			
			Card temp = cardArr[i];
			cardArr[i] = cardArr[r];
			cardArr[r] = temp;
		}
	}
}