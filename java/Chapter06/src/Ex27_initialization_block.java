
public class Ex27_initialization_block {

	static {
		System.out.println("static { }");
	}
	{
		System.out.println("instance { }");
	}
	Ex27_initialization_block() {
		System.out.println("»ý¼ºÀÚ");
	}
	public static void main(String[] args) {
		
		System.out.println("Ex27 ex1 = new Ex27(); ");
		Ex27_initialization_block ex1 = new Ex27_initialization_block();
		
		System.out.println("Ex27 ex2 = new Ex27(); ");
		Ex27_initialization_block ex2 = new Ex27_initialization_block();	
	}
}
