import java.util.Comparator;
import java.util.IntSummaryStatistics;
import java.util.stream.IntStream;
import java.util.stream.Stream;

// - ��Ʈ���� �߰�����4 (��ȯ - �⺻������)

/*
	: map()�� ������ ����� Stream<T>Ÿ���� ��Ʈ���� ��ȯ�ϴµ�, ��Ʈ���� ��Ҹ� ���ڷ� ��ȯ�ϴ� ��� IntStream�� ���� �⺻�� ��Ʈ������ ��ȯ�ϴ� ���� �� ����.
			ex)
				IntStream studentScoreStream = studentStream.mapToInt(Student::getTotalScore);
				int allTotalScore = studentScoreStream.sum();
	  count()�� �����ϴ� Stream<T>�� �޸� IntStream�� ���� �⺻�� ��Ʈ���� ���ڸ� �ٷ�µ� ���� �޼������ �����ȴ�.
		  	int sum()
		  	OptionalDouble average()
		  	OptionalInt max()
		  	OptionalInt min()
	  �� �޼������ ���������̱� ������ ȣ���Ŀ� ��Ʈ���� ������.
	  sum(), average()�� ��� ȣ���ؾ��� ��, ��Ʈ���� �� �����ؾ��ϹǷ� �����ϴ�. �׷��� summaryStatistics()��� �޼��尡 ���� �����ȴ�.
	  
	
 	- IntStream mapToInt(ToIntFunction<? super T> mapper)
 	- LongStream mapToLong(ToLongFunction<? super T> mapper)
 	- DoubleStream mpaToDouble(ToDoubleFunction<? super T> mapper)
*/
public class Ex14_Stream_middleOp {

	public static void main(String[] args) {

		Student[] studentArr = {
				new Student("���ڹ�", 3, 300),
				new Student("���ڹ�", 1, 200),
				new Student("���ڹ�", 2, 100),
				new Student("���ڹ�", 2, 150),
				new Student("���ڹ�", 1, 200),
				new Student("���ڹ�", 3, 290),
				new Student("���ڹ�", 3, 180)
		};
		
		Stream<Student> studentStream = Stream.of(studentArr);
		
		studentStream.sorted(Comparator.comparing(Student::getBan).thenComparing(Comparator.naturalOrder()))
							.forEach(System.out::println);
		
		studentStream = Stream.of(studentArr);
		
		IntStream studentScoreStream = studentStream.mapToInt(Student::getTotalScore);
		
		IntSummaryStatistics stat = studentScoreStream.summaryStatistics();
		
		System.out.println("count = " + stat.getCount());
		System.out.println("sum = " + stat.getSum());
		System.out.printf("average = %.2f\n", stat.getAverage());
		System.out.println("min = " + stat.getMin());
		System.out.println("max = " + stat.getMax());
	}

}










