
public class Ex17_finally {

	public static void main(String[] args) {

		try {
			startInstall();
			copyFiles();
			deleteTempFiles();
		} catch(Exception e) {
			e.printStackTrace();
			deleteTempFiles();	// ������ ���� �Ǿƾ��ϴ� �޼ҵ���.
		}
	}

	static void startInstall() {
		
	}
	static void copyFiles() {
		
	}
	static void deleteTempFiles() {
		
	}
}
