import java.util.Optional;
import java.util.OptionalInt;
import java.util.stream.IntStream;
import java.util.stream.Stream;

// - ��Ʈ���� ��������2
/*
	< reduce() >
	
	- Optional<T> reduce(BinaryOperator<T> accumulator)		
 	- T reduce(T identity, BinaryOperator<T> accumulator)
 	- U reduce(U identity, BiFunction<U,T,U> accumulator, BinaryOperator<U> combiner)
 	
	: ��Ʈ���� ��Ҹ� �ϳ��� �ٿ����鼭 ���
	: ó�� �� ��Ҹ� ������ ������ ����� ������ �� ���� ��ҿ� �����Ѵ�. �� �������� ��Ʈ���� ��Ҹ� �ϳ��� �Ҹ��ϰ� �Ǹ�, 
	  ��Ʈ���� ��� ��Ҹ� �Ҹ��ϰ� �Ǹ� �� ����� ��ȯ�Ѵ�. identity�� �ʱⰪ �̴�.
	: count()�� sum()���� �������� �޼������ ���������� ��� reduce()�� �̿��ؼ� �ۼ��� ���̴�.
	
	ex)
	int count = intStream.reduce(0, (a,b) -> a + 1);						// count()
	int sum   = intStream.reduce(0, (a,b) -> a + b);							// sum()
	int max   = intStream.reduce(Integer.MIN_VALUE, (a,b) -> a>b ? a:b);		// max()
	int min   = intStream.reduce(Integer.MAX_VALUE, (a,b) -> a>b ? a:b);		// max()
	
	: max(), min()�� ���, �ʱⰪ�� �ʿ�����Ƿ� Optional<T>�� ��ȯ�ϴ� �Ű����� �ϳ�¥�� reduce()�� ����ϴ� ���� ����.
	  ��, intSream�� Ÿ���� IntStream�� ��� OptionalInt�� ����ؾ� �Ѵ�. Stream<T>�� �޸� IntStream�� ���ǵ� reduce()�� ��ȯ Ÿ���� OptionalInt�̱� �����̴�.
	
	ex)
	OptionalInt max   = intStream.reduce((a,b) -> a>b ? a:b);		// max()
	OptionalInt min   = intStream.reduce((a,b) -> a>b ? a:b);		// max()
	OptionalInt max   = intStream.reduce(Integer::max);		// max()
	OptionalInt min   = intStream.reduce(Integer::min);		// max()
	int maxValue = max.getAsInt();	// OptionalInt�� ����� �� ������.
	
	: reduce()�� ���������� �����ϴ� ���
	
		int a = identity;
		
		for(int b : strea){
			a = a + b;
		}
	
 	
 	<��Ʈ���� ��Ҹ� �����Ѵ�. �ַ� ��Ҹ� �׷�ȭ�ϰų� ������ ����� �÷��ǿ� ��� ��ȯ�ϴµ� ���ȴ�.>
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
		
		// Stream<String[]>�� IntStream���� ��ȯ
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




















