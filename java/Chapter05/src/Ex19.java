
public class Ex19 {

	public static void main(String[] args) {
		
		int[][] score = {
							{ 100, 100, 100 },
							{ 20, 20, 20 },
							{ 30, 30, 30 },
							{ 40, 40, 40 },
							{ 50, 50, 50 }
						};
		
		int korTotal = 0 , engTotal = 0, mathTotal = 0;
		
		System.out.println("º¯È£    ±¹¾î     ¿µ¾î     ¼öÇÐ    ÃÑÁ¡    Æò±Õ");
		System.out.println("========================================");
		
		for(int i=0 ; i<score.length ; i++) {
			int sum = 0;
			float avg = 0;
			
			korTotal += score[i][0];
			engTotal += score[i][1];
			mathTotal += score[i][2];
			
			System.out.printf("%2d    ", i+1);
			for(int j=0 ; j<score[i].length ; j++) {
				System.out.printf(" %3d    ", score[i][j]);
				
				sum += score[i][j];
				avg = sum / score[i].length;
			}
			System.out.printf("%3d   %3.1f", sum, avg);
			System.out.println();
		}
		System.out.println("========================================");
		System.out.printf("ÃÑÁ¡ :  %3d     %3d     %3d\n", korTotal, engTotal, mathTotal);
	}

}
