import java.util.Arrays;
// 제한된 임의의 값으로 배열 채우기
public class Ex09 {

	public static void main(String[] args) {

		int[] code = {-4, -1, 3, 6, 11};
		int[] arr = new int[10];
		
		for(int i=0 ; i<arr.length ; i++) {
			int tmp = (int)(Math.random()*code.length);
			arr[i] = code[tmp];
		}
		System.out.println(Arrays.toString(arr));
	}

}
