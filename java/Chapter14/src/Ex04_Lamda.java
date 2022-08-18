import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 	- java.util.function ��Ű�� : �Ϲ������� ���� ���̴� ������ �޼��带 �Լ��� �������̽��� �̸� ������ ���Ҵ�.
 	
 		- �Ű������� �� ���� �Լ��� �������̽�
 		
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
 		
 		- �Ű������� �� ���� �Լ��� �������̽�
 		
 			public interface BiConsumer<T, U> {
 				void accept(T t, U u);
 			}
 			public interface BiPredicate<T, U> {
 				boolean test(T t, U u);
 			}
 			public interface BiFunction<T, U, R> {
 				R apply(T t, U u);
 			}
 		
 			* �� �� �̻��� �Ű������� ���� �Լ��� �������̽��� �ʿ��ϴٸ� ���� ���� ����Ѵ�.
 		
 		- UnaryOperator, BinaryOperator : �Ű������� Ÿ�԰� ��ȯŸ���� Ÿ���� ��� ��ġ.
 		
 			public interface UnaryOperator<T> {
 				T apply(T t);
 			}
 			public interface BinaryOperator<T> {
 				T apply(T t, T t);
 			}
 			
 		- �÷��� �����ӿ�ũ�� �Լ��� �������̽�
 		
 			interface Collection {
 				default boolean removeIf(Predicate<E> filter){				// ���ǿ� �´� ��Ҹ� ����
 					......
 				}
 			}
 			interface List {
 				default void replaceAll(UnaryOperator<E> operator){			// ��� ��Ҹ� ��ȯ�Ͽ� ��ü
 					....
 				}
 			}
 			interface Iterable {
 				default void forEach(Consumer<T> action) {					// ��� ��ҿ� �۾� action�� ����
 					....
 				}
 			}
 			interface Map {
 				default V compute(K key, BiFunction<K,V,V> f){				// ������ Ű�� ���� �۾� f�� ����
 					....
 				}
 				default V computeIfAbsent(K key, Function<K,V> f){			// Ű�� ������, �۾� f ���� �� �߰�
 					....
 				}
 				default V computeIfPresent(K key, BiFunction<V,V,V> f){		// ������ Ű�� ���� ��, �۾� f ����
 					....
 				}
 				default V merge(K key, V value, BiFunction<V,V,V> f){		// ��� ��ҿ� �����۾� f�� ����
 					....
 				}
 				default void forEach(BiConsumer<K,V> action){				// ��� ��ҿ� �۾� action�� ����
 					....
 				}
 				default void replaceAll(BiFunction<K,V,V> f){				// ��� ��ҿ� ġȯ�۾� f�� ����
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













