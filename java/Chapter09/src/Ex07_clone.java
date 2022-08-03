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
