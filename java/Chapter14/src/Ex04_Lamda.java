import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Ex04_Lamda {

	public static void main(String[] args) {

		ArrayList<Integer> list = new ArrayList<>();
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













