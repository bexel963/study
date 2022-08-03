// < Ex37의 EventHandler클래스를 익명 클래스로 변경 >

import java.awt.Button;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ex38 {

	public static void main(String[] args) {

		Button b = new Button("Start");
		b.addActionListener(new EventHandler() {
			public void actionPerformed(ActionEvent e) {
				System.out.println("ActionEvent occurred!!!");
			}
		});
	}

}
