package gram00_Variable;
/*
    - 자료형은 값이 저장될 공간의 크기와 저장형식을 정의한 것.
    - 자바에서는 클래스의 이름이 참조변수의 타입이 된다. (변수의 타입이 기본형이 아닌 것들은 모두 참조변수이다.)
    - 참조형 변수(4byte or 8byte)는 객체의 주소(0x0 ~ 0xFFFFFFFF)를 값으로 갖는다. (32bit JVM에서)
    - 자료형 vs 타입
        : 보통 자료형은 기본형을 구분할 때 사용하고, 타입은 참조형 변수의 종류를 구분할 때 사용한다.
        : 타입이 자료형을 포함하는 넓은 의미이다.
    - boolean(1), char(2), byte(1), short(2), int(4), long(8), float(4)(7자리), double(8)(15자리)
    - char는 문자를 내부적으로 정수(유니코드)로 저장한다.
    - 리터럴의 타입과 접미사
        : 접미사가 없으면 int타입의 리터럴이다. (byte와 short타입의 리터럴은 별도로 존재하지 않으며 byte와 short타입의 변수에 값을 저장할 때는 int타입의 리터럴을 사용한다.)
        : 접미사 l 또는 L 은 long타입의 리터럴이다.
        : 접미사 f 또는 F 는 float타입의 리터럴이다.
        : 접미사 d 또는 D 는 double타입의 리터럴이다. (실수형에서는 double이 기본 자료형이라서 접미사 'd'는 생략 가능하다.)
    - 타입의 불일치
        : 저장 범위가 넓은 타입의 자료형 변수에 좁은 타입의 리터럴을 저장하는 것은 허용.
            int i = 'A';     long l = 123;      double d = 3.14f;
        : 반대는 안 됨.
            int i = 0x123456789;    float f = 3.14;
        : byte, short타입의 리터럴은 따로 존재하지 않으므로 int타입의 리터럴을 사용. 단, short타입의 변수가 저장할 수 있는 범위에 속하는 것이어야 한다.

*/
class Specifier {

    byte b = 1;
    short s = 2;
    char c = 'A';

    int finger = 10;
    long big = 100_000_000_000L;
    long hex = 0xFFFF_FFFF_FFFF_FFFFL;

    int octNum = 010;
    int hexNum = 0x10;
    int binNum = 0b10;

    void print1() {
        System.out.printf("b=%d\n", b);
        System.out.printf("s=%d\n", s);
        // C언어 에서는 char타입의 값을 지시자 '%d'로 출력할 수 있지만, 자바에서는 안 됨. int타입으로 형 변환 해야 '%d'로 출력 가능.
        System.out.printf("c=%c, %d \n", c, (int)c);
        System.out.printf("finger=[%5d]\n", finger);    // [   10]
        System.out.printf("finger=[%-5d]\n", finger);   // [10   ]
        System.out.printf("finger=[%05d]\n", finger);   // [00010]
        System.out.printf("big=%d\n", big);
        System.out.printf("hex=%#x\n", hex);    // 0xffffffffffffffff - '#'은 접두사(16진수 0x, 8진수 0)
        System.out.printf("hex=%#X\n", hex);    // 0XFFFFFFFFFFFFFFFF - '#'은 접두사(16진수 0x, 8진수 0)
        System.out.printf("octNum=%o, %d\n", octNum, octNum);   // 10, 8
        System.out.printf("hexNum=%x, %d\n", hexNum, hexNum);   // 10, 16
        // 10진수를 2진수로 출력하는 지시자 없어서 메서드 사용해야함.
        System.out.printf("binNum=%s, %d\n", Integer.toBinaryString(binNum), binNum);   // 10, 2

        System.out.println();
    }
    String url = "www.codechobo.com";

    float f1 = .10f;    // 0.10
    float f2 = 1e1f;    // 10.0
    float f3 = 3.14e3f;
    double d = 1.23456789;

