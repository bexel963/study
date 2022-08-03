
public class Ex08 {

	public static void main(String[] args) {
		System.out.println("main(String[] args)이 시작 되었음");
		firstMethod();
		System.out.println("main(String[] args)이 종료 되었음");
	}
	
	static void firstMethod() {
		System.out.println("firstMethod()가 시작 되었음");
		secondMethod();
		System.out.println("firstMethod()가 종료 되었음");
	}
	static void secondMethod() {
		System.out.println("secondMethod()가 시작 되었음");
		System.out.println("secondMethod()");
		System.out.println("secondMethod()가 종료 되었음");
	}
}
