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

// Ex02�� �޸� �����尡 ���� �������� �ʾҴ�. main�������� ȣ�⽺�� �ϳ��� �ִ�.
