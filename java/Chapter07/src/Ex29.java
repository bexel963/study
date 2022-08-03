// 느슨한결합 방법2 : 제3의 클래스를 통해서 제공받는다.
//			- JDBC의 DriverManager클래스가 이런 방식으로 되어있다.

interface I2 {
	public abstract void methodB();
}
class B2 implements I2 {
	public void methodB() {
		System.out.println("methodB in B class");
	}
	public String toString() {
		return "class B";
	}
}

class InstanceManager {
	public static I2 getInstance() {
		return new B2();
	}
}
class A2 {
	void methodA() {
		I2 i = InstanceManager.getInstance();
		i.methodB();
		System.out.println(i.toString());
	}
}
public class Ex29 {

	public static void main(String[] args) {

		A2 a = new A2();
		a.methodA();
	}

}
