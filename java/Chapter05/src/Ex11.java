import java.util.Arrays;

// 빈도수 구하기
public class Ex11 {

	public static void main(String[] args) {

		int[] numArr = new int[10];
		int[] count = new int[10];
		int index = 0;
		
		for(int i=0 ; i<numArr.length ; i++) {
			numArr[i] = (int)(Math.random()*10);
		}
		System.out.println(Arrays.toString(numArr));
		for(int i=0 ; i<numArr.length ; i++) {
			index = numArr[i];
			++count[index];
		}
		
		System.out.println(Arrays.toString(count));
		System.out.println();
		
		for(int i=0 ; i<count.length ; i++) {
			System.out.println(i + "의 개수 : " + count[i]);
		}
		
	}

}
