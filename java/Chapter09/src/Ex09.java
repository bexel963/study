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
 * clone()�� �ܼ��� ��ü�� ����� ���� �״�� ������ ��, ��ü�� �����ϰ� �ִ� ��ü���� ���������� �ʴ´�.
 * �⺻�� �迭�� ��쿡�� �ƹ��� ������ ������, ��ü�迭�� clone()���� �����ϴ� ��쿡�� ������ �������� ���� ��ü�� �����ϹǷ�
 * ������ ������� ����� ��ƴ�.(���� ����)
 * �ݸ鿡 ������ �����ϰ� �ִ� ��ü���� �����ϴ� ���� ���� ���� ��� �Ѵ�.
 * ���� ���翡���� ������ ���纻�� ���� �ٸ� ��ü�� �����ϱ� ������ ������ ������ ���纻�� ������ ��ġ�� �ʴ´�.
 * */
 