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

// ȣ�⽺���� ù ��° �޼��尡 main�޼��尡 �ƴ϶� run�޼����� ���� Ȯ��.
// -> �� �����尡 ���ܰ� �߻��ؼ� ����Ǿ �ٸ� �������� ���࿡�� ������ ��ġ�� �ʴ´�.
