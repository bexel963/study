import java.util.Scanner;
import java.util.Stack;

// 웹 브라우저의 앞으로 뒤로가기 기능

public class Ex08_Uses_SackQueue01 {

	static Stack list = new Stack();
	static Stack list2 = new Stack();
	
	public static void main(String[] args) {
		
		int input = 0;
		String address = "";
		Scanner scan = new Scanner(System.in);
		
		System.out.println("주소 검색 : ");
		while(true){
			address = scan.nextLine();
			if("z".equals(address))
				break;
			list.push(address);
		};
		
		
		do {
			System.out.println("\n==== 검색 목록 ====");
			listPrint(list);
			System.out.println("현재 페이지 : " + list.peek());
			System.out.println("=================");
			System.out.println("===== 기능 선택 =====");
			System.out.println("1. 뒤로");
			System.out.println("2. 앞으로");
			System.out.println("99. 종료");
			System.out.println("===================");
			System.out.print("기능 선택 : \n");
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
			System.out.println("첫 페이지 입니다.");
			return;
		}
		list2.push(list.pop());
		
	}
	public static void after() {
		if(list2.empty()) {
			System.out.println("마지막 페이지 입니다.");
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
