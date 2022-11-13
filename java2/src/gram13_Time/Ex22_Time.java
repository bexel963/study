package gram13_Time;

import java.time.*;
import java.time.temporal.ChronoField;
import java.time.temporal.ChronoUnit;

/*
    - java.time 패키지
        <클래스>
            <Temporal, TemporalAccessor, TemporalAdjuster 인터페이스를 구현>
            - LocalDate
            - LocalTime
            - LocalDateTime
            - ZonedDateTime
            <TemporalAmount 인터페이스를 구현>
            - Period        : 날짜 ~ 날짜
            - Duration      : 시간 ~ 시간

        <객체 생성>
        - now()
        - of()

        <TemporalUnit 인터페이스>
        - 날짜와 시간의 단위를 정의해 놓은 것
        <ChronoUnit 열거형>
        - TemporalUnit을 열거형으로 구현한 것

        <TemporalField 인터페이스>
        - 년, 월, 일 등 날짜와 시간의 필드를 정의해 놓은 것
       <ChronoField 열거형>
       - TemporalField를 열거형으로 구현한 것
*/
public class Ex22_Time {
    public static void main(String[] args) {

        LocalDate date = LocalDate.now();
        LocalTime time = LocalTime.now();
        LocalDateTime dateTime = LocalDateTime.now();
        ZonedDateTime dateTimeInKr = ZonedDateTime.now();

        LocalDate date2 = LocalDate.of(2015, 11, 23);
        LocalTime time2 = LocalTime.of(23, 59, 59);
        LocalDateTime dateTime2 = LocalDateTime.of(date2, time);
        ZonedDateTime zDateTime = ZonedDateTime.of(dateTime, ZoneId.of("Asia/Seoul"));

        System.out.println(date);
        System.out.println(time);
        System.out.println(dateTime);
        System.out.println(dateTimeInKr);
        System.out.println("----------------------");
        System.out.println(date2);
        System.out.println(time2);
        System.out.println(dateTime2);
        System.out.println(zDateTime);

        System.out.println("\n---------------------------------------------\n");

        LocalTime now = LocalTime.now();
        int minute = now.getMinute();
        int minute2 = now.get(ChronoField.MINUTE_OF_HOUR);  // 위 문장과 동일

        LocalDate today = LocalDate.now();
        LocalDate tomorrow = today.plus(1, ChronoUnit.DAYS);
        LocalDate tomorrow2 = today.plusDays(1);    // 위 문장과 동일

        System.out.println(now);
        System.out.println(minute);
        System.out.println(minute2);
        System.out.println("----------------");
        System.out.println(tomorrow);
        System.out.println(tomorrow2);

        /*
            - get(), plus()의 정의
                int get(TemporalField field)
                LocalDate plus(long amountToAdd, TemporalUnit unit)
            - TemporalField나 TemporalUnit을 사용할 수 있는지 확인하는 메서드
                boolean isSupported(TemporalUnit unit)
                boolean isSupported(TemporalField field)
        */
    }
}

















