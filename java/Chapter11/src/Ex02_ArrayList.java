import java.util.ArrayList;

public class Ex02_ArrayList {

	public static void main(String[] args) {

		// �� ���ڿ��� ���ٿ� 10���� ���
		String str = "0123456789abcdefghijklmnopqrstuvwxyz~!@#$%^&*()_+";
		// �÷��� �̿�
		ArrayList list = new ArrayList();
		for(int i=0 ; i<str.length() ; i+=10) {
			if(i+10 > str.length()) {
				list.add(str.substring(i));
			}else {
				list.add(str.substring(i, i+10));				
			}
		}
		for(int i=0 ; i<list.size() ; i++) {
			System.out.println(list.get(i));
		}
		// String Ŭ������ ��� �̿�
	}

}
