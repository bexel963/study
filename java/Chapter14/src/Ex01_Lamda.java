import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/*
 	- 람다식
 		: 메서드를 하나의 식(expression)으로 표현. 메서드의 이름과 반환값이 없으므로 익명함수(anonymous function) 라고도 한다.
 		: 메서드를 변수처럼 다루는 것이 가능해진다.
 		
 		int max(int a, int b) {
 			return a > b ? a : b;
 		}
 		(int a, int b) -> { return a > b ? a : b; } 
 		(int a, int b) -> a > b ? a : b
 		(a, b) -> a > b ? a : b
 		
 		: 문장(statement)이 아닌 '식' 이므로 끝에 ';'을 붙이지 않는다.
 		: 매개변수의 타입은 추론이 가능한 경우는 생략할 수 있다.
 		: 반환타입도 항상 추론이 가능하기 때문에 생략 가능하다.
 		: 매개변수가 하나뿐ㅇ니 경우에는 괄호를 생략할 수 있다.
 		: 괄호{} 안의 문장이 하낭리 때는 괄호{}를 생략할 수 있다. 그러나 괄호{} 안의 문장이 return 문을 경우 괄호{}를 생략할 수 없다.
 	
 	- 함수형 인터페이스
 		: 자바에서 모든 메서드는 클래스 내에 포함되어야 한다.
 		: 람다식은 익명 클래스의 객체와 동등하다.
 		
 		Object obj = new Object() {										
 						int max(int a, int b) {				=>			(a, b) -> a > b ? a : b
 							return a > b ? a : b;
 						}
 					}
 		* 객체의 메서드를 다루려면 해당 타입의 참조변수가 있어한다. 익명 클래스의 객체를 어떻게 다룰까?
 			- Object obj = (a, b) -> a > b ? a : b;
 			- int value = obj.max(1, 2);	// Object 타입의 참조변수로는 익명객체의 max() 라는 메서드를 다룰 수 없다.
 		* 참조 변수의 타입으로는 클래스 또는 인터페이스를 사용할 수 있다. 그리고 람다식과 동등한 메서드가 정의되어 있는 것이어야 한다.
 		  그래야만, 참조변수로 익명 객체(람다식)의 메서드를 호출할 수 있기 때문이다.
 		
 		interface MyFunction {
 			int max(int a, int b);
 		}
 		MyFunction f = new Object() {										
 					   	  int max(int a, int b) {				=>			(a, b) -> a > b ? a : b
 							  return a > b ? a : b;
 						  }
 					   }
 			- MyFunction f = (a, b) -> a > b ? a : b;
 			- int value = f.max(1, 2);		// MyFunction 타입의 참조변수로 익명객체의 max() 메서드를 다룰 수 있게된다.
 		* MyFunction인터페이스에 정의된 메서드 max()는 람다식 (a, b) -> a > b ? a : b 과 메서드의 선언부가 일치한다. 그래서 익명 객체를 람다식으로 대체할 수 있다.
 		* 이처럼 MyFunction인터페이스를 구현한 익명 객체를 람다식으로 대체가 가능한 이유는 람다식도 실제로는 익명 객체이고, MyFunction인터페이스를 구현한 익명 객체의 메서드 max()와
 		  람다식의 매개변수 타입과 개수 그리고 반환값이 일치하기 때문이다.
 		* 하나의 메서드가 선언되 인터페이스를 정의해서 람다식을 다루는 것은 기존의 자바의 규칙들을 어기지 않으면서도 자연스럽다.
 		* 람다식을 다루기 위한 인터페이스를 '함수형 인터페이스'라고 한다.
 			- 함수형 인터페이스에는 오직 하나의 추상 메서드만 정의되어 있어야 한다. 그래야 람다식과 인터페이스의 메서드가 1:1로 연결될 수 있기 때문이다.
 */
@FunctionalInterface
interface MyFunction {
	void run();
}
@FunctionalInterface
interface Plus {
	int plus(int a, int b);
}
@FunctionalInterface
interface Mul {
	int mul(int a);
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
		
		Mul m = x -> x * x;
		System.out.println(m.mul(2));
		
		Plus p = (a, b) -> a + b;
		System.out.println(p.plus(2, 3));
		
		System.out.println((Plus)(a, b) -> a + b);
//		num(1, (a,b)->a+b);
		int[] arr = new int[10];
		Arrays.setAll(arr, (a) -> a+a);
		System.out.println(Arrays.toString(arr));
		
		Arrays.setAll(arr, (i) -> (int)(Math.random()*10)+1);
		System.out.println(Arrays.toString(arr));
		
		MyFunction f1 = () -> System.out.println("f1.run()");	// 람다식을 MyFunction타입의 참조변수로 참조한다.
		
		MyFunction f2 = new MyFunction() {						// 익명 객체를 MyFunction타입의 참조변수로 참조한다.
			public void run() {									// 인터페이스의 구현한 클래스의 메서드는 그 접근 제어자의 범위가 인터페이스에 선언된 메서드의 것 보다 좁으면 안 된다.
				System.out.println("f2.run()");
			}
		};
		
		MyFunction f3 = getMyFunction();						// 람다식을 참조한 참조변수를 참조변수 f3에 저장한다.
		
		f1.run();
		f2.run();
		f3.run();
		
		execute(f1);											// 람다식을 참조한 f1을 매개변수로 넘겨준다.
		execute(() -> System.out.println("후후"));				// 람다식을 매개변수로 넘겨준다.
		
		// * 위 처럼 람다식을 이용하여 메서드를 변수처럼 주고받는 것이 가능해 진다.
		// * 사실상 메서드가 아니라 객체를 주고받는 것이다.
		
		
		// < 람다식 활용 예 >
		
		List<String> list = Arrays.asList("abc", "aaa", "bbb", "ddd", "aaa");
		
		Collections.sort(list, new Comparator<String>() {		// 익명 객체를 매개변수로 넘겨준다.
			public int compare(String s1, String s2) {
				return s2.compareTo(s1);
			}
		});
		
		System.out.println(list);
		
		List<String> list2 = Arrays.asList("abc", "aaa", "bbb", "ddd", "aaa");
		
		Collections.sort(list2, (s1, s2) -> s2.compareTo(s1));	// 람다식을 매개변수로 넘겨준다.
	}

}









