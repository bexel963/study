package gram01_Operator;

/*
    - 산술변환
        : 연산 수행 직전에 발생하는 피연산자의 자동 형변환.
        : 두 피연산자의 타입을 같게 일치시킨다.(보다 큰 타입으로 일치 - 값 손실 방지)
        : 피연산자의 타입이 int보다 작은 타입이면 int로 변환된다.
*/
class Operator {

    void func1() {

        byte a = 10;
        byte b = 20;
        byte c = (byte)(a + b); // byte는 int형 보다 작기 때문에 연산자 '+'는 이 두개의 피연산자들의 자료형을 int형으로 변환한 후 연산을 수행한다.
        byte d = (byte)(a * b); // d=44, 데이터 손실 발생

        int i1 = 1_000_000;
        int i2 = 2_000_000;
        long l = i1 * i2;           // l=-1454759936, 두 수의 연산 결과가 오버플로우되었기 때문에 이 후 long형으로 자동 형변환 되어도 값은 변하지 않는다.
        long l2 = (long)i1 * i2;    // 이렇게 해야 올바른 값이 나온다.

        long l3 = 1_000_000 * 1_000_000;    // l3=-727379968, 위와 같은 이유로 올바른 값이 나오지 않음
        long l4 = 1_000_000 * 1_000_000L;   // 이렇게 해야 올바른 값이 나온다.

        int n = 1000000;
        int result1 = a * a / a;    // -727
        int result2 = a / a * a;    // 1000000

        char c1 = 'a';
        char c2 = 'd';
        char zero = '0';
        char two = '2';

        int result3 = c2 - c1;      // char형은 int형 보다 작기 때문에 연산 시 연산자에 의해 int형으로 변환된다.
        int result4 = two - zero;   // 이 개념으로 문자 '2'를 숫자로 바꾸려 할 때 문자 '0'을 빼주면 된다. (아스키 코드에서 0~9는 연속된 코드로 배치되어있기 때문에 가능.)

        // '0': 48, 'A': 65, 'a': 97
        char c3 = 'a';
        char c4 = c3;
        char c5 = ' ';
        int i = c1 + 1;         // 98
        c5 = (char)(c1 + 1);    // 덧셈의 결과가 int이므로 이 결과를 char형 변수에 담으려면 char형으로 형변환이 필요하다.

        char c6 = 'a' + 1;      // 상수 또는 리터럴 간의 연산은 실행 과정동안 변하는 값이 아니다. 컴파일러가 미리 덧셈연산을 수행하기 때문에 이 코드는 OK이다.
    }

    void func2() {

        // 소수점 3번째 까지 빼내기
        float pi = 3.141592f;
        pi = (int)(pi * 1000) / (float)1000;
        System.out.println(pi);
        // 소수점 4번째 자리에서 반올림하기
        pi = 3.141592f;
        pi = (int)(pi * 1000 + 0.5) / (float)1000;
        System.out.println(pi);
        // round() 사용해서 반올림하기
        double d = 3.141592;
        d = Math.round(pi * 1000) / 1000.0; // round()는 매개변수로 받은 값을 소수점 첫째자리에서 반올림 하고 그 결과를 '정수'로 돌려준다.
        System.out.println(pi);
    }
    /*
        - 나머지 연산자
            : 나누는 수로 0을 사용할 수 없다.
            : 나누는 수로 음수도 허용한다. 그러나 부호는 무시됨.
    */
    void func3() {
        float f = 0.1f;
        double d = 0.1;
        double d2 = (double)f;

        // 10.0f는 오차없이 저장할 수 있는 값이라서 double로 형변환해도 그대로 10.0이다.
        System.out.printf("10.0==10.0f %b\n", 10.0==10.0f); // true

        // 0.1f는 저장할 때 2진수로 변환하는 과정에서 오차가 발생한다.
        // double타입의 상수인 0.1도 저장되는 과정에서 오차가 발생하지만, float타입의 리터럴인 0.1f보다 적은 오차로 저장된다.
        System.out.printf("0.1==0.1f %b\n", 0.1==0.1f);     // false
        System.out.printf("f = %19.17f\n", f);
        System.out.printf("d = %19.17f\n", d);

        // float타입의 값을 double타입으로 형변환하면, 부호와 지수는 달라지지 않고 그저 가수의 빈자리를 0으로 채울 뿐이므로,
        // 0.1f를 double타입으로 형변환해도 그 값은 전혀 달라지지 않는다.
        // 즉, float타입의 값을 정밀도가 더 높은 double타입으로 형변환했다고 해서 오차가 적어지지는 않는 것이다.
        System.out.printf("d2 = %19.17f\n", d2);

        System.out.printf("d==f %b\n", d==f);                 // false
        System.out.printf("d==d2 %b\n", d==d2);               // false
        System.out.printf("d2==f %b\n", d2==f);               // true

        // float타입의 값과 double타입의 값을 비교하려면 double타입의 값을 float타입으로 형변환한 다음에 비교해야한다.
        System.out.printf("(float)d==f %b\n", (float)d==f);   // true
    }
    /*
        - 연산자 우선순위
            : '&&' 가 '||' 보다 우선순위가 높다.
    */
}
public class Main {
    public static void main(String[] args) {

        Operator op = new Operator();
        op.func2();
    }
}














