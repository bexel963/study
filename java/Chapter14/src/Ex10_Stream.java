import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.stream.DoubleStream;
import java.util.stream.IntStream;
import java.util.stream.LongStream;
import java.util.stream.Stream;

// - ��Ʈ�� �����

public class Ex10_Stream {

	public static void main(String[] args) {

		// �÷����� �ְ� ������ Collection�� stream()�� ���ǵǾ� �ִ�.
		// Stream<T> Collection.stream()
		List<Integer> list = Arrays.asList(1,2,3,4,5);
		Stream<Integer> intStream = list.stream();
		
		
		// �迭�� �ҽ��� �ϴ� ��Ʈ���� �����ϴ� �޼���� Stream�� Arrays�� static�޼���� ���ǵǾ� �ִ�.
		Stream<String> strStream = Stream.of("a", "b", "c");							// Stream.of(T...values)
		Stream<String> strStream2 = Stream.of(new String[] {"a", "b", "c"});			// Stream.of(T[])
		Stream<String> strStream3 = Arrays.stream(new String[] {"a", "b", "c"});		// Arrays.stream(T[])
		Stream<String> strStream4 = Arrays.stream(new String[] {"a", "b", "c"}, 0 , 3);	// Arrays.stream(T[], int startInclusive, int endExclusive)
		// �⺻�� ��Ʈ�� : IntStream, LongStream, DoubleStream
		IntStream intStream1 = IntStream.of(1, 2, 3 ,4, 5);				// IntStream IntStream.of(int... values)
		IntStream intStream2 = IntStream.of(new int[] {1,2,3});			// IntStream IntStream.of(int[])
		IntStream intStream3 = Arrays.stream(new int[] {1,2,3});		// IntStream Arrays.stream(int[])
		IntStream intStream4 = Arrays.stream(new int[] {1,2,3}, 0, 3);	// IntStream Arrays.stream(int[] array, int startInclusive, int endExclusive)
		
		// IntStream�� LongStream�� ������ ������ ���ӵ� ������ ��Ʈ������ �����ؼ� ��ȯ�ϴ� range(), rangeClosed() �޼ҵ带 �������ִ�.
		IntStream intStream5 = IntStream.range(1, 5);					// IntStream.range(int begin, int end)
		IntStream intStream6 = IntStream.rangeClosed(1, 5);				// IntStream.rangeClosed(int begin, int end) - end�� ������ ����.
		
		// ������ �����ϴµ� ����ϴ� RandomŬ�������� �ش� Ÿ���� ������� �̷���� ��Ʈ���� ��ȯ�ϴ� �ν��Ͻ��� �޼������ �ִ�.
		// IntStream ints(), LongStream longs(), DoubleStream doubles()
		// Integer.MIN_VALUE <= ints() <= Integer.MAX_VALUE
		//    Long.MIN_VALUE <= longs() <= Long.MAX_VALUE
		//               0.0 <= doubles() <= 1.0
		// �� �޼������ ��ȯ�ϴ� ��Ʈ���� ũ�Ⱑ �������� ���� ���� ��Ʈ�� �̹Ƿ� limit()�� ���� ����ؼ� ��Ʈ���� ũ�⸦ ������ �־���Ѵ�.
		IntStream intStream7 = new Random().ints();		// ���� ��Ʈ��
		intStream.limit(5).forEach(System.out::print);	// ���� ��Ʈ������ 5���� �߶� 5���� ��Ҹ� ����Ѵ�.
		
		// �Ű������� ��Ʈ���� ũ�⸦ �����ؼ� ���� ��Ʈ���� �����ؼ� ��ȯ�ϴ� �޼���鵵 �ִ�.
		// IntStream ints(long streamSize), LongStream longs(long streamSize), DoubleStream doubles(long streamSize)
		IntStream intStream8 = new Random().ints(5);		// ũ�Ⱑ 5�� ���� ��Ʈ�� ��ȯ.
		
		// ������ ����(begin~end)�� ������ �߻���Ű�� ��Ʈ���� ��� �޼ҵ嵵 �ִ�.
		IntStream instStream9 = new Random().ints(10, 20);
		LongStream longStream = new Random().longs(10, 20);
		DoubleStream doubleStream = new Random().doubles(10, 20);
		// ũ�� ���� + ���� ����
		IntStream instStream10 = new Random().ints(5, 10, 20);
		LongStream longStream1 = new Random().longs(5, 10, 20);
		DoubleStream doubleStream1 = new Random().doubles(5, 10, 20);
		
		// StreamŬ������ iterate(), generate()�� ���ٽ��� �Ű������� �޾Ƽ�, �� ���ٽĿ� ���� ���Ǵ� ������ ��ҷ� �ϴ� ���� ��Ʈ���� �����Ѵ�.
		// static<T> Stream<T> iterate(T seed, UnaryOperator<T> f)		- ���� ����� �̿��ؼ� ���� ��Ҹ� ���
		// static<T> Stream<T> generate(Supplier<T> s)					- ���� ����� �̿��ؼ� ���� ��Ҹ� ������� ����.
		Stream<Integer> evenStream = Stream.iterate(0, n->n+2);
		Stream<Double> randomStream = Stream.generate(Math::random);
		Stream<Integer> outStream = Stream.generate(()->1);
		// * iterate(), generate()�� ���� ������ ��Ʈ���� �⺻�� ��Ʈ�� Ÿ���� ���������� �ٷ� �� ����.
		//   ���� �ʿ��ϴٸ�, mapToInt()�� ���� �޼���� ��ȯ �ؾ��Ѵ�.
		IntStream evenStream1 = Stream.iterate(0, n->n+2).mapToInt(Integer::valueOf);
		// * �ݴ�� IntStreamŸ���� ��Ʈ���� Stream<Integer>Ÿ������ ��ȯ �Ϸ���, boxed()�� ����ϸ� �ȴ�.
		Stream<Integer> stream = evenStream1.boxed();
		
		// empty() - ��Ұ� �ϳ��� ���� ����ִ� ��Ʈ�� ����
		Stream emptyStream = Stream.empty();
		long count = emptyStream.count();
		System.out.println("\n" + count);
		
		// concat() - �� ��Ʈ���� ���� : �����Ϸ��� �� ��Ʈ���� ��Ҵ� ���� Ÿ���̾�� �Ѵ�.
		String[] str1 = {"123", "456", "789"};
		String[] str2 = {"ABC", "abc", "DEF"};
		
		Stream<String> strs1 = Stream.of(str1);
		Stream<String> strs2 = Stream.of(str2);
		Stream<String> strs3 = Stream.concat(strs1, strs2);
	}

}
