
public class Ex10 {

	public static void main(String[] args) {

		Date d = new Date();
		d.x = 10;
		System.out.println("main() : x = " + d.x);
		
		change(d);
		
		System.out.println("After Change(d)");
		System.out.println("main() : x = " + d.x);
	}
	
	static void change(Date d) {
		d.x = 1000;
		System.out.println("change() : x = " + d.x);
	}
}
