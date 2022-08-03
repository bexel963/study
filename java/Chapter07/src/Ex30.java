interface MyInterface {
	
	default void method1() {
		System.out.println("method1() in MyInterface");
	}
	default void method2() {
		System.out.println("method2() in MyInterface");
	}
	static void staticMethod() {
		System.out.println("staticMethod() in MyInterface");
	}
}
interface MyInterface2 {
	
	default void method1() {
		System.out.println("method1() in MyInterface2");
	}
	static void staticMethod() {
		System.out.println("staticMethod() in MyInterface2");
	}
}
class Parent0 {
	
	public void method2() {
		System.out.println("method2() in Parent");
	}
}

class Child0 extends Parent0 implements MyInterface, MyInterface2 {
	
	public void method1() {			// 여러 인터페이스의 디폴트 메서드 간의 충돌 -> 오버라이딩 해야함.
		System.out.println("method1() in Child");
	}
}
public class Ex30 {

	public static void main(String[] args) {

		Child0 c = new Child0();
		c.method1();
		c.method2();
		MyInterface.staticMethod();
		MyInterface2.staticMethod();
	}

}
