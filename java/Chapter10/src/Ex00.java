
import java.util.Calendar;
import java.util.Date;

public class Ex00 {

	public static void main(String[] args) {

		Calendar date = Calendar.getInstance();

		System.out.println(date.get(Calendar.YEAR) + "�� " + (date.get(Calendar.MONTH)+1) + "�� " + date.get(Calendar.DATE) + "��");

		date.clear();
		// Calendar ��ü�� ���� �� �� clear �� �Ŀ� ����ؾ��Ѵ�.
		System.out.println(date.get(Calendar.YEAR) + "�� " + (date.get(Calendar.MONTH)+1) + "�� " + date.get(Calendar.DATE) + "��");
	}

}
