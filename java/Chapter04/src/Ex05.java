import java.util.Scanner;

public class Ex05 {

	public static void main(String[] args) {
		int score = 0;
		char grade = ' ', opt = ' ';
		
		System.out.print("점수를 입력하세요.>");
		Scanner scan = new Scanner(System.in);
		score = scan.nextInt();
		
		if(score >= 90) {
			grade = 'A';
			if(score >= 98) {
				opt = '+';				
			}else if(score < 94) {
				opt = '-';
			}
		}else if(score >= 80) {
			grade = 'B';
			if(score >= 88) {
				opt = '+';				
			}else if(score < 84) {
				opt = '-';
			}
		}else if(score >= 70) {
			grade = 'C';
		}else {
			grade = 'D';
		}
		System.out.println("당신의 학점은 " + grade + opt + "입니다.");

	}

}
