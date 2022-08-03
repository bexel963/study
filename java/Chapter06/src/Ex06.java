class MyMath {
	long add(long a, long b) {
		return a+b;
	}
	long subtract(long a, long b) {
		return a-b;
	}
	long multiply(long a, long b) {
		return a*b;
	}
	double divide(double a, double b) {
		return a/b;
	}
}
public class Ex06 {

	public static void main(String[] args) {

		MyMath mm = new MyMath();
		
		long result1 = mm.add(5, 3);
		long result2 = mm.subtract(5, 3);
		long result3 = mm.multiply(5, 3);
		double result4 = mm.divide(5, 3);
		
		System.out.println("add(5, 3) = " + result1);
		System.out.println("subtract(5, 3) = " + result2);
		System.out.println("multiply(5, 3) = " + result3);
		System.out.println("divide(5, 3) = " + result4);
	}

}
