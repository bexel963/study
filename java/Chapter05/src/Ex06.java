// 최소값, 최대값
public class Ex06 {

	public static void main(String[] args) {

		int min = 0, max = 0;
		
		int[] score = {79, 88, 91, 33, 100, 55, 95};
		
		min = score[0];
		max = score[0];
		for(int i=1 ; i<score.length ; i++) {
			if(min > score[i]) {
				min = score[i];
			}
			if(max < score[i]) {
				max = score[i];
			}
		}
		System.out.println("최소값 : " + min + ", 최대값 : " + max);
	}

}
