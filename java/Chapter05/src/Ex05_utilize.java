// ÃÑÇÕ, Æò±Õ
public class Ex05_utilize {

	public static void main(String[] args) {
		
		int sum = 0;
		double avg = 0;
		int[] score = {100, 88, 100, 100, 90};
		
		for(int i=0 ; i<score.length ; i++) {
			sum += score[i];
		}
		
		avg = (double)sum / score.length;
		
		System.out.println("ÃÑÇÕ : " + sum + ", Æò±Õ : " + avg);
	}

}
