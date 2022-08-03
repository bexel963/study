import java.util.Arrays;

// 정렬하기
public class Ex10 {

	public static void main(String[] args) {
		
		int[] numArr = new int[10];
		int tmp = 0;
		
		for(int i=0 ; i<numArr.length ; i++) {
			numArr[i] = (int)(Math.random()*10);
		}
		System.out.println("원본 배열 : " + Arrays.toString(numArr));
		
		for(int i=0 ; i<numArr.length-1 ; i++) {
			for(int k=0 ; k<numArr.length-1-i ; k++) {
				if(numArr[k]>numArr[k+1]) {
					tmp = numArr[k];
					numArr[k] = numArr[k+1];
					numArr[k+1] = tmp;
				}
			}
		}
		System.out.println("정렬 배열 : " + Arrays.toString(numArr));
	}

}
