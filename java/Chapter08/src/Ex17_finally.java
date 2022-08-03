
public class Ex17_finally {

	public static void main(String[] args) {

		try {
			startInstall();
			copyFiles();
			deleteTempFiles();
		} catch(Exception e) {
			e.printStackTrace();
			deleteTempFiles();	// 언제나 실행 되아야하는 메소드임.
		}
	}

	static void startInstall() {
		
	}
	static void copyFiles() {
		
	}
	static void deleteTempFiles() {
		
	}
}
