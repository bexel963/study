import java.util.Arrays;

public class Ex14_StringMethod {

	public static void main(String[] args) {
		
		String src = "ABCDE";
		
		for(int i=0 ; i<src.length() ; i++) {
			char ch = src.charAt(i);
			System.out.println("src.charAt("+i+") : " + ch);
		}
		
		char[] chArr = src.toCharArray();	// 문자열 -> 배열
		System.out.println(chArr);
		
		String str = new String(chArr);		// 배열 -> 문자열
		System.out.println(str);
		
	}

}
