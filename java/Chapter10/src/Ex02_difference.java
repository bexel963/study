
import java.util.Calendar;

public class Ex02_difference {

	public static void main(String[] args) {
		
		final String[] DAY_OF_WEEK = {"", "일", "월", "화", "수", "목", "금", "토"};
		
		Calendar date1 = Calendar.getInstance();
		Calendar date2 = Calendar.getInstance();
		
		date1.set(2022, 1, 1);	// 2022.2.1
		
		System.out.println("date1은 " + toString(date1) + DAY_OF_WEEK[date1.get(Calendar.DAY_OF_WEEK)] + "요일이고, ");
		System.out.println("오늘(date2)은 " + toString(date2) + DAY_OF_WEEK[date2.get(Calendar.DAY_OF_WEEK)] + "요일 입니다.");
		
		// 두 날짜의 차이를 얻으려면, getTimeInMillis() 천분의 일초 단위로 변환해야한다.
		long difference = (date2.getTimeInMillis() - date1.getTimeInMillis()) / 1000;
		
		System.out.println("그 날(date1)부터 지금(date2)까지 " + difference + "초가 지났습니다.");
		System.out.println("일(day)로 계산하면 " + difference/(24*60*60) + "일 입니다.");

	}
	
	public static String toString(Calendar date) {
		return date.get(Calendar.YEAR)+"년 " + date.get(Calendar.MONTH)+"월 " + date.get(Calendar.DATE)+"일 ";
	}
}
