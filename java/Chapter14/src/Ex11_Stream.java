// - ��Ʈ���� �߰� ����

/*
 	- Stream<T> distinct()								- �ߺ� ���� 	
 	- Stream<T> filter(Predicate<T> predicate)			- ���ǿ� �� �´� ��� ���� 	
 	- Stream<T> limit(long maxSize)						- ��Ʈ���� �Ϻθ� �ڸ���.	
 	- Stream<T> skip(long n)							- ��Ʈ���� �Ϻθ� �ǳʶڴ�.	
 	- Stream<T> peek(Consumer<T> action)				- ��Ʈ���� ��ҿ� �۾� ����
 	- Stream<T> sorted()								- ��Ʈ���� ��Ҹ� ����
 	- Stream<T> sorted(Comparator<T> comparator)
 	
 	<��Ʈ���� ��Ҹ� ��ȯ>
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
