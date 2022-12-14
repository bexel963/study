import java.util.HashMap;
import java.util.Scanner;

public class Ex30_HashMap {

	public static void main(String[] args) {
		
		HashMap map = new HashMap();
		map.put("id", "1234");
		map.put("asdf", "1111");
		map.put("asdf", "1234");
		
		Scanner scan  = new Scanner(System.in);
		
		while(true) {
			System.out.println("id와 password를 입력해주세요.");
			System.out.print("id : ");
			String id = scan.nextLine();
			System.out.print("password : ");
			String pwd = scan.nextLine().trim();
			System.out.println();
			
			if(!map.containsKey(id)) {
				System.out.println("입력하신 id는 존재하지 않습니다. 다시 입력해주세요.");
				continue;
			}else {
				if(!(map.get(id).equals(pwd))) {
					System.out.println("비밀번호가 일치하지 않습니다. 다시 입력해주세요.");
				}else {
					System.out.println(id + "님 로그인 하셨습니다.");
					break;
				}
			}
		}
	}

}
