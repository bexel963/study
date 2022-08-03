import java.util.Arrays;
import java.util.Comparator;

public class EX19_Comparator {

	public static void main(String[] args) {

		String[] strArr = {"cat", "Dog", "lion", "tiger"};
		
		Arrays.sort(strArr);	// 객체 배열에 저장된 객체에 기본적으로 구현되어있는 Comparable(인터피에스)의 compareTo(메서드)에 의한 정렬
		System.out.println("strArr = " + Arrays.toString(strArr));
		
		Arrays.sort(strArr, String.CASE_INSENSITIVE_ORDER);	// 상수 형태로 제공되는 Comparator에 의한 정렬
		System.out.println("strArr = " + Arrays.toString(strArr));
		
		Arrays.sort(strArr, new Descending());	// 지정한 Comparator(인터페이스)의 compare(메서드)에 의한 정렬
		System.out.println("strArr = " + Arrays.toString(strArr));
	}

}

class Descending implements Comparator {
	public int compare(Object o1, Object o2) {
		if( o1 instanceof Comparable && o2 instanceof Comparable) {
			Comparable c1 = (Comparable)o1;
			Comparable c2 = (Comparable)o2;
			return c1.compareTo(o2) * -1;
		}
		return -1;
	}
}
