import java.util.Scanner;

public class Ex03 {

	public static void main(String[] args) {
		

		
		System.out.print("���ڸ� �ϳ� �Է��ϼ���.>");
		
		Scanner scan = new Scanner(System.in);
		
		int input = scan.nextInt();
		
		if(input==0) {
			System.out.println("�Է��Ͻ� ���ڴ� 0�Դϴ�.");			
		}else{
			System.out.println("�Է��Ͻ� ���ڴ� 0�� �ƴմϴ�.");
			System.out.println("�Է��Ͻ� ���ڴ� " + input + "�Դϴ�.");
		}
	}

}
