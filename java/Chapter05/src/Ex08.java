import java.util.Arrays;
// ¼¯±â
public class Ex08 {

	public static void main(String[] args) {

		int[] ball = new int[45];
		int index = 0, tmp = 0;
		
		for(int i=0 ; i<ball.length ; i++) {
			ball[i] = i+1;
		}
		System.out.println(Arrays.toString(ball));
		
		for(int i=0 ; i<ball.length ; i++) {
			index = (int)(Math.random()*45);
			tmp = ball[i];
			ball[i] = ball[index];
			ball[index] = tmp;
		}
		
		for(int i=0 ; i<6 ; i++) {
			System.out.print(ball[i] + " ");
		}
		
	}

}
