/*
 	- �� ���ڿ�
 	: String s = ""; �� ���� ������ ���� ��, �������� s�� �����ϰ� �ִ� String�ν��Ͻ��� ���ο� new char[0]�� ���� ���̰� 0�� char�� �迭�� �����ϰ� �ִ� �� �̴�.
 	: �׷��� char c = ''; �� ���� ǥ���� ������ ���� �ƴϰ�, char�� �������� �ݵ�� �ϳ��� ���ڸ� �����ؾ� �Ѵ�. -> char c = ' ';
*/
public class Ex13_emptyString {

	public static void main(String[] args) {

		char[] cArr = new char[0];
		String s = new String(cArr);
		
		System.out.println("cArr.length = " + cArr.length);
		System.out.println("@@@" + s + "@@@");
	}

}
