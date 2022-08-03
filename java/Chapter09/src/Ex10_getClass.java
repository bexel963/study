final class Card3 {
	String kind;
	int num;
	
	Card3() {
		this("SAPDE", 1);
	}
	Card3(String kind, int num) {
		this.kind = kind;
		this.num = num;
	}
	public String toString() {
		return kind + " : " + num;
	}
}
public class Ex10_getClass {

	public static void main(String[] args) throws Exception {

		Card3 c = new Card3("HEART", 3);
		Card3 c2 = Card3.class.newInstance();	// Class객체를 이용해서 객체 생성 - 예외처리가 필요하다.
		
		Class cObj = c.getClass();				// 생성된 객체로 부터 얻는 방법
		Class cObj2 = new Card3().getClass();	// 생성된 객체로 부터 얻는 방법
		Class cObj3 = Card3.class;				// 클래스 리터럴(*.class)로부터 얻는 방법
		Class cObj4 = Class.forName("Card3");	// 클래스 이름으로 부터 얻는 방법
		
		System.out.println(c);
		System.out.println(c2);
		System.out.println(cObj.getName());
		System.out.println(cObj.toGenericString());
		System.out.println(cObj.toString());
	}

}

/*
 * getClass()는 자신이 속한 클래스의 Class객체를 반환한다.
 * Class객체는 이름이 'Class'인 클래스의 객체이다.
 * Class객체는 클래스의 모든 정보를 담고 있으며, 클래스 당 1개만 존재한다.
 * 클래스 파일이 클래스 로더에 의해서 메모리에 올라갈 때, 자동으로 생성된다.
 * */
