
public class Ex05 {
	
	static long startTime = 0;
	
	public static void main(String[] args) {

		Runnable r = new printThread();
		Thread t = new Thread(r);
		
		t.start();
		startTime = System.currentTimeMillis();
		
		for(int i=0 ; i<300 ; i++)
			System.out.print(new String("|"));
		System.out.println("�ҿ�ð�(main) : " + (System.currentTimeMillis() - startTime));
		
	
	}

}

class printThread implements Runnable {
	
	
	public void run() {
		for(int i=0 ; i<300 ; i++)
			System.out.print(new String("-"));
		System.out.println("�ҿ�ð�(thread) : " + (System.currentTimeMillis() - Ex05.startTime));
	}
}

// �� ���� �����尡 �� ������ �������� �۾��� ó���ϴ� �ð��� ���� - Ex04 ���� �����ɸ���.
