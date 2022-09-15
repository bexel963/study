import java.util.Optional;
import java.util.OptionalInt;
import java.util.stream.IntStream;
import java.util.stream.Stream;

// - 스트림의 최종연산2
/*
	< reduce() >
	
	- Optional<T> reduce(BinaryOperator<T> accumulator)		
 	- T reduce(T identity, BinaryOperator<T> accumulator)
 	- U reduce(U identity, BiFunction<U,T,U> accumulator, BinaryOperator<U> combiner)
 	
	: 스트림의 요소를 하나씩 줄여가면서 계산
	: 처음 두 요소를 가지고 연산한 결과를 가지고 그 다은 요소와 연산한다. 이 과정에서 스트림의 요소를 하나씩 소모하게 되며, 
	  스트림의 모든 요소를 소모하게 되면 그 결과를 반환한다. identity는 초기값 이다.
	: count()와 sum()같은 최종연산 메서드들은 내부적으로 모두 reduce()를 이용해서 작성된 것이다.
	
	ex)
	int count = intStream.reduce(0, (a,b) -> a + 1);						// count()
	int sum   = intStream.reduce(0, (a,b) -> a + b);							// sum()
	int max   = intStream.reduce(Integer.MIN_VALUE, (a,b) -> a>b ? a:b);		// max()
	int min   = intStream.reduce(Integer.MAX_VALUE, (a,b) -> a>b ? a:b);		// max()
	
	: max(), min()의 경우, 초기값이 필요없으므로 Optional<T>를 반환하는 매개변수 하나짜리 reduce()를 사용하는 것이 낫다.
	  단, intSream의 타입이 IntStream인 경우 OptionalInt를 사용해야 한다. Stream<T>와 달리 IntStream에 정의된 reduce()의 반환 타입이 OptionalInt이기 때문이다.
	
	ex)
	OptionalInt max   = intStream.reduce((a,b) -> a>b ? a:b);		// max()
	OptionalInt min   = intStream.reduce((a,b) -> a>b ? a:b);		// max()
	OptionalInt max   = intStream.reduce(Integer::max);		// max()
	OptionalInt min   = intStream.reduce(Integer::min);		// max()
	int maxValue = max.getAsInt();	// OptionalInt에 저장된 값 꺼내기.
	
	: reduce()가 내부적으로 동작하는 방식
	
		int a = identity;
		
		for(int b : strea){
			a = a + b;
		}
	
 	
 	<스트림의 요소를 수집한다. 주로 요소를 그룹화하거나 분할한 결과를 컬렉션에 담아 반환하는데 사용된다.>
 	- R collect(Collector<T,A,R> collector)					
 	- R collect(Supplier<R> supplier, BiConsumer<R,T> accumulator, BiConsumer<R,R> combiner)
	
 	
*/
public class Ex19_Stream_finalOp {

	public static void main(String[] args) {

		String[] strArr = {
				"Inheritance", "Java", "Lamda", "stream", "OptionalDouble", "IntStream", "count", "sum"
		};
		
		Stream.of(strArr).forEach(System.out::println);
		
		boolean noEmptyStr = Stream.of(strArr).noneMatch(s -> s.length()==0);
		Optional<String> sWord = Stream.of(strArr).filter(s->s.charAt(0)=='s').findFirst();
		System.out.println("noEmptyStr = " + noEmptyStr);
		System.out.println("sWord = " + sWord.get());
		
		// Stream<String[]>을 IntStream으로 변환
		IntStream intStream1 = Stream.of(strArr).mapToInt(String::length);
		IntStream intStream2 = Stream.of(strArr).mapToInt(String::length);
		IntStream intStream3 = Stream.of(strArr).mapToInt(String::length);
		IntStream intStream4 = Stream.of(strArr).mapToInt(String::length);
		System.out.println();
		
		int count = intStream1.reduce(0, (a,b)->a+1);
		int sum = intStream2.reduce(0, (a,b)->a+b);
		
		OptionalInt max = intStream3.reduce(Integer::max);
		OptionalInt min = intStream4.reduce(Integer::min);
		
		System.out.println("count = " + count);
		System.out.println("sum = " + sum);
		System.out.println("max = " + max.getAsInt());
		System.out.println("min = " + min.getAsInt());
	}

}




















