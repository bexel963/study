
public class Ex13 {

	public static void main(String[] args) {

		method1();	// ���� Ŭ�������� static ����̹Ƿ� ��ü�������� ���� ȣ�Ⱑ��.
	}

	static void method1() {
		try {
			throw new Exception();
		} catch(Exception e) {
			System.out.println("method1�޼ҵ忡�� ���ܰ� ó���Ǿ����ϴ�.");
			e.printStackTrace();
		}
	}
}
