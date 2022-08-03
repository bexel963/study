class Point2 {
	int x, y;
	
	Point2(int x, int y){
		this.x = x;
		this.y = y;
	}
	public String toString() {
		return "(" + x + ", " + y + ")";
	}
}
class Circle implements Cloneable {
	
	Point2 p;
	double r;
	
	Circle(Point2 p, double r){
		this.p = p;
		this.r = r;
	}
	public Circle shallowCopy() {
		Object obj = null;
		try {
			obj = super.clone();
		} catch(CloneNotSupportedException e) {
			
		}
		return (Circle)obj;
	}
	public Circle deepCopy() {
		Object obj = null;
		try {
			obj = super.clone();
		} catch(CloneNotSupportedException e) {
			
		}
		Circle c = (Circle)obj;
		c.p = new Point2(this.p.x, this.p.y);
		
		return c;
	}
	public String toString() {
		return "[p=" + p + ", r=" + r + "]";
	}
}
public class Ex09 {

	public static void main(String[] args) {

		Circle c1 = new Circle(new Point2(1, 1), 2.0);
		Circle c2 = c1.shallowCopy();
		Circle c3 = c1.deepCopy();
		
		System.out.println("c1=" + c1);
		System.out.println("c2=" + c2);
		System.out.println("c2=" + c3);
		
		System.out.println();
		
		c1.p.x = 9;
		c1.p.y = 9;
		c1.r = 3;
		
		System.out.println("c1=" + c1);
		System.out.println("c2=" + c2);
		System.out.println("c3=" + c3);
	}

}

/*
 * clone()은 단순히 객체에 저장된 값을 그대로 복제할 뿐, 객체가 참조하고 있는 객체까지 복제하지는 않는다.
 * 기본형 배열인 경우에는 아무런 문제가 없지만, 객체배열을 clone()으로 복제하는 경우에는 원본과 복제본이 같은 객체를 공유하므로
 * 완전한 복제라고 보기는 어렵다.(얕은 복사)
 * 반면에 원본이 참조하고 있는 객체까지 복제하는 것을 깊은 복사 라고 한다.
 * 깊은 복사에서는 원본과 복사본이 서로 다른 객체를 참조하기 때문에 원본의 변경이 복사본에 영향을 미치지 않는다.
 * */
 