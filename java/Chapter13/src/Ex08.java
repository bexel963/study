
public class Ex08 {

	public static void main(String[] args) {

		priorityOfThread1 t1 = new priorityOfThread1();
		priorityOfThread2 t2 = new priorityOfThread2();
		
		t2.setPriority(7);
		
		System.out.println("Priority of t1(-) : " + t1.getPriority());
		System.out.println("Priority of t2(|) : " + t2.getPriority());
		
		t1.start();
		t2.start();
	}

}

class priorityOfThread1 extends Thread {
	public void run() {
		for(int i=0 ; i<300 ; i++) {
			System.out.print("-");
			for(int x=0 ; x<10000000 ; x++);
		}
	}
}
class priorityOfThread2 extends Thread {
	public void run() {
		for(int i=0 ; i<300 ; i++) {
			System.out.print("|");
			for(int x=0 ; x<10000000 ; x++);
		}
	}
}