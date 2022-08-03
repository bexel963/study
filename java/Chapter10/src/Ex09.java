
public class Ex09 {

	public static int[] endOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	public static void main(String[] args) {

		System.out.println("2014. 5. 31 : " + getDayOfWeek(2014, 5, 31));
		System.out.println("2012. 6. 1 : " + getDayOfWeek(2012, 6, 1));
		System.out.println("2014. 5. 1 - 2014.4.28 : " + dayDiff(2014, 5, 1, 2014, 4, 28));
		System.out.println("2015. 6. 29 : " + convertDateToDay(2015, 6, 29) + "일");
		System.out.println("735778일 : " + convertDayToDate(735778));
	}
	

	// 윤년인지 알려주는 메소드
	public static boolean isLeapYear(int year) {
		return ((year%4==0)&&(year%100!=0)||(year%400==0));
	}
	// 두 날짜간의 차이를 일단위로 반환한다.
	public static int dayDiff(int y1, int m1, int d1, int y2, int m2, int d2) {
		return convertDateToDay(y1, m1, d1) - convertDateToDay(y2, m2, d2);
	}
	// 지정한 날짜의 요일을 반환한다.
	public static int getDayOfWeek(int year, int month, int day) {
		return convertDateToDay(year, month, day) % 7 + 1;
	}
	// 일단위의 값을 년월일의 형태의 문자열로 변환한다.
	public static String convertDayToDate(int day) {
		
		int year = 1;
		int month = 0;
		
		while(true) {
			int aYear = isLeapYear(year) ? 366 : 365;
			if(day > aYear) {
				day -= aYear;
				year++;
			}else {
				break;
			}
		}
		while(true) {
			int endDay = endOfMonth[month];
			if(isLeapYear(year)&&month==1)
				endDay++;
			if(day > endDay) {
				day -= endDay;
				month++;
			}else {
				break;
			}
		}
		return year + "-" + (month+1) + "-" + day;
	}
	// 년월일을 입력받아서 일단위로 변환한다. - 서기 1년 1월 1일부터 계산
	public static int convertDateToDay(int year, int month, int day) {
		
		int numOfLeapYear = 0;	// 윤년의 수
		
		for(int i=1 ; i<year ; i++) {
			if(isLeapYear(i))
				numOfLeapYear++;
		}
		
		int toLastYearDaySum = (year-1) * 365 + numOfLeapYear;
		
		int thisYearDaySum = 0;
		
		for(int i=0 ; i<month-1 ; i++)
			thisYearDaySum += endOfMonth[i];
		
		if(month >2 && isLeapYear(year))
			thisYearDaySum++;
		
		thisYearDaySum += day;
		
		return toLastYearDaySum + thisYearDaySum;
	}

}
