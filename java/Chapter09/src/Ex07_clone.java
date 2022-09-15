/*
	- clone()�� �ڽ��� �����Ͽ� ���ο� �ν��Ͻ��� �����Ѵ�.
	  � �ν��Ͻ��� ���� �۾��� �� ��, ������ �ν��Ͻ��� �����ϰ� clone�޼��带 �̿��ؼ� ���ο� �ν��Ͻ��� �����Ͽ� �۾��� �ϸ�,
	  �۾������� ���� �����ǹǷ� �۾��� �����ؼ� ������ ���·� �ǵ����ų� ����Ǳ� ���� ���� �����ϴµ� ������ �ȴ�.
	  �ܼ��� �ν��Ͻ������� ���� �����ϱ� �빮�� ����Ÿ���� �ν��Ͻ� ������ �ִ� Ŭ������ ������ �ν��Ͻ� ������ �̷������ �ʴ´�.
	  �� ����, �迭�� ���, ������ �ν��Ͻ��� ���� �迭�� �ּҸ� ���� ������ ������ �ν��Ͻ��� �۾��� ������ �ν��Ͻ��� ������ ��ģ��.
	  �̷� ��� clone()�� �������̵��ؼ� ���ο� �迭�� �����ϰ� �迭�� ������ �����ϵ��� �ؾ��Ѵ�.
 
*/


class Point implements Cloneable {		// Cloneable �������̽��� ������ Ŭ���������� clone()�� ȣ���� �� �ִ�.
										// �� �������̽��� �������� �ʰ� clone()�� ȣ���ϸ� ���ܰ� �߻��Ѵ�.
	int x, y;
	
	Point(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	public String toString() {
		return "x=" + x + ", y=" + y;
	}
	
	public Object clone() {			// ���������ڸ� protected���� public���� �����Ѵ�.
		Object obj = null;
		try {
			obj = super.clone();	// clone()�� �ݵ�� ���� ó���� ���־�� �Ѵ�. - ����Ŭ������ clone()�� ȣ��
		} catch(CloneNotSupportedException e) {
		
		}
		return obj;
	}
}
public class Ex07_clone {

	public static void main(String[] args) {

		Point original = new Point(3, 5);
		Point copy = (Point)original.clone();
		System.out.println(original);
		System.out.println(copy);

	}

}
