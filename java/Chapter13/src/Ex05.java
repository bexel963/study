
public class Ex05 {
	
	static long startTime = 0;
	
	public static void main(String[] args) {

		Runnable r = new printThread();
		Thread t = new Thread(r);
		
		t.start();
		startTime = System.currentTimeMillis();
		
		for(int i=0 ; i<300 ; i++)
			System.out.print(new String("|"));
		System.out.println("소요시간(main) : " + (System.currentTimeMillis() - startTime));
		
	
	}

}

class printThread implements Runnable {
	
	
	public void run() {
		for(int i=0 ; i<300 ; i++)
			System.out.print(new String("-"));
		System.out.println("소요시간(thread) : " + (System.currentTimeMillis() - Ex05.startTime));
	}
}

// 두 개의 쓰레드가 두 가지의 연속적인 작업을 처리하는 시간을 측정 - Ex04 보다 오래걸린다.
