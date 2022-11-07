package gram10_Time;

import java.util.Calendar;

public class Ex02_Calendar {
    public static void main(String[] args) {

        final String[] DAY_OF_WEEK = { "", "일", "월", "화", "수", "목", "금", "토" };

        Calendar enter = Calendar.getInstance();
        Calendar current = Calendar.getInstance();

        enter.set(2022, 7, 25);

        String enterPrint = String.format("입사일 : %d년 %d월 %d일",
                enter.get(Calendar.YEAR), enter.get(Calendar.MONTH), enter.get(Calendar.DATE));
        String currentPrint = String.format("현재 : %d년 %d월 %d일 %s요일",
                current.get(Calendar.YEAR), current.get(Calendar.MONTH)+1, current.get(Calendar.DATE), DAY_OF_WEEK[current.get(Calendar.DAY_OF_WEEK)]);
        // 1/1000초로 변환
        long difference = (current.getTimeInMillis() - enter.getTimeInMillis()) / 1000;
        String diffSecond = String.format("근무 기간(초) : %d일", difference);
        String diffCalendar = String.format("근무 기간(일) : %d일", difference/(60*60*24));

        System.out.println(enterPrint);
        System.out.println(currentPrint);
        System.out.println(diffSecond);
        System.out.println(diffCalendar);
    }
}
