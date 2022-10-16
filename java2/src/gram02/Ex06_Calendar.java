package gram02;

import java.util.Calendar;

// 달력
public class Ex06_Calendar {
    public static void main(String[] args) {
        
        int year = 2022;
        int month = 10;
        int START_DAY_OF_WEEK = 0;
        int END_DAY = 0;
        
        Calendar sDay = Calendar.getInstance();
        Calendar eDay = Calendar.getInstance();
        
        sDay.set(year, month-1, 1);   // 해당 달의 시작일
        eDay.set(year, month, 1);           // 다음달 1일
        eDay.add(Calendar.DATE, -1);      // 해당 달의 마지막일 (다음달 1일에서 1일 빼기 => 전달 마지막 일) 
        
        START_DAY_OF_WEEK = sDay.get(Calendar.DAY_OF_WEEK); // 첫 번째 요일 알아내기
        END_DAY = eDay.get(Calendar.DATE);                  // 마지막 일 얻어오기

        String title = String.format("      < %d년  %d월 >\n   일  월  화  수  목  금  토", year, month);
        System.out.println(title);

        for(int i=0 ; i<START_DAY_OF_WEEK ; i++) {
            System.out.print("   ");
        }
        System.out.print("   ");
        for(int i=1, n=START_DAY_OF_WEEK ; i<END_DAY ; i++, n++) {
            System.out.print((i<10) ? "   "+i : "  "+i);
            if(n % 7 == 0) {
                System.out.println();
            }
        }
        
    }
}
