import javax.swing.JOptionPane;

public class Ex07 {

	public static void main(String[] args) {

		Thread t = new Thread(new CntThread());
		t.start();
		
		String input = JOptionPane.showInputDialog("아무 값이나 입력하세요.");
		System.out.println("입력하신 값은 " + input + " 입니다.");
		
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

// 두 작업을 두 개의 쓰레드로 나누어서 처리