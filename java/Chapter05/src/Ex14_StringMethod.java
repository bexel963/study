import java.util.Arrays;

public class Ex14_StringMethod {

	public static void main(String[] args) {
		
		String src = "ABCDE";
		
		for(int i=0 ; i<src.length() ; i++) {
			char ch = src.charAt(i);
			System.out.println("src.charAt("+i+") : " + ch);
		}
		
		char[] chArr = src.toCharArray();	// ���ڿ� -> �迭
		System.out.println(chArr);
		
		String str = new String(chArr);		// �迭 -> ���ڿ�
		System.out.println(str);
		
	}

}
