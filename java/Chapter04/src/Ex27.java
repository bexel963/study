import java.util.Scanner;

public class Ex27 {

	public static void main(String[] args) {

		int num = 0;
		int sum = 0;
		boolean flag = true;
		
		System.out.println("합계를 구할 숫자를 입력하세요. (끝내려면 0을 입력)");
		
		Scanner scan = new Scanner(System.in);
		
		while(flag) {
			System.out.print(">>");
			num = scan.nextInt();
			if(num==0)
				flag = false;
			sum += num;
		}
		System.out.println("합계 : " + sum);
		
	}

}
