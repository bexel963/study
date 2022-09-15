import java.util.Comparator;
import java.util.stream.IntStream;
import java.util.stream.Stream;

// - 스트림의 중간연산2 (정렬)

/*
 	: sorted()는 지정된 Comparator로 스트림을 정렬하는데, Comparator대신 int값을 반환하는 람다식을 사용하는 것도 가능하다.
 	  Comparator를 지정하지 않으면 스트림 요소의 기본정렬 기준(Comparable)으로 정렬한다.
 	  단, 스트림의 요소가 Comparable을 구현한 클래스가 아니면 예외가 발생한다.
 	  
 		- Stream<T> sorted()								
 		- Stream<T> sorted(Comparator<T> comparator)
 	
 	: 문자열 스트림 정렬 방법
 	
	 	- strStream.sorted()							// 기본정렬		-> CCaaabccdd
	 	- strStream.sorted(Comparator.naturalOrder())	// 기본정렬
	 	- strStream.sorted((s1,s2)->s1.compareTo(s2))	// 람다식도 가능
	 	- strStream.sorted(String::compareTo)			// 위와 동일
	 	
	 	- strStream.sorted(Comparator.reverseOrder())	// 기본정렬의 역순	-> ddccbaaaCC
	 	- strStream.sorted(Comparator.<String>naturalOrder().reversed())
	 	
	 	- strStream.sorted(String.CASE_INSENSITIVE_ORDER)				// 대소문자 구분 안함	-> aaabCCccdd
	 	- strStream.sorted(String.CASE_INSENSITIVE_ORDER.reversed())						-> ddCCccbaaa
	 	
	 	- strStream.sorted(Comparator.comparing(String::length)			// 길이 순 정렬		-> bddCCccaaa
	 	- strStream.sorted(Comparator.comparingInt(String::length)		// 오토박싱x
	 	- strStream.sorted(Comparator.comparing(String::length).reversed())					-> aaaddCCccb
 	
 	: Comparator인터페이스에 static메서드와 디폴트 메서드가 많이 추가되었는데, 이 메서드들을 이용하면 정렬이 쉬워진다.
 	  이 메서드들은 모두 Comparator<T>를 반환한다.
 	
	 	- Comparator의 default메서드
	 	
	 		// 정렬조건 추가.
	 		thenComparing(Comparator<T> other)		
	 		thenComparing(Function<T, U> keyExtractor)
	 		thenComparing(Function<T, U> keyExtractor, Comparator<U> keyComp)
	 		thenComparingInt(ToIntFunction<T> keyExtractor)
	 		
	 		reversed()
	 		
	 	- Comparator의 static메서드
	 	
	 		// 스트림의 요소가 Comparable을 구현한 경우, 매개변수 하나짜리를 사용하면 되고 그렇지 않은 경우,
	 		   추가적인 매개변수로 정렬기준(comparator)을 따로 지정해 줘야한다.
	 		comparing(Function<T, U> keyExtractor)
	 		comparing(Function<T, U> keyExtractor, Comparator<U> keyComparator)
	 		
	 		// 비교대상이 기본형인 경우, 이 메서드를 사용하면 오토박싱과 언박싱 과정이 없어서 더 효율적이다.
	 		comparingInt(ToIntFunction<T> keyExtractor)
	 		comparingLong(ToIntFunction<T> keyExtractor)
	 		comparingDouble(ToIntFunction<T> keyExtractor)
	 		
	 		naturalOrder()
	 		reverseOrder()
	 	
	 	ex) 학생 스트림을 반별, 성적순, 이름순 으로 정렬하여 출력
	 		studentStream.sorted(Comparator.comparing(Student::getBan)
	 									.thenComparing(Student::getTotalScore)
	 									.thenComparing(Student::getName)
	 									.forEach(System.out::println)

*/
class Student implements Comparable<Student> {
	
	private String name;
	private int ban;
	private int totalScore;
	
	Student(String name, int ban, int totalScore) {
		this.name = name;
		this.ban = ban;
		this.totalScore = totalScore;
	}
	public String toString() {
		return String.format("[%s, %d, %d]", name, ban, totalScore);
	}
	public String getName() {
		return name;
	}
	public int getBan() {
		return ban;
	}
	public int getTotalScore() {
		return totalScore;
	}
	
	public int compareTo(Student s) {
		return s.totalScore - this.totalScore;
	}
}
public class Ex12_Stream_middleOp {

	public static void main(String[] args) {

		Stream<Student> studentStream = Stream.of(
					new Student("이자바", 3, 300),
					new Student("김자바", 1, 200),
					new Student("안자바", 2, 100),
					new Student("박자바", 2, 150),
					new Student("소자바", 1, 200),
					new Student("나자바", 3, 290),
					new Student("감자바", 3, 180)
				);
		studentStream.sorted(Comparator.comparing(Student::getBan)
				.thenComparing(Comparator.naturalOrder()))
				.forEach(System.out::println);
		
		studentStream = Stream.of(
				new Student("이자바", 3, 300),
				new Student("김자바", 1, 200),
				new Student("안자바", 2, 100),
				new Student("박자바", 2, 150),
				new Student("소자바", 1, 200),
				new Student("나자바", 3, 290),
				new Student("감자바", 3, 180)
			);
		
		IntStream studentScoreStream = studentStream.mapToInt(Student::getTotalScore);
		int allTotalScore = studentScoreStream.sum();
		System.out.println("allTotalScore = " + allTotalScore);
	}

}









