/*
	  - clone()은 단순히 객체에 저장된 값을 그대로 복제할 뿐, 객체가 참조하고 있는 객체까지 복제하지는 않는다.
	  	기본형 배열인 경우에는 아무런 문제가 없지만, 객체배열을 clone()으로 복제하는 경우에는 원본과 복제본이 같은 객체를 공유하므로
	  	완전한 복제라고 보기는 어렵다.(얕은 복사)
	  	반면에 원본이 참조하고 있는 객체까지 복제하는 것을 깊은 복사 라고 한다.
	  	깊은 복사에서는 원본과 복사본이 서로 다른 객체를 참조하기 때문에 원본의 변경이 복사본에 영향을 미치지 않는다.
*/

class Points {
	
	private int x;
	private int y;
	
	Points(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public String toString() {
		return "x: " + x + ", y: " + y; 
	}
}
class Circles implements Cloneable {
	
	private Points p;
	private int r;
	
	Circles(){
		this(new Points(1,1), 1);
	}
	Circles(Points p, int r){
		this.p = p;
		this.r = r;
	}
	
	public Points getP() {
		return p;
	}
	public void setP(Points p) {
		this.p = p;
	}
	public int getR() {
		return r;
	}
	public void setR(int r) {
		this.r = r;
	}
	public Circles shallowCopy() {
		
		try {
			return (Circles)this.clone();
		} catch (CloneNotSupportedException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public Circles deepCopy() {
		Circles c = null;
		try {
			c = (Circles)this.clone();
		} catch (CloneNotSupportedException e) {
			e.printStackTrace();
		}
		c.p = new Points(1, 1);
		
		return c;
	}
	public String toString() {
		return p.toString() + ", r: " + r;
	}
}

public class Ex09_deepCopy {

	public static void main(String[] args) {

		Circles circle1 = new Circles();
		Circles circle2 = new Circles();
		Circles newCircle1 = circle1.shallowCopy();
		Circles newCircle2 = circle2.deepCopy();
		
		System.out.println("circle1 => " + circle1);
		System.out.println("circle2 => " + circle2);
		System.out.println("newCircle1 => " + newCircle1);
		System.out.println("newCircle2 => " + newCircle2);
		
		System.out.println("-----------------------------------------");
		
		newCircle1.getP().setX(1000);
		newCircle1.getP().setY(1000);
		newCircle2.getP().setX(1000);
		newCircle2.getP().setY(1000);
		
		System.out.println("circle1 => " + circle1);
		System.out.println("circle2 => " + circle2);
		System.out.println("newCircle1 => " + newCircle1);
		System.out.println("newCircle2 => " + newCircle2);
	}

}


 