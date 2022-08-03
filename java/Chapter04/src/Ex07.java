import java.util.Scanner;

public class Ex07 {

	public static void main(String[] args) {
		
		while(true) {
			System.out.print("가위(1), 바위(2), 보(3) 중 하나를 입력하세요.(종료:0)> ");
			
			Scanner scan = new Scanner(System.in);
			int me = scan.nextInt();
			if(me==0)
				break;
			int com = (int)(Math.random()*3 + 1);
			
			System.out.println("당신이 낸거 : " + me);
			System.out.println("컴이 낸거 : " + com);
			switch(me-com) {
				case -2: case 1:
					System.out.println("당신이 이겼습니다.");
					break;
				case 0:
					System.out.println("비겼습니다.");
					break;
				default:
					System.out.println("당신이 졌습니다.");
					break;
			}
			System.out.println();
		}
		System.out.println("종료!");
		
	}

}
