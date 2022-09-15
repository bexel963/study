import java.util.stream.IntStream;

// - 스트림의 중간 연산1 (자르기, 걸러내기)

/*
 	- Stream<T> distinct()								- 중복 제거 	
 	- Stream<T> filter(Predicate<T> predicate)			- 조건에 안 맞는 요소 제외 	
 	- Stream<T> limit(long maxSize)						- 스트림의 일부를 자른다.	
 	- Stream<T> skip(long n)							- 스트림의 일부를 건너뛴다.	
 	- Stream<T> peek(Consumer<T> action)				- 스트림의 요소에 작업 수행

*/
public class Ex11_Stream_middleOp {

	public static void main(String[] args) {

		IntStream intStream = IntStream.rangeClosed(1, 10);
		intStream.skip(3).limit(5).forEach(System.out::print);
		System.out.println();
		
		IntStream intStream2 = IntStream.of(1, 2, 2, 3, 3, 3, 4, 5, 5, 6);
		intStream2.distinct().forEach((i)->System.out.print(i));
		System.out.println();
		
		IntStream intStream3 = IntStream.rangeClosed(1, 10);
		intStream3.filter(i -> i%2==0).forEach(System.out::print);
		System.out.println();
		
		IntStream intStream4 = IntStream.rangeClosed(1, 10);
		intStream4.filter(i -> i%2 != 0 && i%3 != 0).forEach(System.out::print);
		System.out.println();
		IntStream intStream5 = IntStream.rangeClosed(1, 10);
		intStream5.filter(i -> i%2 != 0).filter(i -> i%3 != 0).forEach(System.out::print);
	}

}
