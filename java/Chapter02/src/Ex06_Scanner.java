import java.util.Scanner;

public class Ex06_Scanner {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		System.out.print("�� �ڸ� ������ �Է��ϼ���.> ");
		
		String input = scan.nextLine();
		
		int num = Integer.parseInt(input);
		
		System.out.println("�Է��� �� : " + input);
		System.out.printf("num = %d\n", num);
	}

}
