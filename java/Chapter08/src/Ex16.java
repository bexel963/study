// 예외를 호출한 메서드에서 예외 처리

import java.io.File;

public class Ex16 {

	public static void main(String[] args) {

		try {
			File f = createFile("텍스트파일.txt");
			System.out.println(f.getName() + " 파일이 성공적으로 생성되었습니다.");			
		} catch(Exception e) {
			System.out.println(e.getMessage() + " 다시 입력해 주시기 바랍니다.");
		}
	}
	
	static File createFile(String fileName) throws Exception {

		if(fileName==null || fileName.equals("")) {
			throw new Exception("파일 이름이 유효하지 않습니다.");
		}
		File f = new File(fileName);
		createNewFile(f);
		return f;	
	}
	
	static void createNewFile(File f) {
		try {
			f.createNewFile();
		} catch(Exception e) {
			
		}
	}

}
