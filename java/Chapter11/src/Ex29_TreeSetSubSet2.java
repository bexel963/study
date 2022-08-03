import java.util.Arrays;
import java.util.TreeSet;

public class Ex29_TreeSetSubSet2 {

	public static void main(String[] args) {

		TreeSet set = new TreeSet();
		int[] score = {80, 95, 50, 35, 45, 65, 10, 100};
		
		for(int i=0 ; i<score.length ; i++) {
			set.add(new Integer(score[i]));
		}
		System.out.println("50���� ���� �� : " + set.headSet(new Integer(50)));
		System.out.println("50���� ū �� : " + set.tailSet(new Integer(50)));
		
		System.out.println("=======================����=======================");
		int[] copy1 = new int[score.length];
		System.arraycopy(score, 0, copy1, 0, score.length);	// copy1�� �迭�� ũ�Ⱑ Ư���Ǿ�� �ϰ�, ���� �迭���� ũ�� �ȵ�
		
		int[] copy2 = null;
		copy2 = Arrays.copyOf(score, 10);			// score�� �迭�� 10 ��° ���� ���� - copy2�� ũ��� �ڵ����� �÷���.
		
		int[] copy3 = null;
		copy3 = Arrays.copyOfRange(score, 0, 12);	// score�� �迭�� 0~12 ��° ���� ���� - copy3�� ũ��� �ڵ����� �÷���.
		
		System.out.println(Arrays.toString(copy1));
		System.out.println(Arrays.toString(copy2));
		System.out.println(Arrays.toString(copy3));
	}

}
