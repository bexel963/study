package gram13_Time;

/*
    <윤년>
    - 자연의 흐름에 대해서 생길 수 있는 오차를 보정하기 위해 삽입하는 날이나 주, 달이 들어가는 해
    - 그레고리력에서 여분의 하루인 2월 29일을 추가하여 1년동안 날짜의 수가 366일이 되는 해
    - 4로 나누어 떨어지는 해는 윤년, 그 밖의 해는 평년으로 한다.
    - 그레고리력은 예외규칙 추가
        - 100으로 나누어 떨어지되 400으로 나누어 떨어지지 않는 해는 평년으로 한다.
*/
public class Ex09_Calendar {
    public static void main(String[] args) {

        System.out.println("2022. 9. 25 : " + getDayOfWeek(2022, 9, 25) + "요일");
        System.out.println("2011. 12. 6 : " + getDayOfWeek(2011, 12, 6) + "요일");

        int current = convertDateToday(2022, 9, 25);
        String currentC = convertDayToDate(current);
        int discharge = convertDateToday(2011, 12, 6);
        String dischargeC = convertDayToDate(discharge);
        int diff = current - discharge;
        String diffC = convertDayToDate(diff);

        System.out.println(current);
        System.out.println(discharge);
        System.out.println(diff);
        System.out.println(dayDiff(2022, 9, 25, 2011, 12, 6));
        System.out.println("-----------------------");
        System.out.println(currentC);
        System.out.println(dischargeC);
        System.out.println(diffC);
    }
    public static int[] endOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public static boolean isLeapYear(int year) {
        return ((year%4==0)&&(year%100!=0)||(year%400==0));
    }
    public static int dayDiff(int y1, int m1, int d1, int y2, int m2, int d2) {
        return convertDateToday(y1, m1, d1) - convertDateToday(y2, m2, d2);
    }
    // 년월일 -> 일
    public static int convertDateToday(int year, int month, int day) {
        int numOfLeapYear = 0;
        for(int i=1 ; i<year ; i++) {
            if(isLeapYear(i)) {
                numOfLeapYear++;
            }
        }
        // 전년도까지의 일수 구하기
        int toLastYearDaySum = (year-1) * 365 + numOfLeapYear;
        // 올해의 현재 월까지의 일수 구하기
        int thisYearDaySum = 0;

        for(int i=0 ; i<month-1 ; i++) {
            thisYearDaySum += endOfMonth[i];
        }
        if(month>2 && isLeapYear(year)) {
            thisYearDaySum++;
        }
        thisYearDaySum += day;

        return toLastYearDaySum + thisYearDaySum;
    }
    // 지정한 날짜의 요일 반환. (1~7)
    public static int getDayOfWeek(int year, int month, int day) {
        return convertDateToday(year, month, day) % 7 + 1;
    }
    // 일 -> 년 월 일
    public static String convertDayToDate(int day) {
        int year = 1;
        int month = 0;
        while(true) {
            int aYear = isLeapYear(year) ? 366 : 365;
            if(day > aYear) {
                day -= aYear;
                year++;
            } else {
                break;
            }
        }
        while(true) {
            int endDay = endOfMonth[month];
            if(isLeapYear(year) && month==1) {
                endDay++;
            }
            if(day > endDay) {
                day -= endDay;
                month++;
            } else {
                break;
            }
        }

        return year + "-" + (month+1) + "-" + day;
    }

}
