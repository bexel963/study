// 느슨한결합 방법1 : 매개변수를 통해서 인터페이스 I를 구현한 클래스의 인스턴스를 동적으로 제공받는다.
//		- Thread의 생성자은 Thread(Runnable target)이 이런 방식으로 되어있음.

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
