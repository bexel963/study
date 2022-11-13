package gram13_Time;

public class Ex08_Calendar {
    public static void main(String[] args) {
        String date1 = "202209";
        String date2 = "201403";

        int month1 = Integer.parseInt(date1.substring(0,4)) * 12
                   + Integer.parseInt(date1.substring(4));
        int month2 = Integer.parseInt(date2.substring(0,4)) * 12
                   + Integer.parseInt(date2.substring(4));

        String diff = String.format("%s과 %s의 차이는 %d개월 입니다. ", date1, date2, Math.abs(month1-month2));

        System.out.println(diff);

        // 년, 월 정도의 계산이면 굳이 Calendar를 사용 안 해도 이렇게 할 수도 있다.
    }
}
