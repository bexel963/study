
public class Ex22 {

	public static void main(String[] args) {

		Buyer b = new Buyer();
		
		System.out.println(b);
		System.out.println();
		
		b.buy(new Tv0());
		b.buy(new Computer());
		b.buy(new Audio());
		System.out.println();
		
		b.summary();
	}

}
