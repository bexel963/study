import java.util.HashSet;
import java.util.Iterator;

public class Ex25_HashSetAggregation {

	public static void main(String[] args) {

		HashSet setA = new HashSet();
		HashSet setB = new HashSet();
		HashSet setHab = new HashSet();
		HashSet setKyo = new HashSet();
		HashSet setCha = new HashSet();
		
		for(int i=1 ; i<=5 ; i++) {
			setA.add(i+"");
		}
		for(int i=4 ; i<=8 ; i++) {
			setB.add(i+"");
		}
		System.out.println("A = " + setA);
		System.out.println("B = " + setB);
		
		Iterator it = setB.iterator();
		while(it.hasNext()) {
			Object tmp = it.next();
			if(setA.contains(tmp))
				setKyo.add(tmp);
		}
		it = setA.iterator();
		while(it.hasNext()) {
			Object tmp = it.next();
			if(!setB.contains(tmp))
				setCha.add(tmp);
		}
		it = setA.iterator();
		while(it.hasNext()) {
			setHab.add(it.next());
		}
		it = setB.iterator();
		while(it.hasNext()) {
			setHab.add(it.next());
		}
		
		System.out.println("A ¡û B = " + setKyo);
		System.out.println("A ¡ú B = " + setHab);
		System.out.println("A - B = " + setCha);
	}

}
