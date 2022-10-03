package gram02;

import java.util.Calendar;

public class Ex04_Calendar {
    public static void main(String[] args) {

        Calendar date = Calendar.getInstance();
        date.set(2022, 8, 25);
        System.out.println(toString(date));

        System.out.println("= 1일 후 =");
        date.add(Calendar.DATE, 1);
        System.out.println(toString(date));

        System.out.println("= 6달 전 =");
        date.add(Calendar.MONTH, -6);
        System.out.println(toString(date));

        System.out.println("= 31일 후(add) =");
        date.add(Calendar.DATE, 31);
        System.out.println(toString(date));

        System.out.println("= 31일 후(roll) =");
        // roll()은 add()와 달리 다른 필드에 영향을 미치지 않는다.
        // 예외) 일 필드가 말일 일 때, roll()로 월 필드를 변경하면 일 필드에 영향을 미칠 수 있다.
        date.roll(Calendar.DATE, 31);
        System.out.println(toString(date));

        date.set(2015, 0, 31);
        System.out.print(toString(date));
        date.roll(Calendar.MONTH, 1);
        System.out.println(toString(date));


    }

    public static String toString(Calendar date) {
        String print = String.format("%d년 %d월 %d일 \n",
                date.get(Calendar.YEAR), date.get(Calendar.MONTH)+1, date.get(Calendar.DATE));
        return print;
    }
}
