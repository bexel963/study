import java.util.Scanner;

public class Ex21 {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		final int SIZE = 5;
		int[][] board = new int[SIZE][SIZE];
		int number = 0;
		
		for(int i=0 ; i<SIZE ; i++) {
			for(int j=0 ; j<SIZE ; j++) {
				board[i][j] = (int)(Math.random()*25+1);
			}
		}
		
		do {			
			for(int i=0 ; i<SIZE ; i++) {
				for(int j=0 ; j<SIZE ; j++) {
					if(number==board[i][j]) {
						board[i][j] = 0;
					}
					System.out.printf("%2d ", board[i][j]);
				}
				System.out.println();
			}
			System.out.println();
			
			System.out.print("1 ~ 25의 숫자를 입력하세요. (종료:0) > ");
			number = scan.nextInt();
			if(number == 0) {
				break;
			}
		}while(true);
		
		System.out.println("프로그램 종료!");
		
	}

}
