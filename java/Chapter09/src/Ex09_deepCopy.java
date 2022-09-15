/*
	  - clone()�� �ܼ��� ��ü�� ����� ���� �״�� ������ ��, ��ü�� �����ϰ� �ִ� ��ü���� ���������� �ʴ´�.
	  	�⺻�� �迭�� ��쿡�� �ƹ��� ������ ������, ��ü�迭�� clone()���� �����ϴ� ��쿡�� ������ �������� ���� ��ü�� �����ϹǷ�
	  	������ ������� ����� ��ƴ�.(���� ����)
	  	�ݸ鿡 ������ �����ϰ� �ִ� ��ü���� �����ϴ� ���� ���� ���� ��� �Ѵ�.
	  	���� ���翡���� ������ ���纻�� ���� �ٸ� ��ü�� �����ϱ� ������ ������ ������ ���纻�� ������ ��ġ�� �ʴ´�.
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


 