import java.util.Scanner;
import java.util.Stack;

// �� �������� ������ �ڷΰ��� ���

public class Ex08_Uses_SackQueue01 {

	static Stack list = new Stack();
	static Stack list2 = new Stack();
	
	public static void main(String[] args) {
		
		int input = 0;
		String address = "";
		Scanner scan = new Scanner(System.in);
		
		System.out.println("�ּ� �˻� : ");
		while(true){
			address = scan.nextLine();
			if("z".equals(address))
				break;
			list.push(address);
		};
		
		
		do {
			System.out.println("\n==== �˻� ��� ====");
			listPrint(list);
			System.out.println("���� ������ : " + list.peek());
			System.out.println("=================");
			System.out.println("===== ��� ���� =====");
			System.out.println("1. �ڷ�");
			System.out.println("2. ������");
			System.out.println("99. ����");
			System.out.println("===================");
			System.out.print("��� ���� : \n");
			input = Integer.valueOf(scan.nextLine());
			
			switch(input) {
				case 1:
					before();
					break;
				case 2:
					after();
					break;
			}
		}while(input!=99);
	}
	
	public static void before() {
		if(list.size()==1) {
			System.out.println("ù ������ �Դϴ�.");
			return;
		}
		list2.push(list.pop());
		
	}
	public static void after() {
		if(list2.empty()) {
			System.out.println("������ ������ �Դϴ�.");
			return;
		}
		list.push(list2.pop());
	}
	public static void listPrint(Stack list) {
		Stack newList = (Stack)list.clone();
		while(!newList.empty()) {
			System.out.println(newList.pop());
		}
	}
}
