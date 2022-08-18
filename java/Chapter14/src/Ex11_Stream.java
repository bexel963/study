// - 스트림의 중간 연산

/*
 	- Stream<T> distinct()								- 중복 제거 	
 	- Stream<T> filter(Predicate<T> predicate)			- 조건에 안 맞는 요소 제외 	
 	- Stream<T> limit(long maxSize)						- 스트림의 일부를 자른다.	
 	- Stream<T> skip(long n)							- 스트림의 일부를 건너뛴다.	
 	- Stream<T> peek(Consumer<T> action)				- 스트림의 요소에 작업 수행
 	- Stream<T> sorted()								- 스트림의 요소를 정렬
 	- Stream<T> sorted(Comparator<T> comparator)
 	
 	<스트림의 요소를 변환>
 	- Stream<R> map(Function<T,R> mapper)
 	- DoubleStream mpaToDouble(ToDoubleFunction<T> mapper)
 	- IntStream mpaToInt(ToIntFunction<T> mapper)
 	- LongStream mpaToLong(ToLongFunction<T> mapper)
 	
 	- Stream<R> flatMap(Function<T, Stream<R>> mapper)
 	- DoubleStream flatMapToDouble(Function<T, DoubleStream> m)
 	- IntStream flatMapToInt(Function<T, IntStream> m)
 	- LongStream flatMapToLong(Function<T, LongStream> m)
*/
public class Ex11_Stream {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