    void print2() {
        System.out.printf("f1=%f, %e, %g\n", f1, f1, f1);
        System.out.printf("f2=%f, %e, %g\n", f2, f2, f2);
        System.out.printf("f3=%f, %e, %g\n", f3, f3, f3);

        System.out.printf("d=%f\n", d);
        System.out.printf("d=%14.10f\n", d);    // 14자리로 출력하는데, 그 중 소수점 이하가 10자리를 차지한다.

        System.out.println("[12345678901234567890]");
        System.out.printf("[%s]\n", url);
        System.out.printf("[%20s]\n", url);     // 20자리로 출력하는데, 글자 수가 20자리 미만이면 오른쪽 정렬.
        System.out.printf("[%-20s]\n", url);    // 왼쪽 정렬.
        System.out.printf("[%.8s]\n", url);     // 8번째 까지만 잘라서 출력

        System.out.println();
    }
}
// 문자형
class Char {

    void print1() {
        char ch = 'A';
        int code = (int)ch;

        System.out.printf("%c = %d(%#X)\n", ch, code, code);    // A = 65(0X41)

        char hch = '가';
        System.out.printf("%c = %d(%#X)\n", hch, (int)hch, (int)hch);   // 가 = 44032(0XAC00)

        char ch2 = 65;
        short s = 65;
        // println()은 변수의 타입이 정수형이면 변수에 저장된 값을 10진수로 해석하여 출력하고, 문자형이면 저장된 숫자에 해당하는 유니코드 문자를 출력한다.
        System.out.println(ch2);    // A
        System.out.println(s);      // 65

        System.out.println();

    }
}
/*
    - 아스키(ASCII - American Standard Code for Information Interchange
        : 128개(2^7)의 문자 집합을 제공하는 7bit 부호
        : 1~32개     - 인쇄와 전송 제어용으로 사용되는 제어문자
        : 1개        - , 마지막 문자(DEL)
        : 그 이후     - '0~9', 'A~Z', 'a~z' 가 연속적으로 배치되어있음.

    - 확장 아스키(Extended ASCII)와 한글
        : 일반적으로 데이터는 byte단위로 다뤄지는데 아스키는 7bit이므로 1bit가 남음. 이 남는 공간을 활용해서 문자를 추가로 정의한 것이 '확장 아스키'
        : 확장 아스키에 추가된 128개의 문자는 여러 국가와 기업에서 서로의 필요에 따라 다르게 정의해서 사용한다.
        : 확장 아스키로 표현할 수 있는 문자의 개수는 255개 -> 한글을 표현하기에는 부족.

    - 한글을 표현하는 방법
        : 조합형 - 초성, 중성, 종성을 조합하는 방식
        : 완성형 - 확장 아스키의 일부 영역(162~254)에 해당하는 두 문자코드를 조합하여 한글을 표현
        : 현재 조합형은 사용되지 않고 '완성형(KSC 5601)'에 없는 잘 안 쓰이는 8822글자를 추가한 '확장 완성형(CP 949)'이 사용된다.
        : 한글 윈도우에서 작성된 문서는 기본적으로 'CP949'로 인코딩되어 저장된다.

    - 유니코드(Unicode)
        : 확장 아스키는 pc를 사용하는 지역이나 국가에 따라 여러 버전이 필요했다.
        : 전 세계의 모든 문자를 하나의 통일된 문자집합으로 표현 가능한 것이 유니코드이다.
        : 처음엔 모든 문자를 2byte(65536)로 표현하려 했으나, 부족해서 21bit(약 200만 문자)로 확장 되었다.
        : 새로 추가된 문자들을 보충 문자라고 한다.
        : 유니코드는 먼저 유니코드에 포함시키고자 하는 문자들의 집합을 정의하였는데, 이것을 유니코드 문자 셋(또는 캐릭터 셋)이라고 한다.
        : 그리고 이 문자 셋에 번호를 붙인 것이 유니코드 인코딩이다.
        : 유니코드 인코딩에는 UTF-8, UTF-16, UTF-32등 여러 가지가 있는데 자바에서는 UTF-16을 사용한다.
        : UTF-8  - 하나의 문자를 1~4byte의 가변크기로 표현
                   (영문과 숫자는 1byte, 그리고 한글은 3byte로 표현되기 때문에 문소의 크기가 작다.)
        : UTF-16 - 모든 문자를 2byte의 고정 크기로 표현
                   (1byte로 표현할 수 있는 영어와 숫자가 2byte로 표현되므로 문서의 크기가 커진다.)
        : UTF-8, UTF-16 두 인코딩 모두 처음 128문자가 아스키와 동일하다.
*/

