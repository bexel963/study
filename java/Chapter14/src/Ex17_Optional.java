import java.util.Optional;
import java.util.OptionalInt;

public class Ex17_Optional {

	public static void main(String[] args) {

		Optional<String> optStr = Optional.of("abcd");
		Optional<Integer> optInt = optStr.map(String::length);
		System.out.println("optStr = " + optStr.get());
		System.out.println("optInt = " + optInt.get());
		
		int result1 = Optional.of("123").filter(x->x.length()>0).map(Integer::parseInt).get();
		int result2 = Optional.of("").filter(x->x.length()>0).map(Integer::parseInt).orElse(-1);
		System.out.println("result1 = " + result1);
		System.out.println("result2 = " + result2);
		
		Optional.of("456").map(Integer::parseInt).ifPresent(x->System.out.printf("result3 = %d\n", x));
		
		// isPresent()는 Optional객체의 값이 null이면 false를, 아니면 true를 반환한다.
		// isPresent(Consumer<T> block)은 값이 있으면 주어진 람다식을 실행하고, 없으면 아무 일도 하지 않는다.
		OptionalInt optInt1 = OptionalInt.of(0);		// 0을 저장
		OptionalInt optInt2 = OptionalInt.empty();		// 빈 객체를 생성
		System.out.println(optInt1.isPresent());
		System.out.println(optInt2.isPresent());
		
		System.out.println(optInt1.getAsInt());	// 0
//		System.out.println(optInt2.getAsInt());	// NosuchElementException
		System.out.println("optInt1 = " + optInt1);
		System.out.println("optInt2 = " + optInt2);
		System.out.println("optInt1.equals(optInt2) ? " + optInt1.equals(optInt2));
		
		Optional<String> opt  = Optional.ofNullable(null);	// null 저장
		Optional<String> opt2 = Optional.empty();			// 빈 객체 생성
		System.out.println("opt = " + opt);
		System.out.println("opt2 = " + opt2);
		System.out.println("opt.equals(opt2) ? " + opt2.equals(opt2));
		
		int result3 = optStrToInt(Optional.of("123"), 0);
		int result4 = optStrToInt(Optional.of(""), 0);
		
		System.out.println("result3 = " + result3);
		System.out.println("result4 = " + result4);
	}
	
	static int optStrToInt(Optional<String> optStr, int defaultValue) {
		try {
			return optStr.map(Integer::parseInt).get();
		} catch (Exception e) {
			return defaultValue;
		}
	}

}
