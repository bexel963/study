// - 스트림의 최종연산
/*
 	- void forEach(Consumer<? super T> action)			- 각 요소에 지정된 작업 수행
 	- void forEachOrdered(Consumer<? super T> action)
 	
 	- long count()		- 스트림의 요소의 개수 반환
 	
 	- Optional<T> max(Comparator<? super T> comparator)	- 스트림의 최대값/최소값을 반환
 	- Optional<T> min(Comparator<? super T> comparator)
 	
 	- Optional<T> findAny()			- 스트림의 요소 중 아무거나 하나 반환
 	- Optional<T> findFirst()		- 스트림의 요소 중 첫 번째 요소 반환
 	
 	- boolean allMatch(Predicate<T> p)		- 주어진 조건을 모든 요소가 만족하는지 확인
 	- boolean anyMatch(Predicate<T> p)		- 주어진 조건을 하나의 요소라도 만족하는지 확인
 	- boolean noneMatch(Predicate<T> p)		- 주어진 조건을 모든 요소가 만족하지 않는지 확인
 	
 	- Object[] toArray()						- 스트림의 모든 요소를 배열로 반환
 	- A[] toArray(IntFunction<A[]> generator)	
 	
 	<스트림의 요소를 하나씩 줄여가면서 계산>
 	- Optional<T> reduce(BinaryOperator<T> accumulator)		
 	- T reduce(T identity, BinaryOperator<T> accumulator)
 	- U reduce(U identity, BiFunction<U,T,U> accumulator, BinaryOperator<U> combiner)
 	
 	<스트림의 요소를 수집한다. 주로 요소를 그룹화하거나 분할한 결과를 컬렉션에 담아 반환하는데 사용된다.>
 	- R collect(Collector<T,A,R> collector)					
 	- R collect(Supplier<R> supplier, BiConsumer<R,T> accumulator, BiConsumer<R,R> combiner)
*/

public class Ex16_Stream {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