// 정수형
/*
    - 정수형의 표현형식과 범위
        : 어떤 진법의 리터를을 변수에 저장해도 실제로는 2진수로 바뀌어 저장된다.
        : 모든 정수형은 부호있는 정수이므로 왼쪽의 첫 번째 비트를 '부호 비트'로 사용하고, 나머지는 값을 표현하는데 사용한다.
        : n비트로 표현할 수 있는 정수의 개수             -   2^n개 = 2^(n-1)개 + 2^(n-1)개
        : n비트로 표현할 수 있는 부호있는 정수의 범위     -   -2^(n-1) ~ 2^(n-1)-1

    - char 와 short의 표현 범위 (표현 개수는 2^(16)개 - 65536개)
        : short -    -2^(15) ~ 2^(15)-1 (-32768 ~ 32767)
        : char  -    0 ~ 2^(16)-1 (0 ~ 65535)

    - 정수형의 선택 기준
        : JVM의 피연산자 스택이 피연산자를 4byte단위로 저장하기 때문에 크기가 4byte보다 작은 자료형의 값을 계산할 때는 4byte로 변환하여 연산이 수행된다.
          그래서 byte,short 보다 int를 사용하는 것이 더 효율적이다.
*/

class Overflow {

    void func1() {
        short sMin = -32768;
        short sMax = 32767;
        char cMin = 0;
        char cMax = 65535;

        System.out.println("sMin   = " + sMin);                 // sMin   = -32768
        System.out.println("sMin-1 = " + (short)(sMin-1));      // sMin-1 = -32769
        System.out.println("sMax   = " + sMax);                 // sMax   = 32767
        System.out.println("sMax+1 = " + (short)(sMax+1));      // sMax+1 = -32768
        System.out.println("cMin   = " + (int)cMin);            // cMin   = 0
        System.out.println("cMin-1 = " + (int)--cMin);          // cMin-1 = 65535
        System.out.println("cMax   = " + (int)cMax);            // cMax   = 65535
        System.out.println("cMax+1 = " + (int)++cMax);          // cMax+1 = 0
        System.out.println();
    }
}
/*
    - 실수형
        : 정수 타입은 부호와 값 두 부분으로 이루어져있지만, 실수 타입은 부호(S), 지수(E), 가수(M) 세 부분으로 이루어져 있다.
        : float의 정밀도는 7자리이고, double의 정밀도는 15자리 이다.
*/
class Float_Double {

