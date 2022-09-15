import java.util.stream.IntStream;

// - ��Ʈ���� ��������1
/*
 	: ���� ������ ��Ʈ���� ��Ҹ� �Ҹ��ؼ� ����� ������. �׷��� ���� �����Ŀ��� ��Ʈ���� ������ �ǰ� �� �̻� ����� �� ����.
 	  ���� ������ ����� ��Ʈ�� ����� �հ� ���� ���� ���̰ų�, ��Ʈ���� ��Ұ� ��� �迭 �Ǵ� �÷����� �� �ִ�.
 	
 	1. ��� : forEach(), forEachOrdered()
 	2. ���� �˻� : allMatch(), anyMatch(), noneMatch(), findFirst(), findAny()
 	3. ��� : count(), sum(), average(), max(), min()
 	
 	- void forEach(Consumer<? super T> action)			- �� ��ҿ� ������ �۾� ����
 	- void forEachOrdered(Consumer<? super T> action)
 	
 	- Optional<T> findFirst()	- ��Ʈ���� ��� �߿��� ���ǿ� ��ġ�ϴ� ù ��° ���� ��ȯ. �ַ� filter()�� �Բ� ���. ���� ��Ʈ���� ���. ����� null�� �� ������ Optional���.
 	- Optional<T> findAny()		- ��Ʈ���� ��� �߿��� ���ǿ� ��ġ�ϴ� �ƹ��ų��� ��ȯ. ���� ��Ʈ���� ���. ����� null�� �� ������ Optional���.
 	  ex) 
 	  	Optional<Student> stu = stuStream.filter(s -> s.getTotalScore()<=100).findFirst();
 	  	Optional<Student> stu = parallelStream.filter(s -> s.getTotalScore()<=100).findAny();
 	
 	- boolean allMatch(Predicate<? super T> predicate)		- �־��� ������ ��� ��Ұ� �����ϴ��� Ȯ��
 	- boolean anyMatch(Predicate<? super T> predicate)		- �־��� ������ �ϳ��� ��Ҷ� �����ϴ��� Ȯ��
 	- boolean noneMatch(Predicate<? super T> predicate)		- �־��� ������ ��� ��Ұ� �������� �ʴ��� Ȯ��
 	  ex) 
 	  	boolean hasFiledStu = stuStream.anyMatch(s -> s.getTotalScore()<=100);	// �����ڰ� �ִ���?
 	  
 	- long count()		- ��Ʈ���� ����� ���� ��ȯ
 	- Optional<T> max(Comparator<? super T> comparator)	- ��Ʈ���� �ִ밪/�ּҰ��� ��ȯ
 	- Optional<T> min(Comparator<? super T> comparator)
 	
 	- Object[] toArray()						- ��Ʈ���� ��� ��Ҹ� �迭�� ��ȯ
 	- A[] toArray(IntFunction<A[]> generator)	

*/

public class Ex18_Stream_finalOp {

	public static void main(String[] args) {

		// sequential()�� ���Ľ�Ʈ�� - ��� ��Ʈ���� �⺻������ ���� ��Ʈ���̹Ƿ� ���� �����ϴ�.
		IntStream.range(1,  10).sequential().forEach(System.out::print);	
		System.out.println();
		IntStream.range(1,  10).sequential().forEachOrdered(System.out::print);	// ���� ����
		System.out.println();
		// parallel()�� ���� ��Ʈ�� - ���������� fork&join�����ӿ��� �̿��ؼ� �ڵ������� ������ ���ķ� �����Ѵ�.
		// �� ��, ������ �����Ϸ��� forEachOrdered()�� ����Ѵ�.
		IntStream.range(1,  10).parallel().forEach(System.out::print);
		System.out.println();
		IntStream.range(1,  10).parallel().forEachOrdered(System.out::print);
		System.out.println();
		
		System.out.println("===================================");
		
	}

}
