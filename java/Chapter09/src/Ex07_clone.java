/*
	- clone()은 자신을 복제하여 새로운 인스턴스를 생성한다.
	  어떤 인스턴스에 대해 작업을 할 때, 원래의 인스턴스는 보존하고 clone메서드를 이용해서 새로운 인스턴스를 생성하여 작업을 하면,
	  작업이전의 값이 보존되므로 작업에 실패해서 원래의 상태로 되돌리거나 변경되기 전의 값을 참고하는데 도움이 된다.
	  단순히 인스턴스변수의 값만 복사하기 대문에 참조타입의 인스턴스 변수가 있는 클래스는 완전한 인스턴스 복제가 이루어지지 않는다.
	  한 예로, 배열의 경우, 복제된 인스턴스도 같은 배열의 주소를 갖기 때문에 복제된 인스턴스의 작업이 원래의 인스턴스에 영향을 미친다.
	  이런 경우 clone()을 오버라이딩해서 새로운 배열을 생성하고 배열의 내용을 복사하도록 해야한다.
 
*/


class Point implements Cloneable {		// Cloneable 인터페이스를 구현한 클래스에서만 clone()을 호출할 수 있다.
										// 이 인터페이스를 구현하지 않고 clone()을 호출하면 예외가 발생한다.
	int x, y;
	
	Point(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	public String toString() {
		return "x=" + x + ", y=" + y;
	}
	
	public Object clone() {			// 접근제어자를 protected에서 public으로 변경한다.
		Object obj = null;
		try {
			obj = super.clone();	// clone()은 반드시 예외 처리를 해주어야 한다. - 조상클래스의 clone()을 호출
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
