package gram02;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Ex13_DateFormat {
    public static void main(String[] args) {

        Calendar cal = Calendar.getInstance();
        cal.set(2005, 9, 3);

        // Calendar -> Date
        // Date 인스턴스만 format메서드에 사용될 수 있다.
        Date day = cal.getTime();

        SimpleDateFormat sdf1, sdf2, sdf3, sdf4;
        sdf1 = new SimpleDateFormat("yyyy-MM-dd");
        sdf2 = new SimpleDateFormat("yy-MM-dd E요일");
        sdf3 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
        sdf4 = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss a");

        System.out.println(sdf1.format(day));
        System.out.println(sdf2.format(day));
        System.out.println(sdf3.format(day));
        System.out.println(sdf4.format(day));

        System.out.println("\n---------------------------------\n");

        DateFormat df = new SimpleDateFormat("yyyy년 MM월 dd일");
        DateFormat df2 = new SimpleDateFormat("yyyy-MM-dd");

        try {
            Date d = df.parse("2015년 11월 23일");
            System.out.println(df2.format(d));
        } catch (Exception e) { }
        /*
            - Integer의 parseInt()가 문자열을 정수로 변환하는 것처럼 SimpleDateFormat의 parse(String s)는 문자열 s 를 날짜 Date인스턴스로 변환해준다.
            - 사용자로부터 날짜 데이터를 문자열로 입력받을 때, 입력받은 문자열을 날짜로 인식하기 위해서 substring()으로 년, 월, 일을 뽑아내야 하는데,
              parse()를 사용하면 이러한 수고를 덜어준다.
            - parse(String s)는 SimpleDateFormat의 조상인 DateFormat에 정의되어 있다.
            - 지정된 형식과 입력된 형식이 일치하지 않는 경우에는 예외가 발생하므로 적절한 예외 처리가 필요하다.
        */

    }
}









