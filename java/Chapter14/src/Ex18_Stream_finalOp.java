import java.util.stream.IntStream;

// - 스트림의 최종연산1
/*
 	: 최종 연산은 스트림의 요소를 소모해서 결과를 만들어낸다. 그래서 최종 연산후에는 스트림이 닫히게 되고 더 이상 사용할 수 없다.
 	  최종 연산의 결과는 스트림 요소의 합과 같은 단일 값이거나, 스트림의 요소가 담긴 배열 또는 컬렉션일 수 있다.
 	
 	1. 출력 : forEach(), forEachOrdered()
 	2. 조건 검사 : allMatch(), anyMatch(), noneMatch(), findFirst(), findAny()
 	3. 통계 : count(), sum(), average(), max(), min()
 	
 	- void forEach(Consumer<? super T> action)			- 각 요소에 지정된 작업 수행
 	- void forEachOrdered(Consumer<? super T> action)
 	
 	- Optional<T> findFirst()	- 스트림의 요소 중에서 조건에 일치하는 첫 번째 것을 반환. 주로 filter()와 함께 사용. 순차 스트림에 사용. 결과가 null일 수 있으니 Optional사용.
 	- Optional<T> findAny()		- 스트림의 요소 중에서 조건에 일치하는 아무거나를 반환. 병렬 스트림에 사용. 결과가 null일 수 있으니 Optional사용.
 	  ex) 
 	  	Optional<Student> stu = stuStream.filter(s -> s.getTotalScore()<=100).findFirst();
 	  	Optional<Student> stu = parallelStream.filter(s -> s.getTotalScore()<=100).findAny();
 	
 	- boolean allMatch(Predicate<? super T> predicate)		- 주어진 조건을 모든 요소가 만족하는지 확인
 	- boolean anyMatch(Predicate<? super T> predicate)		- 주어진 조건을 하나의 요소라도 만족하는지 확인
 	- boolean noneMatch(Predicate<? super T> predicate)		- 주어진 조건을 모든 요소가 만족하지 않는지 확인
 	  ex) 
 	  	boolean hasFiledStu = stuStream.anyMatch(s -> s.getTotalScore()<=100);	// 낙제자가 있는지?
 	  
 	- long count()		- 스트림의 요소의 개수 반환
 	- Optional<T> max(Comparator<? super T> comparator)	- 스트림의 최대값/최소값을 반환
 	- Optional<T> min(Comparator<? super T> comparator)
 	
 	- Object[] toArray()						- 스트림의 모든 요소를 배열로 반환
 	- A[] toArray(IntFunction<A[]> generator)	

*/

public class Ex18_Stream_finalOp {

	public static void main(String[] args) {

		// sequential()은 직렬스트림 - 모든 스트림은 기본적으로 직렬 스트림이므로 생략 가능하다.
		IntStream.range(1,  10).sequential().forEach(System.out::print);	
		System.out.println();
		IntStream.range(1,  10).sequential().forEachOrdered(System.out::print);	// 순서 유지
		System.out.println();
		// parallel()은 병렬 스트림 - 내부적으로 fork&join프레임웍을 이용해서 자동적으로 연산을 병렬로 수행한다.
		// 이 때, 순서를 유지하려면 forEachOrdered()를 사용한다.
		IntStream.range(1,  10).parallel().forEach(System.out::print);
		System.out.println();
		IntStream.range(1,  10).parallel().forEachOrdered(System.out::print);
		System.out.println();
		
		System.out.println("===================================");
		
	}

}
