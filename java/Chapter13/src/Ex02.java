class MyThread3 extends Thread {
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
public class Ex02 {

	public static void main(String[] args) {
	
		MyThread3 t = new MyThread3();
		
		t.start();
	}

}

// 호출스택의 첫 번째 메서드가 main메서드가 아니라 run메서드인 것을 확인.
// -> 한 쓰레드가 예외가 발생해서 종료되어도 다른 쓰레드의 실행에는 영향을 미치지 않는다.
