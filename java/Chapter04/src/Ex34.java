import java.util.Scanner;

public class Ex34 {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		int menu = 0, num = 0;
		
		outer:
		while(true) {
			System.out.println("(1) square");
			System.out.println("(2) square root");
			System.out.println("(3) log");
			System.out.print("���ϴ� �޴�(1~3)�� �����ϼ���.(����:0) > ");
			menu = scan.nextInt();
			if(menu==0) {
				System.out.println("���α׷��� �����մϴ�.");
				break;
			}else if(!(0<menu && menu<4)) {
				System.out.println("�߸��� �޴��Դϴ�. �ٽ� ������ �ּ���.");
				continue;
			}
			
			while(true) {
				System.out.print("����� ���� �Է��ϼ���.(�������:0, ��ü����:99) > ");
				num = scan.nextInt();
				if(num==0)
					break;
				if(num==99)
					break outer;
				switch(menu) {
					case 1:
						System.out.println("result = " + num * num);
						break;
					case 2:
						System.out.println("result = " + Math.sqrt(num));
						break;
					case 3:
						System.out.println("result = " + Math.log(num));
						break;
				}
			}
		}
	}

}
