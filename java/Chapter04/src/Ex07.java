import java.util.Scanner;

public class Ex07 {

	public static void main(String[] args) {
		
		while(true) {
			System.out.print("����(1), ����(2), ��(3) �� �ϳ��� �Է��ϼ���.(����:0)> ");
			
			Scanner scan = new Scanner(System.in);
			int me = scan.nextInt();
			if(me==0)
				break;
			int com = (int)(Math.random()*3 + 1);
			
			System.out.println("����� ���� : " + me);
			System.out.println("���� ���� : " + com);
			switch(me-com) {
				case -2: case 1:
					System.out.println("����� �̰���ϴ�.");
					break;
				case 0:
					System.out.println("�����ϴ�.");
					break;
				default:
					System.out.println("����� �����ϴ�.");
					break;
			}
			System.out.println();
		}
		System.out.println("����!");
		
	}

}
