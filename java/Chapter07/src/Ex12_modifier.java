class Card2 {
	final int NUMBER;
	final String KIND;
	static int width = 100;
	static int height = 250;
	
	Card2(String kind, int num) {
		KIND = kind;
		NUMBER = num;
	}
	Card2() {
		this("HEART", 1);
	}
	public String toString() {
		return KIND + " " + NUMBER;
	}
}
public class Ex12_modifier {

	public static void main(String[] args) {

		Card2 c = new Card2("SPADE", 10);
		
//		c.NUMBER = 4; -> ¿¡·¯
		System.out.println(c.KIND);
		System.out.println(c.NUMBER);
		System.out.println(c);
	}

}
