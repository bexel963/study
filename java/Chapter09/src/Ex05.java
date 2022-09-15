// String클래스와 Date클래스의 경우 Object클래스toString()이 오버라이딩 되어있다.

public class Ex05 {

	public static void main(String[] args) {

		String str = new String("KOREA");
		java.util.Date today = new java.util.Date();
		
		System.out.println(str);
		System.out.println(str.toString());
		System.out.println(today);
		System.out.println(today.toString());
	}

}
