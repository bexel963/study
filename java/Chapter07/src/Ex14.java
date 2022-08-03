final class Singleton {
	// getInstance() ���� ���� �� �ֵ��� �ν��Ͻ��� �̸� �����Ǿ�� �ϹǷ� static�̾�� �Ѵ�.
	private static Singleton s = new Singleton();
	
	private Singleton() {
		
	}
	// �ν��Ͻ��� �������� �ʰ� ȣ���� �� �־�� �ϹǷ� static�̾�� �Ѵ�.
	public static Singleton getInstance() {
		if(s==null) {
			s = new Singleton();
		}
		return s;
	}
}
public class Ex14 {

	public static void main(String[] args) {

//		Singleton s = new Singleton(); -> ����
		Singleton s = Singleton.getInstance();
		
		System.out.println(s);
	}

}
