
public class Ex03_card {

	public static void main(String[] args) {

		Deck d = new Deck();
		Card c = d.pick(0);
		
		System.out.println(c);
		
		d.shuffle();
		c = d.pick(0);
		System.out.println(c);
		
	}

}
