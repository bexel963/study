import javax.swing.JOptionPane;

public class Ex06 {

	public static void main(String[] args) {
		
		String input = JOptionPane.showInputDialog("아무 값이나 입력하세요.");
		System.out.println("입력하신 값은 " + input + " 입니다.");
		
		for(int i=10 ; i>0 ; i--) {
			System.out.println(i);
			try {
				Thread.sleep(1000);
			} catch(Exception e) { }
		}
	}
}

// 하나의 쓰레드로 사용자의 입력을 받는 작업과 화면에 숫자를 출력하는 작업을 처리.
