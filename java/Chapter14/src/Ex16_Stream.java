// - ��Ʈ���� ��������
/*
 	- void forEach(Consumer<? super T> action)			- �� ��ҿ� ������ �۾� ����
 	- void forEachOrdered(Consumer<? super T> action)
 	
 	- long count()		- ��Ʈ���� ����� ���� ��ȯ
 	
 	- Optional<T> max(Comparator<? super T> comparator)	- ��Ʈ���� �ִ밪/�ּҰ��� ��ȯ
 	- Optional<T> min(Comparator<? super T> comparator)
 	
 	- Optional<T> findAny()			- ��Ʈ���� ��� �� �ƹ��ų� �ϳ� ��ȯ
 	- Optional<T> findFirst()		- ��Ʈ���� ��� �� ù ��° ��� ��ȯ
 	
 	- boolean allMatch(Predicate<T> p)		- �־��� ������ ��� ��Ұ� �����ϴ��� Ȯ��
 	- boolean anyMatch(Predicate<T> p)		- �־��� ������ �ϳ��� ��Ҷ� �����ϴ��� Ȯ��
 	- boolean noneMatch(Predicate<T> p)		- �־��� ������ ��� ��Ұ� �������� �ʴ��� Ȯ��
 	
 	- Object[] toArray()						- ��Ʈ���� ��� ��Ҹ� �迭�� ��ȯ
 	- A[] toArray(IntFunction<A[]> generator)	
 	
 	<��Ʈ���� ��Ҹ� �ϳ��� �ٿ����鼭 ���>
 	- Optional<T> reduce(BinaryOperator<T> accumulator)		
 	- T reduce(T identity, BinaryOperator<T> accumulator)
 	- U reduce(U identity, BiFunction<U,T,U> accumulator, BinaryOperator<U> combiner)
 	
 	<��Ʈ���� ��Ҹ� �����Ѵ�. �ַ� ��Ҹ� �׷�ȭ�ϰų� ������ ����� �÷��ǿ� ��� ��ȯ�ϴµ� ���ȴ�.>
 	- R collect(Collector<T,A,R> collector)					
 	- R collect(Supplier<R> supplier, BiConsumer<R,T> accumulator, BiConsumer<R,R> combiner)
*/

public class Ex16_Stream {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
