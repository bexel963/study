import java.util.Arrays;

// ¼¯±â
public class Ex07 {

	public static void main(String[] args) {

		int[] numArr = new int[10];
		int index = 0, tmp = 0;
		
		for(int i=0 ; i<numArr.length ; i++)
			numArr[i] = i;
		System.out.println(Arrays.toString(numArr));
		
		for(int i=0 ; i<numArr.length ; i++) {
			index = (int)(Math.random()*10);
			tmp = numArr[i];
			numArr[i] = numArr[index];
			numArr[index] = tmp;
		}
		System.out.println(Arrays.toString(numArr));
	}

}
