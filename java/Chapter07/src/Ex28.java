// �����Ѱ��� ���1 : �Ű������� ���ؼ� �������̽� I�� ������ Ŭ������ �ν��Ͻ��� �������� �����޴´�.
//		- Thread�� �������� Thread(Runnable target)�� �̷� ������� �Ǿ�����.

interface I0 {
	public abstract void play();
}
class B0 implements I0 {
	public void play() {
		System.out.println("play in B class");
	}
}
class C0 implements I0 {
	public void play() {
		System.out.println("play in C class");
	}
}

class A0 {
	void autoPlay(I0 i) {
		i.play();
	}
}
public class Ex28 {

	public static void main(String[] args) {
		
		A0 a = new A0();
		
		a.autoPlay(new B0());
		a.autoPlay(new C0());
	}
}
