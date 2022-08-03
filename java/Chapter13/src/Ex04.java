
public class Ex04 {

	public static void main(String[] args) {

		long startTime = System.currentTimeMillis();
		
		for(int i=0 ; i<300 ; i++)
			System.out.print(new String("-"));
		
		System.out.println("소요시간1 : " + (System.currentTimeMillis() - startTime));
		
		for(int i=0 ; i<300 ; i++)
			System.out.print(new String("|"));
		
		System.out.println("소요시간2 : " + (System.currentTimeMillis() - startTime));
	}

}

// 하나의 쓰레드가 두 가지의 연속적인 작업을 처리하는 시간을 측정.
