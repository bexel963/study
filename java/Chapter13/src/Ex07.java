import javax.swing.JOptionPane;

public class Ex07 {

	public static void main(String[] args) {

		Thread t = new Thread(new CntThread());
		t.start();
		
		String input = JOptionPane.showInputDialog("�ƹ� ���̳� �Է��ϼ���.");
		System.out.println("�Է��Ͻ� ���� " + input + " �Դϴ�.");
		
	}

}

class CntThread implements Runnable {
	public void run() {
		for(int i=10 ; i>0 ; i--) {
			System.out.println(i);
			try {
				Thread.sleep(1000);
			} catch(Exception e) { }
		}
	}
}

// �� �۾��� �� ���� ������� ����� ó��