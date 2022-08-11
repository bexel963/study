import java.util.Arrays;
import java.util.Comparator;

public class EX19_Comparator {

	public static void main(String[] args) {

		String[] strArr = {"cat", "Dog", "lion", "tiger"};
		
		Arrays.sort(strArr);	// ��ü �迭�� ����� ��ü�� �⺻������ �����Ǿ��ִ� Comparable(�����ǿ���)�� compareTo(�޼���)�� ���� ����
		System.out.println("strArr = " + Arrays.toString(strArr));
		
		Arrays.sort(strArr, String.CASE_INSENSITIVE_ORDER);	// ��� ���·� �����Ǵ� Comparator�� ���� ����
		System.out.println("strArr = " + Arrays.toString(strArr));
		
		Arrays.sort(strArr, new Descending());	// ������ Comparator(�������̽�)�� compare(�޼���)�� ���� ����
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