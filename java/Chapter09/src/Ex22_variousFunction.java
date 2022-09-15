
public class Ex22_variousFunction {

	public static void main(String[] args) {

		int x1 = 1, y1 = 1;
		int x2 = 2, y2 = 2;
		
		double c = Math.sqrt(Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2));
		double a = c * Math.sin(Math.PI/4);
		double b = c * Math.cos(Math.PI/4);
		
		System.out.println("a = " + a);
		System.out.println("b = " + b);
		System.out.println("c = " + c);
	}

}
