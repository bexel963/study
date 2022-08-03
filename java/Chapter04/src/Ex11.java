import java.util.Scanner;

public class Ex11 {

	public static void main(String[] args) {

		System.out.print("당신의 주민번호를 입력하세요.(123456-1234567)>");
		
		Scanner scan = new Scanner(System.in);
		String input = scan.nextLine();
		
		char first = input.charAt(7);
		
		switch(first) {
			case '1': case '3':
				switch(first) {
					case '1':
						System.out.println("당신은 2000년 이전에 출생한 남자입니다.");
						break;
					case '3':
						System.out.println("당신은 2000년 이후에 출생한 남자입니다.");
						break;
				}
				break;
			case '2': case '4':
				switch(first) {
				case '2':
					System.out.println("당신은 2000년 이전에 출생한 여자입니다.");
					break;
				case '4':
					System.out.println("당신은 2000년 이후에 출생한 여자입니다.");
					break;
			}
				break;
		}
	}

}
