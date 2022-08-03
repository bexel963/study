
public class Ex01 {

	public static void main(String[] args) {

		MyThread1 t1 = new MyThread1();
		
		Runnable r = new MyThread2();
		Thread t2 = new Thread(r);
		
		t1.start();
		t2.start();
	}

}

class MyThread1 extends Thread {
	@Override
	public void run() {
		for(int i=0 ; i<5 ; i++) {
			System.out.println(getName());
		}
	}
}

class MyThread2 implements Runnable {
	public void run() {
		for(int i=0 ; i<5 ; i++) {
			System.out.println(Thread.currentThread().getName());
		}
	}
}

// ����� ���� run()�� �������̵����� �ʰ� �ܺηκ��� run()�� �������� �� �ְԵȴ�.