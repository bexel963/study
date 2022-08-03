// < ���� ���� >
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

// < ������ ���� >
interface I {			// 0. �������̽��� �����ϸ� ������ Ŭ������ ����ο� �����θ� ������.
	public abstract void methodB();
}
class B implements I {
	public void methodB() {
		System.out.println("methodB()");
	}
}
class C implements I {	// 1. methodB�� ������ �����ص� ( I�� ������ ���ο� Ŭ������ ����� ���� ������ �޼ҵ��� ������ �ٲ۴�. )
	public void methodB() {
		System.out.println("methodC()");
	}
}

class A {				// 2. ����ڿ��� ��ȭ�� ����.
	public void methodA(I i) {
		i.methodB();
	}
}

public class Ex27 {

	public static void main(String[] args) {

		A a = new A();
		a.methodA(new B());
		a.methodA(new C());	// 3. ����� Ŭ����(A)�� ������ Ŭ����(B)���� ������ ��ä ��� �ϱ⸸ �ϸ� �ȴ�.
	}

}