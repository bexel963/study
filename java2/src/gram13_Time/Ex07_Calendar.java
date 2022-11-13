package gram13_Time;

import java.util.Calendar;
// 첫 주와 마지막 주가 이전, 이후 달과 연결되는 달력
public class Ex07_Calendar {
    public static void main(String[] args) {

        int year = 2022;
        int month = 10;

        Calendar sDay = Calendar.getInstance();
        Calendar eDay = Calendar.getInstance();
        sDay.set(year, month-1, 1);
        eDay.set(year, month-1, sDay.getActualMaximum(Calendar.DATE));  // 말일 설정

        // 1일이 속한 주의 일요일로 날짜 설정                 -7 + 1
        System.out.println(sDay.get(Calendar.DATE));
        System.out.println(sDay.get(Calendar.DAY_OF_WEEK));
        sDay.add(Calendar.DATE, -sDay.get(Calendar.DAY_OF_WEEK) + 1);   // 9월 25일
        System.out.println(sDay.get(Calendar.DATE));
        // 말일이 속한 주의 토요일로 날짜 설정
        eDay.add(Calendar.DATE, 7 -eDay.get(Calendar.DAY_OF_WEEK));     // 11월 5일

        String title = String.format("      < %d년  %d월 >\n   일  월  화  수  목  금  토", year, month);
        System.out.println(title);

        for(int n=1 ; sDay.before(eDay) || sDay.equals(eDay) ; sDay.add(Calendar.DATE, 1)) {
            int day = sDay.get(Calendar.DATE);
            System.out.print((day<10) ? "   " + day : "  " + day);
            if(n++%7==0) {
                System.out.println();
            }
        }
    }
}
