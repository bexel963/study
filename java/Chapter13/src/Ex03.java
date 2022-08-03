class MyThread4 extends Thread {
	public void run() {
		throwException();
	}
	public void throwException() {
		try {
			throw new Exception();
		} catch(Exception e){
			e.printStackTrace();
		}
	}
}

public class Ex03 {

	public static void main(String[] args) {

		MyThread4 t = new MyThread4();
		
		t.run();
	}

}

// Ex02와 달리 쓰레드가 새로 생성되지 않았다. main쓰레드의 호출스택 하나만 있다.
