import java.util.Scanner;

public class Ex32 {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		int menu = 0;
		
		do {
			System.out.println("(1) square");
			System.out.println("(2) square root");
			System.out.println("(3) log");
			System.out.print("���ϴ� �޴�(1~3)�� �����ϼ���. (����:0) > ");
			menu = scan.nextInt();
			if(menu==0) {
				System.out.println("���α׷��� �����մϴ�.");
				break;
			}else if(!(0<menu && menu<4)) {
				System.out.println("�޴��� �߸� �����ϼ̽��ϴ�.");	
				continue;
			}
			System.out.println("�����Ͻ� �޴��� " + menu + "�� �Դϴ�.");
		}while(true);

	}

}
