
public class Ex10_float {

	public static void main(String[] args) {
		float f = 9.12345678901234567890f;	// 정밀도 소수점 6자리까지
		float f2 = 1.2345678901234567890f;
		double d = 9.12345678901234567890d;	// 정밀도 소수점 15자리까지
		
		System.out.printf("       123456789012345678901234\n");
		System.out.printf("f   :  %f\n", f);
		System.out.printf("f   :  %24.20f\n", f);
		System.out.printf("f2  :  %24.20f\n", f2);
		System.out.printf("d   :  %24.20f\n", d);
	}

}
