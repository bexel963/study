package gram02;

import java.text.SimpleDateFormat;
import java.util.Date;

/*
    - DateFormat은 추상클래스로 SimpleDateFormat의 조상이다.
    - DateFormat의 인스턴스를 생성하기 위해서는 getDateInstance()와 같은 static메서드를 이용해아한다.
    - getDateInstance()에 의해서 반환되는 것은 DateFormat을 상속받아 완전하게 구현한 SimpleDateFormat인스턴스이다.
*/
public class Ex12_DateFormat {
    public static void main(String[] args) {

        Date today = new Date();

        SimpleDateFormat sdf1, sdf2, sdf3, sdf4, sdf5, sdf6, sdf7, sdf8, sdf9;

        sdf1 = new SimpleDateFormat("yyyy-MM-dd");
        sdf2 = new SimpleDateFormat("''yy년 MMM dd일 E요일");
        sdf3 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
        sdf4 = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss a");

        sdf5 = new SimpleDateFormat("오늘은 올 해의 D번째 날 입니다.");
        sdf6 = new SimpleDateFormat("오늘은 이 달의 d번째 날 입니다.");
        sdf7 = new SimpleDateFormat("오늘은 올 해의 w번째 날 입니다.");
        sdf8 = new SimpleDateFormat("오늘은 이 달의 W번째 날 입니다.");
        sdf9 = new SimpleDateFormat("오늘은 이 달의 F번째 E요일 입니다.");

        System.out.println(sdf1.format(today));
        System.out.println(sdf2.format(today));
        System.out.println(sdf3.format(today));
        System.out.println(sdf4.format(today));
        System.out.println();
        System.out.println(sdf5.format(today));
        System.out.println(sdf6.format(today));
        System.out.println(sdf7.format(today));
        System.out.println(sdf8.format(today));
        System.out.println(sdf9.format(today));
    }
}
