import java.io.UnsupportedEncodingException;
import java.util.StringJoiner;

public class Ex15_getBytes {

	public static void main(String[] args) throws UnsupportedEncodingException {

		String str = "가";
		
		byte[] bArr = str.getBytes("UTF-8");
		byte[] bArr2 = str.getBytes("CP949");
		
		System.out.println("UTF-8 : " + joinByteArr(bArr));
		System.out.println("CP949 : " + joinByteArr(bArr2));
		System.out.println();
		System.out.println("UTF-8 : " + new String(bArr, "UTF-8"));
		System.out.println("CP949 : " + new String(bArr2, "CP949"));	
		
	}

	static String joinByteArr(byte[] bArr) {
		StringJoiner sj = new StringJoiner(":", "[", "]");
		
		for(byte b : bArr) {
			sj.add(String.format("%02X", b));
		}
		return sj.toString();
	}
}
/*
 * getBytes(String charsetName)를 사용하면, 문자열의 문자 인코딩을 다른 인코딩으로 변경할 수 있다.
 * UTF-8은 한글 한 글자를 3byte로 표현하고 CP949는 2byte로 표현한다.
 * */
 