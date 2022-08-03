
import java.util.Calendar;

public class Ex05 {

	public static void main(String[] args) {

		// roll은 add와 달리 다른 필드에 영향을 미치지 않는다.
		// 예외) - 일이 말일이고 월에 roll을 수행하면 일 필드에 영향을 미칠 수도 있다.
		Calendar date = Calendar.getInstance();
		
		date.set(2022, 0, 31);
		System.out.println(toString(date));
		date.roll(Calendar.MONTH, 1);	// 2월에는 31일이 없기 때문에 자동으로 28일로 세팅된다.
		System.out.println(toString(date));
	}

	public static String toString(Calendar date) {
		return date.get(Calendar.YEAR)+"년 " + (date.get(Calendar.MONTH)+1)+"월 " + date.get(Calendar.DATE)+"일 ";
	}
}
