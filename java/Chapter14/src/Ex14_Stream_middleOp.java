import java.util.Comparator;
import java.util.IntSummaryStatistics;
import java.util.stream.IntStream;
import java.util.stream.Stream;

// - 스트림의 중간연산4 (변환 - 기본형으로)

/*
	: map()은 연산의 결과로 Stream<T>타입의 스트림을 반환하는데, 스트림의 요소를 숫자로 변환하는 경우 IntStream과 같은 기본형 스트림으로 변환하는 것이 더 좋다.
			ex)
				IntStream studentScoreStream = studentStream.mapToInt(Student::getTotalScore);
				int allTotalScore = studentScoreStream.sum();
	  count()만 지원하는 Stream<T>와 달리 IntStream과 같은 기본형 스트림은 숫자를 다루는데 편리한 메서드들이 제공된다.
		  	int sum()
		  	OptionalDouble average()
		  	OptionalInt max()
		  	OptionalInt min()
	  이 메서드들은 최종연산이기 때문에 호출후에 스트림이 닫힌다.
	  sum(), average()를 모두 호출해야할 때, 스트림을 또 생성해야하므로 불편하다. 그래서 summaryStatistics()라는 메서드가 따로 제공된다.
	  
	
 	- IntStream mapToInt(ToIntFunction<? super T> mapper)
 	- LongStream mapToLong(ToLongFunction<? super T> mapper)
 	- DoubleStream mpaToDouble(ToDoubleFunction<? super T> mapper)
*/
public class Ex14_Stream_middleOp {

	public static void main(String[] args) {

		Student[] studentArr = {
				new Student("이자바", 3, 300),
				new Student("김자바", 1, 200),
				new Student("안자바", 2, 100),
				new Student("박자바", 2, 150),
				new Student("소자바", 1, 200),
				new Student("나자바", 3, 290),
				new Student("감자바", 3, 180)
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










