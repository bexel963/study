import java.util.Comparator;
import java.util.stream.IntStream;
import java.util.stream.Stream;

// - ��Ʈ���� �߰�����2 (����)

/*
 	: sorted()�� ������ Comparator�� ��Ʈ���� �����ϴµ�, Comparator��� int���� ��ȯ�ϴ� ���ٽ��� ����ϴ� �͵� �����ϴ�.
 	  Comparator�� �������� ������ ��Ʈ�� ����� �⺻���� ����(Comparable)���� �����Ѵ�.
 	  ��, ��Ʈ���� ��Ұ� Comparable�� ������ Ŭ������ �ƴϸ� ���ܰ� �߻��Ѵ�.
 	  
 		- Stream<T> sorted()								
 		- Stream<T> sorted(Comparator<T> comparator)
 	
 	: ���ڿ� ��Ʈ�� ���� ���
 	
	 	- strStream.sorted()							// �⺻����		-> CCaaabccdd
	 	- strStream.sorted(Comparator.naturalOrder())	// �⺻����
	 	- strStream.sorted((s1,s2)->s1.compareTo(s2))	// ���ٽĵ� ����
	 	- strStream.sorted(String::compareTo)			// ���� ����
	 	
	 	- strStream.sorted(Comparator.reverseOrder())	// �⺻������ ����	-> ddccbaaaCC
	 	- strStream.sorted(Comparator.<String>naturalOrder().reversed())
	 	
	 	- strStream.sorted(String.CASE_INSENSITIVE_ORDER)				// ��ҹ��� ���� ����	-> aaabCCccdd
	 	- strStream.sorted(String.CASE_INSENSITIVE_ORDER.reversed())						-> ddCCccbaaa
	 	
	 	- strStream.sorted(Comparator.comparing(String::length)			// ���� �� ����		-> bddCCccaaa
	 	- strStream.sorted(Comparator.comparingInt(String::length)		// ����ڽ�x
	 	- strStream.sorted(Comparator.comparing(String::length).reversed())					-> aaaddCCccb
 	
 	: Comparator�������̽��� static�޼���� ����Ʈ �޼��尡 ���� �߰��Ǿ��µ�, �� �޼������ �̿��ϸ� ������ ��������.
 	  �� �޼������ ��� Comparator<T>�� ��ȯ�Ѵ�.
 	
	 	- Comparator�� default�޼���
	 	
	 		// �������� �߰�.
	 		thenComparing(Comparator<T> other)		
	 		thenComparing(Function<T, U> keyExtractor)
	 		thenComparing(Function<T, U> keyExtractor, Comparator<U> keyComp)
	 		thenComparingInt(ToIntFunction<T> keyExtractor)
	 		
	 		reversed()
	 		
	 	- Comparator�� static�޼���
	 	
	 		// ��Ʈ���� ��Ұ� Comparable�� ������ ���, �Ű����� �ϳ�¥���� ����ϸ� �ǰ� �׷��� ���� ���,
	 		   �߰����� �Ű������� ���ı���(comparator)�� ���� ������ ����Ѵ�.
	 		comparing(Function<T, U> keyExtractor)
	 		comparing(Function<T, U> keyExtractor, Comparator<U> keyComparator)
	 		
	 		// �񱳴���� �⺻���� ���, �� �޼��带 ����ϸ� ����ڽ̰� ��ڽ� ������ ��� �� ȿ�����̴�.
	 		comparingInt(ToIntFunction<T> keyExtractor)
	 		comparingLong(ToIntFunction<T> keyExtractor)
	 		comparingDouble(ToIntFunction<T> keyExtractor)
	 		
	 		naturalOrder()
	 		reverseOrder()
	 	
	 	ex) �л� ��Ʈ���� �ݺ�, ������, �̸��� ���� �����Ͽ� ���
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
					new Student("���ڹ�", 3, 300),
					new Student("���ڹ�", 1, 200),
					new Student("���ڹ�", 2, 100),
					new Student("���ڹ�", 2, 150),
					new Student("���ڹ�", 1, 200),
					new Student("���ڹ�", 3, 290),
					new Student("���ڹ�", 3, 180)
				);
		studentStream.sorted(Comparator.comparing(Student::getBan)
				.thenComparing(Comparator.naturalOrder()))
				.forEach(System.out::println);
		
		studentStream = Stream.of(
				new Student("���ڹ�", 3, 300),
				new Student("���ڹ�", 1, 200),
				new Student("���ڹ�", 2, 100),
				new Student("���ڹ�", 2, 150),
				new Student("���ڹ�", 1, 200),
				new Student("���ڹ�", 3, 290),
				new Student("���ڹ�", 3, 180)
			);
		
		IntStream studentScoreStream = studentStream.mapToInt(Student::getTotalScore);
		int allTotalScore = studentScoreStream.sum();
		System.out.println("allTotalScore = " + allTotalScore);
	}

}









