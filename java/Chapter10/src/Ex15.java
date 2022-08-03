
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class Ex15 {

	public static void main(String[] args) {

		String pattern = "yyyy/MM/dd";
		DateFormat df = new SimpleDateFormat(pattern);
		Scanner s = new Scanner(System.in);
		
		Date inDate = null;
		
		System.out.println("��¥�� " + pattern + "�� ���·� �Է��� �ּ���.");
		
		while(s.hasNextLine()) {
			try {
				inDate = df.parse(s.nextLine());
				break;
			}catch(Exception e) {
				System.out.println("��¥�� " + pattern + "�� ���·� �ٽ� �Է��� �ּ���");
			}
		}
		
		Calendar cal = Calendar.getInstance();
		cal.setTime(inDate);	// Date�� Calendar�� ��ȯ
	
		Calendar today = Calendar.getInstance();
		long day = (Math.abs(cal.getTimeInMillis() - today.getTimeInMillis()) / (60*60*1000));
		
		System.out.println("�Է��Ͻ� ��¥�� ����� " + day + "�ð� ���̰� �ֽ��ϴ�.");
	}

}
