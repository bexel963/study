
public class Ex17 {

	public static void main(String[] args) {

		String fullName = "Hello.java";
		
		int index = fullName.indexOf('.');
		System.out.println("index = " + index);
		
		String fileName = fullName.substring(0, index);
		System.out.println("fileName = " + fileName);
		
//		String ext = fullName.substring(index+1, fullName.length());
		String ext = fullName.substring(index+1);
		
		System.out.println(fullName + "�� Ȯ���ڸ� ������ �̸��� " + fileName);
		System.out.println(fullName + "�� Ȯ���ڴ� " + ext);
	}

}
