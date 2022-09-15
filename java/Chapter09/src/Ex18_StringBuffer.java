
public class Ex18_StringBuffer {

	public static void main(String[] args) {

		StringBuffer sb = new StringBuffer("abc");
		StringBuffer sb2 = new StringBuffer("abc");
		
		System.out.println("sb == sb2 : " + (sb==sb2));
		System.out.println("sb.equals(sb2) : " + sb.equals(sb2));	// StringBuffer는 equals()를 오버라이딩 해놓지 않음.
		
		String s = sb.toString();					// toString()은 오버라이딩 되어있는데, 비교할 때는 문자열로 바꿔놓고 비교한다.
		String s2 = sb.toString();
		
		System.out.println("s.equals(s2) : " + s.equals(s2));
	}

}
