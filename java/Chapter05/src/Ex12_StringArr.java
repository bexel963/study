import java.util.Arrays;

public class Ex12_StringArr {

	public static void main(String[] args) {

		String[] names = {"Kim", "Park", "Yi"};
		
		System.out.println(Arrays.toString(names));
		
		for(int i=0 ; i<names.length ; i++) {
			System.out.println("names[" + i + "] : " + names[i]);
		}
		
		String tmp = names[2];
		System.out.println("tmp : " + tmp);
		names[0] = "Yu";
		
		for(String str : names) {
			System.out.println(str);
		}
	}

}
