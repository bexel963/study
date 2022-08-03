import java.util.Scanner;

public class Ex08 {

	public static void main(String[] args) {

		System.out.print("당신의 주민번호를 입력하세요.(011231-1111222)>");
		
		Scanner scan = new Scanner(System.in);
		String input = scan.nextLine();
		
		char first = input.charAt(7);
		
		switch(first) {
			case '1': case '3':
				System.out.println("당신은 남자입니다.");
				break;
			case '2': case '4':
				System.out.println("당신은 여자입니다.");
				break;
			default:
				System.out.println("유효하지 않은 주민등록번호 입니다.");
		}
	}

}
