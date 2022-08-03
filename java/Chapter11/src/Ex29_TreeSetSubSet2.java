import java.util.Arrays;
import java.util.TreeSet;

public class Ex29_TreeSetSubSet2 {

	public static void main(String[] args) {

		TreeSet set = new TreeSet();
		int[] score = {80, 95, 50, 35, 45, 65, 10, 100};
		
		for(int i=0 ; i<score.length ; i++) {
			set.add(new Integer(score[i]));
		}
		System.out.println("50보다 작은 값 : " + set.headSet(new Integer(50)));
		System.out.println("50보다 큰 값 : " + set.tailSet(new Integer(50)));
		
		System.out.println("=======================복습=======================");
		int[] copy1 = new int[score.length];
		System.arraycopy(score, 0, copy1, 0, score.length);	// copy1의 배열의 크기가 특정되어야 하고, 원본 배열보다 크면 안됨
		
		int[] copy2 = null;
		copy2 = Arrays.copyOf(score, 10);			// score의 배열의 10 번째 까지 복사 - copy2의 크기는 자동으로 늘려줌.
		
		int[] copy3 = null;
		copy3 = Arrays.copyOfRange(score, 0, 12);	// score의 배열의 0~12 번째 까지 복사 - copy3의 크기는 자동으로 늘려줌.
		
		System.out.println(Arrays.toString(copy1));
		System.out.println(Arrays.toString(copy2));
		System.out.println(Arrays.toString(copy3));
	}

}
