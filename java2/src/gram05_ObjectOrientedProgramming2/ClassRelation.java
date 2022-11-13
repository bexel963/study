package gram05_ObjectOrientedProgramming2;

import java.util.Arrays;

class Shape {
    String color = "black";
    void draw() {
        System.out.println(color + "색으로 그린다.");
    }
}
class Point {
    int x;
    int y;

    Point() {
        this(0, 0);
    }
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    String getXY() {
        return "[" + x + ", " + y + "] ";
    }
}
class Circle extends Shape {
    Point center;
    int r;

    Circle() {
        this(new Point(), 100);
    }
    Circle(Point center, int r) {
        this.center = center;
        this.r = r;
    }
    void draw() {
        System.out.println("(" + center.getXY() + this.r + ") 의 원을 " + this.color + "색으로 그린다.");
    }
}
class Triangle extends Shape {
    Point[] p = new Point[3];

    Triangle(Point[] p) {
        this.p = p;
    }
    void draw() {
        System.out.println("(" + p[0].getXY() + p[1].getXY() + p[2].getXY() + ") 의 삼각형을 " + this.color + "색으로 그린다.");
    }
}

class Card {
    static final int KIND_MAX = 4;
    static final int NUM_MAX = 13;
    static final int SPADE = 4;
    static final int DIAMOND = 3;
    static final int HEART = 2;
    static final int CLOVER = 1;

//    public int kind;
//    public int number;

    // 상수이지만 선언과 함께 초기화 하지 않고, 생성자에서 단 한번만 초기화 할 수 있다.
    // 각 카드마다 다른 종류와 숫자를 갖기 때문에 인스턴스 변수를 사용하지만,
    // 일단 카드가 생성되면 생성된 카드의 값이 변경되어서는 안되기 때문에 final을 붙여 상수로 만들어준다.
    final int NUMBER;
    final int KIND;

    Card() {
        this(SPADE, 1);
    }
    Card(int kind, int number) {
        this.KIND = kind;
        this.NUMBER = number;
    }
    @Override
    public String toString() {
        String[] kinds = { "", "CLOVER", "HEART", "DIAMOND", "SPADE" };
        String numbers = "0123456789XJQK";  // 숫자 10은 X로 표현
        return "무늬: " + kinds[this.KIND] + ", 숫자: " + numbers.charAt(this.NUMBER) + "\n";
    }
}
class Deck {
    final int CARD_NUM = 52;
    Card cardArr[] = new Card[CARD_NUM];
    int idx = 0;

    Deck () {
        for(int i=1 ; i<=4 ; i++) {
            for(int j=1 ; j<=Card.NUM_MAX ; j++) {
                cardArr[idx++] = new Card(i, j);
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
    @Override
    public String toString() {
        return Arrays.toString(cardArr);
    }
}
public class ClassRelation {

    public static void main(String[] args) {
        Circle c = new Circle(new Point(3, 3), 20);
        Triangle t = new Triangle(new Point[] { new Point(1, 1), new Point(2, 2), new Point(3, 3)});

        c.draw();
        t.draw();

        System.out.println("\n==========================================\n");

        Deck deck = new Deck();
        System.out.println(deck);
        deck.shuffle();
        System.out.println(deck);
    }
}