    void func1() {
        float f = 9.12345678901234567890f;
        float f2 = 1.2345678901234567890f;
        double d = 9.12345678901234567890d;

        System.out.printf("      123456789012345678901234\n");
        // printf()의 %f는 기본적으로 소수점 이하 6자리까지만 출력하므로, 7번째 자리에서 반올림 된다.
        System.out.printf("f   :   %f\n", f);
        System.out.printf("f   : %24.20f\n", f);    // 위의 값이랑 7자리까지 같다.
        // 간혹 우연히 8자리 이상이 일치하는 경우도 있다.
        System.out.printf("f2  : %24.20f\n", f2);
        System.out.printf("d   : %24.20f\n", d);
        System.out.println();
    }
}
/*
    - 형변환
        : 변수 또는 상수의 타입을 다른 타입으로 변환하는 것
        : 기본형에서 boolean을 제외한 나머지 타입들은 서로 형변환이 가능하다.
        : 기본형과 참조형간의 형변환은 불가능하다.
        1) 정수형간의 형변환
        2) 실수형간의 형변환
        3) 정수형, 실수형 간의 형변환.
*/
class Casting {
    void func1() {
        int i = 10;
        byte b = (byte)i;
        System.out.printf("[int -> byte] i=%d -> b=%d\n", i, b);

        i = 300;
        b = (byte)i;
        System.out.printf("[int -> byte] i=%d -> b=%d\n", i, b);

        b = 10;
        i = (int)b;
        System.out.printf("[byte -> int] b=%d -> i=%d\n", b, i);

        b = -2;
        i = (int)b;
        System.out.printf("[byte -> int] b=%d -> i=%d\n", b, i);

        System.out.println("i = " + Integer.toBinaryString(i));

        System.out.println();
    }
    void func2() {
        float f = 9.1234567f;
        double d = 9.1234567;
        double d2 = (double)f;  // 한번 값이 저장되었으므로 형 변환 한다고 되돌아오지 않는다.

        System.out.printf("f  = %20.18f\n", f);
        System.out.printf("d  = %20.18f\n", d);
        System.out.printf("d2 = %20.18f\n", d2);

        System.out.println();
    }
    void func3() {
        /*
            - 정수형 -> 실수형
                : 실수형은 정수형보다 훨씬 큰 저장범위를 갖기 때문에, 정수형을 실수형으로 변환하는 것은 별 무리가 없다.
                  정수를 2진수로 변환한 다음 정규화해서 실수의 저장형식에 맞게 저장할 뿐이다.
                  한 가지 주의할 점은 실수형의 정밀도의 제한으로 인한 오차가 발생할 수 있는 것이다.
                  그래서 10진수로 8자리 이상의 값을 실수형으로 변환할 때는 float가 아닌 double로 형변환 해야한다.
            - 실수형 -> 정수형
                : 실수형을 정수형으로 변환하면, 실수형의 소수점 이하 값은 버려진다.
        */
        int i = 91234567;
        float f = (float)i;
        int i2 = (int)f;

        double d = (double)i;
        int i3 = (int)d;

        float f2 = 1.666f;
        int i4 = (int)f2;

        System.out.printf("i = %d\n", i);
        System.out.printf("f = %f   i2=%d\n", f, i2);
        System.out.printf("d = %f   i3=%d\n", d, i3);
        System.out.printf("(int)%f = %d\n", f2, i4);

        System.out.println();

        int j = 100;
        byte b = (byte)j;
    }
}
/*
    - 자동 형변환
        : 컴파일러는 기존의 값을 최대한 보존할 수 있는 타입으로 자동 형변환 한다.
        : 서로 다른 타입의 변수간의 연산은 형변환을 하는 것이 원칙이지만, 값의 범위가 작은 타입에서 큰 타입으로의 형변환은 생략할 수 있다.
        : 변수가 저장할 수 있는 값의 범위보다 더 큰 값을 저장하려는 경우 형변환을 생략하면 에러가 발생한다. (큰 타입에서 작은 타입으로 형변환 시)
          그러나 명시적으로 형변환을 해줬을 경우, 형변환이 프로그래머의 실수가 아닌 의도적인 것으로 간주하고 컴파일러는 에러를 발생시키지 않는다.
        ex)
        float f = 1234;         // OK
        byte b = 1000;          // 에러
        byte b = (byte)1000;    // OK
        char ch = (char)1000;   // OK

        byte b = 100;           // OK
        byte b = (byte)100;     // OK

        int i = 100;            // OK
        byte b = i;             // Error - 컴파일러가 타입만 알고 값은 몰라서...
        byte b = (byte)i;       // OK
*/
public class Main {
    public static void main(String[] args) {

        Specifier sf = new Specifier();
        sf.print1();
        sf.print2();
        Char ch = new Char();
        ch.print1();
        Overflow etc = new Overflow();
        etc.func1();
        Float_Double fd = new Float_Double();
        fd.func1();
        Casting cst = new Casting();
        cst.func1();
        cst.func2();
        cst.func3();
    }
}
