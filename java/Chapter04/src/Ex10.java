import java.util.Scanner;

public class Ex10 {

	public static void main(String[] args) {
		
		char grade = ' ';
		
		System.out.print("����� ������ �Է��ϼ���.>");
		
		Scanner scan = new Scanner(System.in);
		int score = scan.nextInt();
		
		switch(score / 10) {
			case 10: case 9:
				grade = 'A';
				break;
			case 8:
				grade = 'B';
				break;
			case 7:
				grade = 'C';
				break;
			default:
				grade = 'F';
		}
		System.out.println("����� ������ " + grade + " �Դϴ�.");

	}

}
