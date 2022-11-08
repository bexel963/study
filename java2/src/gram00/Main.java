package gram00;
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

class Etc {

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
    }
}
public class Main {
    public static void main(String[] args) {

        Specifier sf = new Specifier();
        sf.print1();
        sf.print2();
        Char ch = new Char();
        ch.print1();
        Etc etc = new Etc();
        etc.func1();
    }
}
