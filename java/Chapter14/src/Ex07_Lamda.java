import java.util.function.Function;
import java.util.function.Predicate;

/*
 	- Function의 합성과 Predicate의 결합.
 	
 		default <V> Function<T, V> andThen(Function<? super R, ? extends V> after)
 		default <V> Function<T, V> compose(Function<? super R, ? extends V> before)
 		static <T> Function<T, T> identity()
 		
 		default Predicate<T> 	and(Predicate<? super T> other)
 		default Predicate<T> 	or(Predicate<? super T> other)
 		default Predicate<T> 	negate()
 		static <T> Predicate<T> isEqual(Object targetRef)
*/
public class Ex07_Lamda {

	public static void main(String[] args) {

		Function<String, Integer> f = (s) -> Integer.parseInt(s, 16);		// 문자열을 16진수의 정수형으로 변환.
		Function<Integer, String> g = (i) -> Integer.toBinaryString(i);
		
		Function<String, String> h	  = f.andThen(g);
		Function<Integer, Integer> h2 = f.compose(g);
		
		System.out.println(h.apply("FF"));
		System.out.println(h2.apply(2));
		
		Function<String, String> f2 = x -> x;	// 항등함수
		System.out.println(f2.apply("AAA"));
		
		Predicate<Integer> p = i -> i < 100;
		Predicate<Integer> q = i -> i < 200;
		Predicate<Integer> r = i -> i%2 == 0;
		Predicate<Integer> notP = p.negate();	// i >= 100
		
		Predicate<Integer> all = notP.and(q.or(r));
		System.out.println(all.test(150));
		
		String str1 = "abc";
		String str2 = "abc";
		
		Predicate<String> p2 = Predicate.isEqual(str1);
		boolean result = p2.test(str2);
		System.out.println(result);
		
//		11111111
//		16
//		AAA
//		true
//		true
	}

}
