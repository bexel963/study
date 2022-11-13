package gram13_Time;

import java.text.MessageFormat;

/*
    - 데이터를 정해진 양식에 맞게 출력할 수 있도록 도와줌
    - 데이터가 들어갈 자리를 마련해 놓은 양식을 미리 작성하고 프로그램을 이용해서 다수의 데이터를 같은 양식으로 출력할 때 사용하면 좋다.
    ex) 고객들에게 보낼 안내문을 출력할 때 같은 안내문 양식에 받는 사람의 이름과 같은 데이터만 달라지도록 출력할 때, 또는 하나의 데이터를 다양한 양식으로
        출력할 때 사용한다.
    - {숫자}로 표시도니 부분이 데이터가 출력될 자리이고, String이외에 다른 객체들이 지정될 수도 있다.
*/
public class Ex18_MessageFormat {
    public static void main(String[] args) {

        String msg = "Name: {0} \nTel: {1} \nAge: {2} \nBirthDay: {3}";

        Object[] arguments = { "이자바", "02-123-1234", "27", "07-09" };

        String result = MessageFormat.format(msg, arguments);

        System.out.println(result);
    }
}
