
import java.util.Calendar;

public class Ex05 {

	public static void main(String[] args) {

		// roll�� add�� �޸� �ٸ� �ʵ忡 ������ ��ġ�� �ʴ´�.
		// ����) - ���� �����̰� ���� roll�� �����ϸ� �� �ʵ忡 ������ ��ĥ ���� �ִ�.
		Calendar date = Calendar.getInstance();
		
		date.set(2022, 0, 31);
		System.out.println(toString(date));
		date.roll(Calendar.MONTH, 1);	// 2������ 31���� ���� ������ �ڵ����� 28�Ϸ� ���õȴ�.
		System.out.println(toString(date));
	}

	public static String toString(Calendar date) {
		return date.get(Calendar.YEAR)+"�� " + (date.get(Calendar.MONTH)+1)+"�� " + date.get(Calendar.DATE)+"�� ";
	}
}
