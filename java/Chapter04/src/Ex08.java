import java.util.Scanner;

public class Ex08 {

	public static void main(String[] args) {

		System.out.print("����� �ֹι�ȣ�� �Է��ϼ���.(011231-1111222)>");
		
		Scanner scan = new Scanner(System.in);
		String input = scan.nextLine();
		
		char first = input.charAt(7);
		
		switch(first) {
			case '1': case '3':
				System.out.println("����� �����Դϴ�.");
				break;
			case '2': case '4':
				System.out.println("����� �����Դϴ�.");
				break;
			default:
				System.out.println("��ȿ���� ���� �ֹε�Ϲ�ȣ �Դϴ�.");
		}
	}

}
