import java.util.Scanner;

public class Ex27 {

	public static void main(String[] args) {

		int num = 0;
		int sum = 0;
		boolean flag = true;
		
		System.out.println("�հ踦 ���� ���ڸ� �Է��ϼ���. (�������� 0�� �Է�)");
		
		Scanner scan = new Scanner(System.in);
		
		while(flag) {
			System.out.print(">>");
			num = scan.nextInt();
			if(num==0)
				flag = false;
			sum += num;
		}
		System.out.println("�հ� : " + sum);
		
	}

}
