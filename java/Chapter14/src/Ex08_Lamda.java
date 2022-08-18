import java.util.Arrays;
import java.util.function.Function;
import java.util.function.Supplier;
/*
 	- 메서드 참조
 		: 람다식이 하나의 메서드만 호출하는 경우에는 '메서드 참조'라는 방법으로 람다식을 간략히 할 수 있다.
 		
 		Function<String, Integer> f = (String s) -> Integer.parseInt(s);
 		Function<String, Integer> f = Integer::parseInt;
 		: 위 두 코드는 같다. 컴파일러는 생략된 부분을 우변의 parseInt메서드의 선언부로부터, 또는 좌변의 Function인터페이스에 지정된
 		  지네릭 타입으로부터 쉽게 알아낼 수 있다.
 	- 생정자의 메서드 참조
*/
class MyClass {
	
	private int lv;
	
	MyClass() {
		
	}
	MyClass(int lv){
		this.lv = lv;
	}
	public int getLv() {
		return lv;
	}
}
public class Ex08_Lamda {

	public static void main(String[] args) {
		
//		Supplier<MyClass> s = () -> new MyClass();
		Supplier<MyClass> s = MyClass::new;		// 위 코드와 같음.
		
		MyClass mc = s.get();
		System.out.println(mc);
		System.out.println(s.get());
		
		System.out.println("===================================");
		
//		Function<Integer, MyClass> f = (i) -> new MyClass(i);
		Function<Integer, MyClass> f = MyClass::new;	// 위 코드와 같음.
		
		MyClass mc2 = f.apply(100);
		System.out.println(mc2);
		System.out.println(mc2.getLv());
		System.out.println(f.apply(200).getLv());
		
		System.out.println("===================================");
		
//		Function<Integer, int[]> arrF = (i) -> new int[i];
		Function<Integer, int[]> arrF = int[]::new;		// 위 코드와 같음
		
		int[] arr = arrF.apply(10);
		Arrays.setAll(arr, (i)->(int)(Math.random()*10)+1);
		System.out.println(Arrays.toString(arr));
	}

}









