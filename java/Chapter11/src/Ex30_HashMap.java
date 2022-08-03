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
			System.out.println("id�� password�� �Է����ּ���.");
			System.out.print("id : ");
			String id = scan.nextLine();
			System.out.print("password : ");
			String pwd = scan.nextLine().trim();
			System.out.println();
			
			if(!map.containsKey(id)) {
				System.out.println("�Է��Ͻ� id�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���.");
				continue;
			}else {
				if(!(map.get(id).equals(pwd))) {
					System.out.println("��й�ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.");
				}else {
					System.out.println(id + "�� �α��� �ϼ̽��ϴ�.");
					break;
				}
			}
		}
	}

}
