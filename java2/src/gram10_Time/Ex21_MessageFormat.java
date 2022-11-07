package gram10_Time;

import java.io.File;
import java.text.MessageFormat;
import java.util.Scanner;

public class Ex21_MessageFormat {
    public static void main(String[] args) throws Exception{

        String tableName = "CUST_INFO";
        String fileName = "data4.txt";
        String msg = "INSERT INTO " + tableName + " VALUES (''{0}'', ''{1}'', ''{2}'', ''{3}'');";

        Scanner s = new Scanner(new File(fileName));

        String pattern = "{0}, {1}, {2}, {3}";
        MessageFormat mf = new MessageFormat(pattern);

        while(s.hasNextLine()) {
            String line = s.nextLine();
            Object[] ojbs = mf.parse(line); // 문자열을 MessageFormat으로 변경
            System.out.println(MessageFormat.format(msg, ojbs));
        }
        s.close();
    }
    /*
        - 이전의 예제에서는 데이터를 객체배열에 직접 초기화하였는데, 그렇게 하면 데이터가 바뀔 때마다 매번 배열을 변경해야하고 다시 컴파일을 해줘야하므로 불편하다.
          이러한 불편함을 없애기 위해 Scanner를 통해 파일로부터 데이터를 라인별로 읽어서 처리하도록 변경하였다.
          이렇게 파일로부터 데이터를 제공받으면 데이터가 변경되어도 다시 컴파일을 하지 않아도 된다.
    */
}
