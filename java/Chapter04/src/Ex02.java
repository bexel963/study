import java.util.Scanner;

public class Ex02 {

	public static void main(String[] args) {

		int input;
		
		System.out.print("���ڸ� �ϳ� �Է��ϼ���.>");
		
		Scanner scan = new Scanner(System.in);
		String tmp = scan.nextLine();
		input = Integer.parseInt(tmp);
		
		if(input==0)
			System.out.println("�Է��Ͻ� ���ڴ� 0�Դϴ�.");
		
		if(input!=0) {
			System.out.println("�Է��Ͻ� ���ڴ� 0�� �ƴմϴ�.");
			System.out.println("�Է��Ͻ� ���ڴ� " + input + "�Դϴ�.");
		}
	}

}
