package gram13_Time;

import java.text.DecimalFormat;

public class Ex10_DecimalFormat {
    public static void main(String[] args) {

        double number = 1234567.89;
        String[] pattern = {
                "0", "#", "0.0", "#.#", "0000000000.0000", "##########.####", "#.#-", "-#.#", "#,###.##", "#,####.##",
                "#E0", "0E0", "##E0", "00E0", "####E0", "0000E0", "#.#E0", "0.0E0", "0.00000000000E0", "00.00000000E0", "000.0000000E0",
                "#,###.##+;#.###.##-", "#.#%", "#.#\u2030", "\u00A4 #.###", "'#'#,###", "''#,###"
        };

        for(int i=0 ; i<pattern.length ; i++) {
            DecimalFormat df = new DecimalFormat(pattern[i]);
            System.out.printf("%19s : %s\n", pattern[i], df.format(number));
        }
        System.out.println("\n-----------------------------------\n");

        DecimalFormat df = new DecimalFormat("#,###");
        System.out.println(df.format(1000000));

        System.out.println("\n-----------------------------------\n");

        DecimalFormat df2 = new DecimalFormat("#,###.##");
        DecimalFormat df3 = new DecimalFormat("#,###E0");

        try {
            Number num = df.parse("1,2,3,4,567.89");
            System.out.print("1,234,567.89 -> ");

            double d = num.doubleValue();
            System.out.print(d + " - ");

            System.out.println(df2.format(num));
        } catch (Exception e) { }
        /*
            - parse()를 이용하면 기호와 문자가 포함된 문자열을 숫자로 변환할 수 있다.
              (Integer.parseInt() 는 콤마(,)가 포함된 문자열을 숫자로 변환할 수 없다.)
            - parse()는 DeciamlFormat의 조상인 NumberFormat에 정의되어있다.
                public Number parse(String source) throws ParseException
            - Number클래스는 Integer, Double과 같은 숫자를 저장하는 래퍼 클래스의 조상이다.
            - doubleValue()는 Number에 저장된 값을 double형으로 변환하여 반환한다.
              이 외에도 intValue(), floatValue()등의 메서드가 Number클래스에 정의되어있다.
        */
    }
}













