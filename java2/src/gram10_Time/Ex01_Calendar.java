package gram10_Time;

import java.util.Calendar;

public class Ex01_Calendar {
    public static void main(String[] args) {
        // Calendar는 추상 클래스, Date클래스의 다음 버전.
        // getInstance()로 얻은 인스턴스는 기본적으로 현재 시스템의 날짜와 시간에 대한 정보를 담고 있다.
        Calendar today = Calendar.getInstance();
        System.out.println("이 해의 년도 : " + today.get(Calendar.YEAR));
        System.out.println("월(0~11, 0:월) : " + today.get(Calendar.MONTH));
        System.out.println("이 해의 몇 번 째 주 : " + today.get(Calendar.WEEK_OF_YEAR));
        System.out.println("이 달의 몇 번 째 주 : " + today.get(Calendar.WEEK_OF_MONTH));
        System.out.println("이 달의 몇 일 : " + today.get(Calendar.DATE));
        System.out.println("이 해의 몇 번 째 일 : " + today.get(Calendar.DAY_OF_YEAR));
        System.out.println("이 달의 몇 번 째 일 : " + today.get(Calendar.DAY_OF_MONTH));
        System.out.println("요일(1~7, 1:일요일) : " + today.get(Calendar.DAY_OF_WEEK));
        System.out.println("이 달의 몇 번 째 요일 : " + today.get(Calendar.DAY_OF_WEEK_IN_MONTH));

        System.out.println();

        System.out.println("오전_오후(0:오전, 1:오후) " + today.get(Calendar.AM_PM));
        System.out.println("시간(0~11) : " + today.get(Calendar.HOUR));
        System.out.println("시간(0~23) : " + today.get(Calendar.HOUR_OF_DAY));
        System.out.println("분(0~59) : " + today.get(Calendar.MINUTE));
        System.out.println("초(0~59) : " + today.get(Calendar.SECOND));
        System.out.println("1000분의 1초(0~999) : " + today.get(Calendar.MILLISECOND));
        // 천분의 1초를 시간으로 표시하기 위해 3600000로 나눔.
        System.out.println("Timezone(-12 ~ +12) : " + (today.get(Calendar.ZONE_OFFSET)/(60*60*1000)));

        System.out.println("이 달의 마지막 날 : " + today.getActualMaximum(Calendar.DATE));
    }
}
