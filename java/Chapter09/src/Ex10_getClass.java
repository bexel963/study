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
		Card3 c2 = Card3.class.newInstance();	// Class��ü�� �̿��ؼ� ��ü ���� - ����ó���� �ʿ��ϴ�.
		
		Class cObj = c.getClass();				// ������ ��ü�� ���� ��� ���
		Class cObj2 = new Card3().getClass();	// ������ ��ü�� ���� ��� ���
		Class cObj3 = Card3.class;				// Ŭ���� ���ͷ�(*.class)�κ��� ��� ���
		Class cObj4 = Class.forName("Card3");	// Ŭ���� �̸����� ���� ��� ���
		
		System.out.println(c);
		System.out.println(c2);
		System.out.println(cObj.getName());
		System.out.println(cObj.toGenericString());
		System.out.println(cObj.toString());
	}

}

/*
 * getClass()�� �ڽ��� ���� Ŭ������ Class��ü�� ��ȯ�Ѵ�.
 * Class��ü�� �̸��� 'Class'�� Ŭ������ ��ü�̴�.
 * Class��ü�� Ŭ������ ��� ������ ��� ������, Ŭ���� �� 1���� �����Ѵ�.
 * Ŭ���� ������ Ŭ���� �δ��� ���ؼ� �޸𸮿� �ö� ��, �ڵ����� �����ȴ�.
 * */
