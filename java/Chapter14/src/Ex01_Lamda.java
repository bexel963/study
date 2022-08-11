import java.util.ArrayList;
import java.util.Arrays;

@FunctionalInterface
interface MyFunction {
	void run();
}
@FunctionalInterface
interface Plus {
	int plus(int a, int b);
}
public class Ex01_Lamda {

	static void execute(MyFunction f) {
		f.run();
	}
	static MyFunction getMyFunction() {
		MyFunction f = () -> System.out.println("f3.run()");
		return f;
	}
	static void num(int x, int y) {
		System.out.println("x = " + x + ", y = " + y);
	}
	public static void main(String[] args) {
		
		Plus p = (a, b) -> a + b;
		System.out.println(p.plus(2, 3));
		System.out.println((Plus)(a, b) -> a + b);
//		num(1, (a,b)->a+b);
//		int[] arr = new int[10];
//		Arrays.setAll(arr, (a) -> a+a);
		
		MyFunction f1 = () -> System.out.println("f1.run()");
		
		MyFunction f2 = new MyFunction() {
			public void run() {					// 인터페이스의 구현한 클래스의 메서드는 그 접근 제어자의 범위가 인터페이스에 선언된 메서드의 것 보다 좁으면 안 된다.
				System.out.println("f2.run()");
			}
		};
		
		MyFunction f3 = getMyFunction();
		
		f1.run();
		f2.run();
		f3.run();
		
		execute(f1);
		execute(() -> System.out.println("후후"));
	}

}
