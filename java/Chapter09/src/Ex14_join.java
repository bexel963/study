import java.util.Arrays;
import java.util.StringJoiner;

public class Ex14_join {

	public static void main(String[] args) {

		String animal = "dog,cat,bear";
		String[] arr = animal.split(",");
		
		System.out.println(Arrays.toString(arr));
		
		animal = String.join("-", arr);
		
		System.out.println(animal);
		
		StringJoiner sj = new StringJoiner("/", "< ", " >");	// java.util.StringJoiner
		for(String s : arr) {
			sj.add(s.toUpperCase());
		}
		
		System.out.println(sj);
	}

}
