import java.util.Arrays;

public class Ex03_copy {

	public static void main(String[] args) {

		int[] arr = new int[5];
		
		for(int i=0 ; i<arr.length ; i++) {
			arr[i] = i;
		}
		System.out.println(Arrays.toString(arr));
		
		int[] newArr = new int[arr.length*2];
		
		for(int i=0 ; i<arr.length ; i++) {
			newArr[i] = arr[i];
		}
		System.out.println(Arrays.toString(newArr));
	
	}

}
