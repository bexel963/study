package gram02;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class Ex15_DateFormat {
    public static void main(String[] args) {

        String pattern = "yyyy-MM-dd";
        DateFormat df = new SimpleDateFormat(pattern);
        Scanner scan = new Scanner(System.in);

        Date inDate = null;

        System.out.println("날짜를 " + pattern + "의 형태로 입력해주세요.(ex:2015-12-31)");

        while(scan.hasNextLine()) {
            try {
                inDate = df.parse(scan.nextLine());
                break;
            } catch(Exception e) {
                System.out.println("날짜 형식이 맞지 않습니다. 확인해주세요.");
            }
        }
        Calendar cal = Calendar.getInstance();
        cal.setTime(inDate);
        Calendar today = Calendar.getInstance();

        long diff = Math.abs((cal.getTimeInMillis() - today.getTimeInMillis()))/(60*60*1000);
        System.out.println("입력하신 날짜는 현재와 " + diff + "시간 차이가 있습니다.");
    }
}
