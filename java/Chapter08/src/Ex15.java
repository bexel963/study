// ���ܰ� �߻��� �޼��忡�� ���ܸ� ó��

import java.io.File;

public class Ex15 {

	public static void main(String[] args) {

		File f = createFile("text.txt");
		System.out.println(f.getName() + " ������ ���������� �����Ǿ����ϴ�.");
	}
	
	static File createFile(String fileName) {
		try {
			if(fileName==null || fileName.equals("")) {
				throw new Exception("���� �̸��� ��ȿ���� �ʽ��ϴ�.");
			}
		} catch(Exception e) {
			fileName = "�������.txt";
		} finally {
			File f = new File(fileName);
			createNewFile(f);
			return f;
		}
	}
	
	static void createNewFile(File f) {
		try {
			f.createNewFile();
		} catch(Exception e) {
			
		}
	}

}
