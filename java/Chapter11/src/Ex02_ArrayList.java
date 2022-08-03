import java.util.ArrayList;

public class Ex02_ArrayList {

	public static void main(String[] args) {

		// 긴 문자열을 한줄에 10개씩 출력
		String str = "0123456789abcdefghijklmnopqrstuvwxyz~!@#$%^&*()_+";
		// 컬렉션 이용
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
		// String 클래스의 멤버 이용
	}

}
