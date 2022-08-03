
public class Ex07_char {

	public static void main(String[] args) {

		char ch = 'A';
		int code = (int)ch;
		
		System.out.printf("%c = %d(%#x)\n", ch, code, code);
		
		char hck = '°¡';
		int code2 = (int)hck;
		
		System.out.printf("%c = %d(%#x)\n", hck, code2, code2);

	}

}
