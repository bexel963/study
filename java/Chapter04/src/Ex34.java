import java.util.Scanner;

public class Ex34 {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		int menu = 0, num = 0;
		
		outer:
		while(true) {
			System.out.println("(1) square");
			System.out.println("(2) square root");
			System.out.println("(3) log");
			System.out.print("원하는 메뉴(1~3)를 선택하세요.(종료:0) > ");
			menu = scan.nextInt();
			if(menu==0) {
				System.out.println("프로그램을 종료합니다.");
				break;
			}else if(!(0<menu && menu<4)) {
				System.out.println("잘못된 메뉴입니다. 다시 선택해 주세요.");
				continue;
			}
			
			while(true) {
				System.out.print("계산할 값을 입력하세요.(계산종료:0, 전체종료:99) > ");
				num = scan.nextInt();
				if(num==0)
					break;
				if(num==99)
					break outer;
				switch(menu) {
					case 1:
						System.out.println("result = " + num * num);
						break;
					case 2:
						System.out.println("result = " + Math.sqrt(num));
						break;
					case 3:
						System.out.println("result = " + Math.log(num));
						break;
				}
			}
		}
	}

}
