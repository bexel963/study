
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Ex14 {

	public static void main(String[] args) {

		// 문자열을 날짜Date인스턴스로 변환
		DateFormat df = new SimpleDateFormat("yyyy년 MM월 dd일");
		DateFormat df2 = new SimpleDateFormat("yyyy/MM/dd");
		
		try {
			Date d = df.parse("2015년 11월 23일");
			System.out.println(df2.format(d));
		}catch(Exception e) {
			e.printStackTrace();
		}
	}

}
