import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 	- java.util.function 패키지 : 일반적으로 자주 쓰이는 형식의 메서드를 함수형 인터페이스로 미리 정의해 놓았다.
 	
 		- 매개변수가 한 개인 함수형 인터페이스
 		
 			public interface Supplier<T> {
 				T get();
 			}
 			public interface Consumer<T> {
 				void accept(T t);
 			}
 			public interface Function<T, R> {
 				R apply(T t);
 			}
 			public interface Predicate<T> {
 				boolean test(T t);
 			}
 			
 			ex)
 			Predicate<String> isEmptyStr = s -> s.length() == 0;
 			String str = "";
 			if(isEmptyStr.test(str)){
 				System.out.println("This is an empty String.");
 			}
 		
 		- 매개변수가 두 개인 함수형 인터페이스
 		
 			public interface BiConsumer<T, U> {
 				void accept(T t, U u);
 			}
 			public interface BiPredicate<T, U> {
 				boolean test(T t, U u);
 			}
 			public interface BiFunction<T, U, R> {
 				R apply(T t, U u);
 			}
 		
 			* 두 개 이상의 매개변수를 갖는 함수형 인터페이스가 필요하다면 직접 만들어서 써야한다.
 		
 		- UnaryOperator, BinaryOperator : 매개변수의 타입과 반환타입의 타입이 모두 일치.
 		
 			public interface UnaryOperator<T> {
 				T apply(T t);
 			}
 			public interface BinaryOperator<T> {
 				T apply(T t, T t);
 			}
 			
 		- 컬렉션 프레임워크와 함수형 인터페이스
 		
 			interface Collection {
 				default boolean removeIf(Predicate<E> filter){				// 조건에 맞는 요소를 삭제
 					......
 				}
 			}
 			interface List {
 				default void replaceAll(UnaryOperator<E> operator){			// 모든 요소를 변환하여 대체
 					....
 				}
 			}
 			interface Iterable {
 				default void forEach(Consumer<T> action) {					// 모든 요소에 작업 action을 수행
 					....
 				}
 			}
 			interface Map {
 				default V compute(K key, BiFunction<K,V,V> f){				// 지정된 키의 값에 작업 f를 수행
 					....
 				}
 				default V computeIfAbsent(K key, Function<K,V> f){			// 키가 없으면, 작업 f 수행 후 추가
 					....
 				}
 				default V computeIfPresent(K key, BiFunction<V,V,V> f){		// 지정된 키가 있을 때, 작업 f 수행
 					....
 				}
 				default V merge(K key, V value, BiFunction<V,V,V> f){		// 모든 요소에 병합작업 f를 수행
 					....
 				}
 				default void forEach(BiConsumer<K,V> action){				// 모든 요소에 작업 action을 수행
 					....
 				}
 				default void replaceAll(BiFunction<K,V,V> f){				// 모든 요소에 치환작업 f를 수행
 					....
 				}
 				
 			}
*/
public class Ex04_Lamda {

	public static void main(String[] args) {

		List<Integer> list = new ArrayList<>();
		for(int i=0 ; i<10 ; i++) {
			list.add(i);
		}
		/*
		  	@FunctionalInterface
			public interface Consumer<T> {
			
    			void accept(T t);
			}
		*/
		/*
		 	@Override
		    public void forEach(Consumer<? super E> action) {
		    
		        Objects.requireNonNull(action);
		        final int expectedModCount = modCount;
		        final Object[] es = elementData;
		        final int size = this.size;
		        for (int i = 0; modCount == expectedModCount && i < size; i++)
		            action.accept(elementAt(es, i));
		        if (modCount != expectedModCount)
		            throw new ConcurrentModificationException();
		    } 
		*/
		list.forEach(i -> System.out.print(i + ", "));
		System.out.println();
		
		list.removeIf(x -> x%2==0 || x%3==0);
		System.out.println(list);
		
		list.replaceAll(i -> i*10);
		System.out.println(list);
		
		Map<String, String> map = new HashMap();
		map.put("1", "1");
		map.put("2", "2");
		map.put("3", "3");
		map.put("4", "4");
		
		map.forEach((k,v) -> System.out.print("{" + k + ", " + v + "}, "));
	}

}













