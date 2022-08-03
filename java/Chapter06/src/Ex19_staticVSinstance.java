
class MyMath2 {
	long a, b;
	
	long add() { return a+b; }
	long subtract() { return a-b; }
	long multiply() { return a*b; }
	long divide() { return a/b; }
	
	static long add(long a, long b) {
		return a+b;
	}
	static long subtract(long a, long b) {
		return a-b;
	}
	static long multiply(long a, long b) {
		return a*b;
	}
	static double divide(double a, double b) {
		return a/b;
	}
}
public class Ex19_staticVSinstance {

	public static void main(String[] args) {

		System.out.println(MyMath2.add(3, 5));
		System.out.println(MyMath2.subtract(3, 5));
		System.out.println(MyMath2.multiply(3, 5));
		System.out.println(MyMath2.divide(3, 5));
		
		System.out.println();
		
		MyMath2 mm = new MyMath2();
		mm.a = 3;
		mm.b = 5;
		System.out.println(mm.add());
		System.out.println(mm.subtract());
		System.out.println(mm.multiply());
		System.out.println(mm.divide());
	}

}
