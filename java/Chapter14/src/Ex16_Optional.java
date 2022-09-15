/*
 	: Optional<T>은 지네릭 클래스로 T타입의 객체를 감싸는 래퍼 클래스이다. 그래서 Optional타입의 객체에는 모든 타입의 참조변수를 담을 수 있다.
	 		public final class Optional<T> {
	 			private final T value;
	 			.....
	 		}
 	  최종 연산의 결과를 그냥 반환하는게 아니라 Optional객체에 담아서 반환하는 것이다.
 	  이처럼 객체에 담아서 반환을 하면, 반환도니 결과가 null인지 매번 if문으로 체크하는 대신 Optional에 정의된 메서드를 통해서 간단히 처리할 수 있다.
 	  
 	  Optional객체 생성하기
 	  	- of()		   : 매개변수의 값이 null이면 NullPointerException발생.
 	  	- ofNullable() : 참조변수의 값이 null일 가능성이 있으면 이걸 사용한다.
 	  
 	  Optional<T>타입의 참조변수를 기본값으로 초기화
 	  	- empty()
 	  
 	  Optional객체의 값 가져오기
 	  	- get()				: 값이 null일 때는 NoSuchElementException 발생
 	  	- orElse()			: 예외 발생 대비해서 이걸 사용.
 	  	- orElseGet()		: null을 대체할 값을 반환하는 람다식을 지정할 수 있음.
 	  	- orElseThrow()		: null일 때 지정된 예외를 발생시킬 수 있음
 	  
 	  기본형을 값으로하는 Optional
 	  	- OptionalInt			: int getAsInt()
 	  	- OptionalLong			: long getAsLong()
 	  	- OptionalDouble		: double getAsDouble()
 	

*/

import java.util.Optional;

public class Ex16_Optional {

	public static void main(String[] args) {

//		int[] arr = null;
		int[] arr = new int[0];			// 이런식으로 초기화 하여 NullPointerException을 최대한 줄이자.
		System.out.println("arr.length = " + arr.length);
		
		System.out.println("=================================");
		
//		Optional<String> opt = null;	// OK. 하지만 바람직하지 않음.
		Optional<String> opt = Optional.empty();
		System.out.println("opt = " + opt);
		
		System.out.println("=================================");
		
//		System.out.println("opt = " + opt.get());	// 빈 문자열에서 get()하면 NoSuchElementException 발생
		String str = "";
		try {
			str = opt.get();
		} catch(Exception e) {
			str = "";	// 그래서 요런식으로 예외가 발생하면 초기화 하는 코드를 작상해야함.
		}
		System.out.println("str = " + str);
		
		// 위 코드는 orElse() 메서드 하나로 대체할 수 있다.
		String str2 = opt.orElse("");	// Optional에 저장된 값이 null이면 ""반환. 아니면 객체에 들어있는 값 반환.
		System.out.println("str2 = " + str2);
		
		System.out.println("=================================");
		
		Optional<String> opt2 = Optional.of("abc");
		String str3 = opt2.orElse("EMPTY");				// Optional에 저장된 값이 null이면 EMPTY 반환. 아니면 객체에 들어있는 값 반환.
		System.out.println("str3 = " + str3);
		
		System.out.println("=================================");
		
		String str4 = opt2.orElseGet(() -> "EMPTY");	// orElse()에서 람다식 받는 기능 추가
		str4 = opt2.orElseGet(() -> new String());		// 이런 식으로도 사용.
		str4 = opt2.orElseGet(String::new);				// 이런 식으로도 사용
		System.out.println("str3 = " + str3);
		
	}

}
