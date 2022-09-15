import java.util.Arrays;
import java.util.StringJoiner;

/*
 [dog, cat, bear]
dog-cat-bear
< DOG/CAT/BEAR >
*/
public class Main {
	public static void main(String[] args) {
		
		String str = "dog,cat,bear";
		
		String[] arr = str.split(",");
		System.out.println(Arrays.toString(arr));
		
		str = String.join("-", arr);
		System.out.println(str);
		
		int index = 0;
		for(String s : arr) {
			arr[index] = s.toUpperCase();
			index++;
		}
		System.out.println(Arrays.toString(arr));
		StringJoiner sj = new StringJoiner("/", "<", ">");
		for(String s : arr) {
			sj.add(s);
		}
		System.out.println(sj);
	}
}
 