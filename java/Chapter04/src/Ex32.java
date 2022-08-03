import java.util.Scanner;

public class Ex32 {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		int menu = 0;
		
		do {
			System.out.println("(1) square");
			System.out.println("(2) square root");
			System.out.println("(3) log");
			System.out.print("원하는 메뉴(1~3)를 선택하세요. (종료:0) > ");
			menu = scan.nextInt();
			if(menu==0) {
				System.out.println("프로그램을 종료합니다.");
				break;
			}else if(!(0<menu && menu<4)) {
				System.out.println("메뉴를 잘못 선택하셨습니다.");	
				continue;
			}
			System.out.println("선택하신 메뉴는 " + menu + "번 입니다.");
		}while(true);

	}

}
