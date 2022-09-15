import java.util.Arrays;
import java.util.stream.Stream;

// - 스트림의 중간연산5 (변환 - flatMap)

/*
 	: 스트림의 요소가 배열이거나 map()의 연산결과가 배열인 경우, 즉 스트림의 타입이 Stream<T[]>인 경우, Stream<T>로 다루는 것이 편리할 때가 있다.
 	  이 때, map()을 사용하면 배열이 하나의 스트림으로 반환되는게 아닌 스트림의 스트림이 된다.
 	  이럴 때, 사용하는것이 flatMap()이다. 
 	
 	- Stream<R> flatMap(Function<T, Stream<R>> mapper)
 	- DoubleStream flatMapToDouble(Function<T, DoubleStream> m)
 	- IntStream flatMapToInt(Function<T, IntStream> m)
 	- LongStream flatMapToLong(Function<T, LongStream> m)
*/
public class Ex15_Stream_middleOp {

	public static void main(String[] args) {

		Stream<String[]> strArrStrm = Stream.of(
				new String[] {"abc", "def", "jkl"},
				new String[] {"ABC", "GHI", "JKL"}
		);
//		Stream<Stream<String>> strStrmStrm = strArrStrm.map(Arrays::stream);
		Stream<String> strStrm = strArrStrm.flatMap(Arrays::stream);
		
		strStrm.map(String::toLowerCase).distinct().sorted().forEach(System.out::println);
		System.out.println();
		
		String[] lineArr = {
				"Believe or not It is true",
				"Do or do not There is no try"
		};
		
		Stream<String> lineStream = Arrays.stream(lineArr);
		lineStream.flatMap(line -> Stream.of(line.split(" +"))).map(String::toLowerCase).distinct().sorted().forEach(System.out::println);
		System.out.println();
		
		Stream<String> strStrm1 = Stream.of("AAA", "ABC", "bBb", "Dd");
		Stream<String> strStrm2 = Stream.of("bbb", "aaa", "ccc", "dd");
		
		Stream<Stream<String>> strStrmStrm = Stream.of(strStrm1, strStrm2);
		Stream<String> strStream = strStrmStrm.map(s->s.toArray(String[]::new)).flatMap(Arrays::stream);
		strStream.map(String::toLowerCase).distinct().forEach(System.out::println);
	}

}












