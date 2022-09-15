
public class Ex05_printf {

	public static void main(String[] args) {
		
		String url = "www.codechobo.com";
		
		float f1 = .10f;
		float f2 = 1e1f;
		float f3 = 3.14e3f;
		double d = 1.23456789;
		
		System.out.printf("f1 = %f, %e, %g\n", f1, f1, f1);
		System.out.printf("f2 = %f, %e, %g\n", f2, f2, f2);
		System.out.printf("f3 = %f, %e, %g\n", f3, f3, f3);
		System.out.println();
		
		System.out.printf("d = [%f]\n", d);
		System.out.printf("d = [%14.10f]\n", d);	// 전체 14자리 출력하고, 그 중 소수점 아래는 10자리
		System.out.println();
		
		System.out.printf("[12345678901234567890]\n");
		System.out.printf("[%s]\n", url);
		System.out.printf("[%20s]\n", url);
		System.out.printf("[%-20s]\n", url);
		System.out.printf("[%.8s]\n", url);
	}

}
