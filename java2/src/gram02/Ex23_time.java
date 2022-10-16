package gram02;

import java.time.LocalDate;
import java.time.LocalTime;

public class Ex23_time {
    public static void main(String[] args) {

        /*
            - of()는 여러 가지 버전이 제공된다.
                static LocalDate of(int year, Month month, int dayOfMonth)
                static LocalDate of(int year, int month, int dayOfMonth)
                static LocalTime of(int hour, int min)
                static LocalTime of(int hour, int min, int sec)
                static LocalTime of(int hour, int min, int sec, int nanoOfSecond)
        */
        LocalDate today = LocalDate.now();
        LocalTime now = LocalTime.now();
        System.out.println(today);
        System.out.println(now);
        LocalDate birthDate = LocalDate.of(1990, 1, 15);
        LocalTime birthTime = LocalTime.of(23, 59, 59);
        System.out.println(birthDate);
        System.out.println(birthTime);
        LocalDate lDate = LocalDate.ofYearDay(1999, 365);   // 1999년의 마지막 날
        LocalTime lTime = LocalTime.ofSecondOfDay(86399);                 // 하루는 86400초
        System.out.println(lDate);
        System.out.println(lTime);
        LocalDate lDate2 = LocalDate.parse("1999-12-31");
        LocalTime lTime2 = LocalTime.parse("23:59:59");
        System.out.println(lDate2);
        System.out.println(lTime2);
    }
}
