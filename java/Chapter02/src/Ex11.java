
public class Ex11 {

	public static void main(String[] args) {

		float f = 9.1234567f;
		int i = Float.floatToIntBits(f);
		
		System.out.printf("%f\n", f);
		System.out.println(i);
		System.out.printf("%X\n", i);
	}

}
