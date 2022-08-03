import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Ex20_HashSet {

	public static void main(String[] args) {

		Object[] objArr = { "1", new Integer(1), "2", "2", "3", "3", "4", "4", "4" };
		Set set = new HashSet();
		
		for(int i=0 ; i<objArr.length ; i++) {
			set.add(objArr[i]);
		}
		
		Iterator it = set.iterator();
		while(it.hasNext()) {
			System.out.print(it.next());
		}
		System.out.println();
		System.out.println(set);
		
		Set set2 = new HashSet();
		
		set2.add(8);
		set2.add(1);
		set2.add(2);
		set2.add(3);
		
		System.out.println(set2.toString());
	}

}
