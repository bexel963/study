
public class Ex19 {

	public static void main(String[] args) {

		Ex19.method1();
		System.out.println("medhod1()�� ������ ��ġ�� main�޼ҵ�� ���ƿԽ��ϴ�.");
	}
	
	static void method1() {
		try {
			System.out.println("method1()�� ȣ��Ǿ����ϴ�.");
			return;
		} catch(Exception e) {
			e.printStackTrace();
		} finally {
			System.out.println("method1()�� finally���� ����Ǿ����ϴ�.");
		}
	}

}
