import java.util.ArrayList;
import java.util.Collection;
import java.util.Enumeration;
import java.util.Iterator;

public class Ex12_Iterator {

	public static void main(String[] args) {

		Collection list = new ArrayList();
		
		for(int i=0 ; i<10 ; i++) {
			list.add((int)(Math.random()*9)+1);
		}
		
		Iterator it = list.iterator();
		
		while(it.hasNext()) {
			System.out.println(it.next());
		}
		
	}

}
