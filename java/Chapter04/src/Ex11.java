import java.util.Scanner;

public class Ex11 {

	public static void main(String[] args) {

		System.out.print("����� �ֹι�ȣ�� �Է��ϼ���.(123456-1234567)>");
		
		Scanner scan = new Scanner(System.in);
		String input = scan.nextLine();
		
		char first = input.charAt(7);
		
		switch(first) {
			case '1': case '3':
				switch(first) {
					case '1':
						System.out.println("����� 2000�� ������ ����� �����Դϴ�.");
						break;
					case '3':
						System.out.println("����� 2000�� ���Ŀ� ����� �����Դϴ�.");
						break;
				}
				break;
			case '2': case '4':
				switch(first) {
				case '2':
					System.out.println("����� 2000�� ������ ����� �����Դϴ�.");
					break;
				case '4':
					System.out.println("����� 2000�� ���Ŀ� ����� �����Դϴ�.");
					break;
			}
				break;
		}
	}

}
