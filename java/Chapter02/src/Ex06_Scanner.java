import java.util.Scanner;

public class Ex06_Scanner {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		System.out.print("두 자리 정수를 입력하세요.> ");
		
		String input = scan.nextLine();
		
		int num = Integer.parseInt(input);
		
		System.out.println("입력한 수 : " + input);
		System.out.printf("num = %d\n", num);
		
		System.out.println(input.getClass().getName());
		
	}

}
