
public class Ex05 {

	public static void main(String[] args) {

		System.out.println("Card.width = " + Card.width);
		System.out.println("Card.height = " + Card.height);
		
		Card c1 = new Card();
		c1.kind = "Heart";
		c1.number = 7;
		
		Card c2 = new Card();
		c2.kind = "Spade";
		c2.number = 4;
		
		System.out.println("c1은 " + c1.kind + ", " + c1.number + "이며 크기는 (" + Card.width + ", " + Card.height + ") 이다." );
		System.out.println("c2은 " + c2.kind + ", " + c2.number + "이며 크기는 (" + Card.width + ", " + Card.height + ") 이다." );
		
		System.out.println("c1과 c2의 넓이와 높이를 각각 50, 80 으로 변경합니다.");
		
		Card.width = 50;
		Card.height = 80;
		
		System.out.println("c1은 " + c1.kind + ", " + c1.number + "이며 크기는 (" + Card.width + ", " + Card.height + ") 이다." );
		System.out.println("c2은 " + c2.kind + ", " + c2.number + "이며 크기는 (" + Card.width + ", " + Card.height + ") 이다." );
	}

}
