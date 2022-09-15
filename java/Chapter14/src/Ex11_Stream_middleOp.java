import java.util.stream.IntStream;

// - ��Ʈ���� �߰� ����1 (�ڸ���, �ɷ�����)

/*
 	- Stream<T> distinct()								- �ߺ� ���� 	
 	- Stream<T> filter(Predicate<T> predicate)			- ���ǿ� �� �´� ��� ���� 	
 	- Stream<T> limit(long maxSize)						- ��Ʈ���� �Ϻθ� �ڸ���.	
 	- Stream<T> skip(long n)							- ��Ʈ���� �Ϻθ� �ǳʶڴ�.	
 	- Stream<T> peek(Consumer<T> action)				- ��Ʈ���� ��ҿ� �۾� ����

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
