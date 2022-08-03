
import java.util.Calendar;
import java.util.Date;

public class Ex00 {

	public static void main(String[] args) {

		Calendar date = Calendar.getInstance();

		System.out.println(date.get(Calendar.YEAR) + "년 " + (date.get(Calendar.MONTH)+1) + "월 " + date.get(Calendar.DATE) + "일");

		date.clear();
		// Calendar 객체를 생성 후 꼭 clear 한 후에 사용해야한다.
		System.out.println(date.get(Calendar.YEAR) + "년 " + (date.get(Calendar.MONTH)+1) + "월 " + date.get(Calendar.DATE) + "일");
	}

}
