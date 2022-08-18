import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.stream.DoubleStream;
import java.util.stream.IntStream;
import java.util.stream.LongStream;
import java.util.stream.Stream;

// - 스트림 만들기

public class Ex10_Stream {

	public static void main(String[] args) {

		// 컬렉션의 최고 조상인 Collection에 stream()이 정의되어 있다.
		// Stream<T> Collection.stream()
		List<Integer> list = Arrays.asList(1,2,3,4,5);
		Stream<Integer> intStream = list.stream();
		
		
		// 배열을 소스로 하는 스트림을 생성하는 메서드는 Stream과 Arrays의 static메서드로 정의되어 있다.
		Stream<String> strStream = Stream.of("a", "b", "c");							// Stream.of(T...values)
		Stream<String> strStream2 = Stream.of(new String[] {"a", "b", "c"});			// Stream.of(T[])
		Stream<String> strStream3 = Arrays.stream(new String[] {"a", "b", "c"});		// Arrays.stream(T[])
		Stream<String> strStream4 = Arrays.stream(new String[] {"a", "b", "c"}, 0 , 3);	// Arrays.stream(T[], int startInclusive, int endExclusive)
		// 기본형 스트림 : IntStream, LongStream, DoubleStream
		IntStream intStream1 = IntStream.of(1, 2, 3 ,4, 5);				// IntStream IntStream.of(int... values)
		IntStream intStream2 = IntStream.of(new int[] {1,2,3});			// IntStream IntStream.of(int[])
		IntStream intStream3 = Arrays.stream(new int[] {1,2,3});		// IntStream Arrays.stream(int[])
		IntStream intStream4 = Arrays.stream(new int[] {1,2,3}, 0, 3);	// IntStream Arrays.stream(int[] array, int startInclusive, int endExclusive)
		
		// IntStream과 LongStream은 지정된 범위의 연속된 정수를 스트림으로 생성해서 반환하는 range(), rangeClosed() 메소드를 가지고있다.
		IntStream intStream5 = IntStream.range(1, 5);					// IntStream.range(int begin, int end)
		IntStream intStream6 = IntStream.rangeClosed(1, 5);				// IntStream.rangeClosed(int begin, int end) - end가 범위에 포함.
		
		// 난수를 생성하는데 사용하는 Random클래스에는 해당 타입의 난수들로 이루어진 스트림을 반환하는 인스턴스의 메서드들이 있다.
		// IntStream ints(), LongStream longs(), DoubleStream doubles()
		// Integer.MIN_VALUE <= ints() <= Integer.MAX_VALUE
		//    Long.MIN_VALUE <= longs() <= Long.MAX_VALUE
		//               0.0 <= doubles() <= 1.0
		// 이 메서드들이 반환하는 스트림은 크기가 정해지지 않은 무한 스트림 이므로 limit()도 같이 사용해서 스트림의 크기를 제한해 주어야한다.
		IntStream intStream7 = new Random().ints();		// 무한 스트림
		intStream.limit(5).forEach(System.out::print);	// 무한 스트림에서 5개를 잘라서 5개의 요소만 출력한다.
		
		// 매개변수로 스트림의 크기를 지정해서 유한 스트림을 생성해서 반환하는 메서드들도 있다.
		// IntStream ints(long streamSize), LongStream longs(long streamSize), DoubleStream doubles(long streamSize)
		IntStream intStream8 = new Random().ints(5);		// 크기가 5인 난수 스트림 반환.
		
		// 지정된 범위(begin~end)의 난수를 발생시키는 스트림을 얻는 메소드도 있다.
		IntStream instStream9 = new Random().ints(10, 20);
		LongStream longStream = new Random().longs(10, 20);
		DoubleStream doubleStream = new Random().doubles(10, 20);
		// 크기 지정 + 범위 지정
		IntStream instStream10 = new Random().ints(5, 10, 20);
		LongStream longStream1 = new Random().longs(5, 10, 20);
		DoubleStream doubleStream1 = new Random().doubles(5, 10, 20);
		
		// Stream클래스의 iterate(), generate()는 람다식을 매개변수로 받아서, 이 람다식에 의해 계산되는 값들을 요소로 하는 무한 스트림을 생성한다.
		// static<T> Stream<T> iterate(T seed, UnaryOperator<T> f)		- 이전 결과를 이용해서 다음 요소를 계산
		// static<T> Stream<T> generate(Supplier<T> s)					- 이전 결과를 이용해서 다음 요소를 계산하지 않음.
		Stream<Integer> evenStream = Stream.iterate(0, n->n+2);
		Stream<Double> randomStream = Stream.generate(Math::random);
		Stream<Integer> outStream = Stream.generate(()->1);
		// * iterate(), generate()에 의해 생성된 스트림은 기본형 스트림 타입의 참조변수로 다룰 수 없다.
		//   굳이 필요하다면, mapToInt()와 같은 메서드로 변환 해야한다.
		IntStream evenStream1 = Stream.iterate(0, n->n+2).mapToInt(Integer::valueOf);
		// * 반대로 IntStream타입의 스트림을 Stream<Integer>타입으로 변환 하려면, boxed()를 사용하면 된다.
		Stream<Integer> stream = evenStream1.boxed();
		
		// empty() - 요소가 하나도 없는 비어있는 스트림 생성
		Stream emptyStream = Stream.empty();
		long count = emptyStream.count();
		System.out.println("\n" + count);
		
		// concat() - 두 스트림의 연결 : 연결하려는 두 스트림의 요소는 같은 타입이어야 한다.
		String[] str1 = {"123", "456", "789"};
		String[] str2 = {"ABC", "abc", "DEF"};
		
		Stream<String> strs1 = Stream.of(str1);
		Stream<String> strs2 = Stream.of(str2);
		Stream<String> strs3 = Stream.concat(strs1, strs2);
	}

}
