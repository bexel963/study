package gram02;

import java.sql.SQLOutput;
import java.time.LocalDate;
import java.time.LocalTime;
import java.time.temporal.ChronoField;
import java.time.temporal.ChronoUnit;

/*
    - 특정 필드의 값 가져오기 - get(), getXX()
    <LocalDate, LocalTime의 필드의 값을 반환하는 메서드> - 1999-12-31 23:59:59
    - LocalDate클래스
        int getYear()               : 년도(1999)
        int getMonthValue()         : 월(12)
        Month getMonth()            : 월(DECEMBER)  getMonth().getValue()=12
        int getDayOfMonth()         : 일(31)
        int getDayOfYear()          : 같은 해의 1월 1일부터 몇번째 일(365)
        DayOfWeek getDayOfWeek()    : 요일(FRIDAY) getDayOfWeek().getValue()=5
        int lengthOfMonth()         : 같은 달의 총 일수(31)
        int lengthOfYear()          : 같은 해의 총 일수(365), 윤년이면 366
        boolean isLeapYear()        : 윤년여부 확인(false)
    - LocalTime
        int getHour()               : 시(23)
        int getMinute()             : 분(59)
        int getSecond()             : 초(59)
        int getNano()               : 나노초(0)

    <get() 사용시 매개변수로 사용할 수 있는 필드의 목록 - 열거형 ChronoField에 정의된 상수 목록>
        ERA                                 : 시대
        YEAR_OF_ERA, YEAR                   : 년
        MONTH_OF_YEAR                       : 월
        DAY_OF_WEEK                         : 요일(1:월요일, 2:화요일, ...., 7:일요일)
        DAY_OF_MONTH                        : 일
        AMPM_OF_DAY                         : 오전/오후
        HOUR_OF_DAY                         : 시간(0~23)
        CLOCK_HOUR_OF_DAY                   : 시간(1~24)
        HOUR_OF_AMPM                        : 시간(0~11)
        CLOCK_HOUR_OF_AMPM                  : 시간(1~12)
        MINUTE_OF_HOUR                      : 분
        SECOND_OF_MINUTE                    : 초
        MILLI_OF_SECOND                     : 천분의 일초
        DAY_OF_YEAR                         : 그 해의 몇 번째 날
        EPOCH_DAY                           : EPOCH(1970.1.1)부터 몇 번째 날
        MINUTE_OF_DAY                       : 그 날의 몇 번째 분(시간을 분으로 환산)
        SECOND_OF_DAY                       : 그 날의 몇 번째 초(시간을 초로 환산)
        MILLI_OF_DAY                        : 그 날의 몇 번째 밀리초
        ALIGNED_WEEK_OF_MONTH               : 그 달의 n번째 주(1~7일 1주, 8~14 2주, ...)
        ALIGNED_WEEK_OF_YEAR                : 그 해의 n번째 주
        ALIGNED_DAY_OF_WEEK_IN_MONTH        : 요일(그 달의 1일을 월요일로 간주하여 계산)
        ALIGNED_DAY_OF_WEEK_IN_YEAR         : 요일(그 해의 1월 1일을 월요일로 간주하여 계산)
        INSTANT_SECONDS                     : 년월일을 초단위로 환산(1970.01.01 00:00:00 UTC를 0초로 계산) instant에만 사용 가능
        OFFSET_SECONDS                      : UTC와의 시차, ZoneOffset에만 사용 가능
        PROLEPTIC_MONTH                     : 년월일을 월단위로 환산(2015년11월 = 2015*12+11)

    <열거형 ChronoUnit에 정의된 상수 목록>
        FOREVER             : Long.MAX_VALUE초(약 3천억년)
        ERAS                : 1,000,000,000년
        MILLENNIA           : 1,000년
        CENTURIES           : 100년
        DECADES             : 10년
        YEARS               : 년
        MONTHS              : 월
        WEEKS               : 주
        DAYS                : 일
        HALF_DAYS           : 반나절
        HOURS               : 시
        MINUTES             : 분
        SECONDS             : 초
        MILLIS              : 천분의 일초

    <필드 값 변경하기 - with(), plus(), minus()>
        LocalDate withYear(int year)
        LocalDate withMonth(int month)
        LocalDate withDayOfMonth(int dayOfMonth)
        LocalDate withDayOfYear(int dayOfYear)

        LocalTime withHour(int hour)
        LocalTime withMinute(int minute)
        LocalTime withSecond(int second)
        LocalTime withNano(int nanoOfSecond)

        LocalDate with(TemporalField field, long newValue)

    <필드 값 변경하기 - plus(), minus()>
        LocalDate plusYears(long yearsToAdd)
        LocalDate plusMonth(long monthToAdd)
        LocalDate plusDays(long daysToAdd)
        LocalDate plusWeeks(long weeksToAdd)

        LocalTime plusHours(long hoursToAdd)
        LocalTime plusMinutes(long minutesToAdd)
        LocalTime plusSeconds(long secondToAdd)
        LocalTime plusNanos(long nanosToAdd)

        LocalTime plus(TemporalAmount amountToAdd)
        LocalTime plus(long amountToAdd, TemporalUnit unit)
        LocalDate plus(TemporalAmount amountToAdd)
        LocalDate plus(long amountToAdd, TemporalUnit unit)

    <날짜와 시간의 비교> - isAfter(), isBefore(), isEqual()
        boolean isAfter(ChronoLocalDate other)
        boolean isBefore(ChronoLocalDate other)
        boolear isEqual(ChronoLocalDate other)
    * equlas()는 모든 필드가 일치해야 하지만, isEqual()은 오직 날짜만 비교한다.


*/
public class Ex24_time {
    public static void main(String[] args) {

        LocalDate today = LocalDate.now();
        LocalTime time = LocalTime.now();
//        System.out.println(today.get(ChronoField.MINUTE_OF_HOUR));  // 예외 발생 - 해당 클래스가 지원하지 않는 필드를 사용

        // 특정 필드의 범위 알아내기 - range()
        System.out.println(ChronoField.CLOCK_HOUR_OF_DAY.range());      // 밤 12시를 24로 표현
        System.out.println(ChronoField.HOUR_OF_DAY.range());            // 밤 12시를 0으로 표현

        System.out.println(today);
        LocalDate Dset = today.withYear(2023);
        System.out.println("#### " + Dset);
        System.out.println(Dset.withMonth(11));
        System.out.println(Dset.withDayOfMonth(5));
        System.out.println(Dset.withDayOfYear(3));


        System.out.println("------------------------------");

        System.out.println(time);
        LocalTime tSet = time.withHour(8);
        System.out.println("#### " + tSet);
        System.out.println(tSet.withMinute(22));
        System.out.println(tSet.withSecond(30));
        System.out.println(tSet.withNano(20));

        System.out.println("------------------------------");

        LocalTime t = LocalTime.of(12, 34, 56);
        t = t.truncatedTo(ChronoUnit.HOURS);    // 시(hour)보다 작은 단위를 0으로 변경 (LocalDate에는 truncatedTo()가 없다.)
        System.out.println(t);

        System.out.println("\n-----------------------------------------\n");

        LocalDate currDay = LocalDate.now();
        LocalTime currNow = LocalTime.now();

        LocalDate birthDate = LocalDate.of(1990, 1, 15);
        LocalTime birthTime = LocalTime.of(23, 59, 59);

        System.out.println("currDay = " + currDay);
        System.out.println("currNow = " + currNow);
        System.out.println("birthDate = " + birthDate);
        System.out.println("birthTime = " + birthTime);

        System.out.println(birthDate.withYear(2000));
        System.out.println(birthDate.plusDays(1));
        System.out.println(birthDate.plus(1, ChronoUnit.DAYS));
        System.out.println(birthTime.truncatedTo(ChronoUnit.HOURS));

    }
}
















