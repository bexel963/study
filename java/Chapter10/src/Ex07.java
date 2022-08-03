
import java.util.Calendar;

public class Ex07 {

	public static void main(String[] args) {

		if(args.length !=2) {
			System.out.println("Usage : java EX06_Calendar 2022 2");
			return;
		}
		int year = Integer.parseInt(args[0]);
		int month = Integer.parseInt(args[1]);
		
		Calendar sDay = Calendar.getInstance();
		Calendar eDay = Calendar.getInstance();
		
		// 시작일 설정
		sDay.set(year, month-1, 1);
		
		// 말일 설정
		eDay.set(year, month-1, sDay.getActualMaximum(Calendar.DATE));
		
		// 1일이 속한 주의 일요일로 날짜설정
		sDay.add(Calendar.DATE, -sDay.get(Calendar.DAY_OF_WEEK) + 1);
		System.out.println(sDay.get(Calendar.DATE));
		// 말일이 속한 주의 토요일로 날짜설정
		eDay.add(Calendar.DATE, 7-eDay.get(Calendar.DAY_OF_WEEK));
		System.out.println(eDay.get(Calendar.DATE));
		
		System.out.println("      " + year + "년 " + month + "월");
		System.out.println(" SU MO TU WE TH FR SA");
		
		// 시작일부터 마지막일까지(sDay <= eDay) 1일씩 증가시키면서 일(Calendar.DATE)을 출력
		for(int n=1 ; sDay.before(eDay) || sDay.equals(eDay) ; sDay.add(Calendar.DATE, 1)) {
			
			int day = sDay.get(Calendar.DATE);
			System.out.print((day<10) ? "  "+day : " " + day);
			if(n++%7==0)
				System.out.println();
		}
	}

}
