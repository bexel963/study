// < 강한 결합 >
/*
class A {
	public void methodA(B b) {
		b.methodB();
	}
}
class B {
	public void methodB() {
		System.out.println("methodB()");
	}
}

public class Ex27 {

	public static void main(String[] args) {

		A a = new A();
		a.methodA(new B());
	}

}
*/

// < 느슨한 결합 >
interface I {			// 0. 인터페이스를 선언하며 공급작 클래스의 선언부와 구현부를 나눈다.
	public abstract void methodB();
}
class B implements I {
	public void methodB() {
		System.out.println("methodB()");
	}
}
class C implements I {	// 1. methodB의 내용을 변경해도 ( I를 구현한 새로운 클래스를 만들고 새로 구현한 메소드의 내용을 바꾼다. )
	public void methodB() {
		System.out.println("methodC()");
	}
}

class A {				// 2. 사용자에는 변화가 없다.
	public void methodA(I i) {
		i.methodB();
	}
}

public class Ex27 {

	public static void main(String[] args) {

		A a = new A();
		a.methodA(new B());
		a.methodA(new C());	// 3. 사용자 클래스(A)는 공급자 클래스(B)내부 내용을 모른채 사용 하기만 하면 된다.
	}

}