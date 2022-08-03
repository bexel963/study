
public class Ex22 {

	public static void main(String[] args) {

		float f = 0.1f;
		double d = 0.1;
		double c = (double)f;
		
		System.out.printf("10.0==10.0f   %b\n", 10.0 == 10.0f);
		System.out.printf("0.1==0.1f     %b\n", 0.1 == 0.1f);
		System.out.printf("f = %19.17f\n", f);
		System.out.printf("d = %19.17f\n", d);
		System.out.printf("c = %19.17f\n", c);
		System.out.printf("d==f          %b\n", d == f);
		System.out.printf("d==c          %b\n", d == c);
		System.out.printf("c==f          %b\n", c == f);
		System.out.printf("(float)d==f   %b\n", (float)d == f);
	}

}
