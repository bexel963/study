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
public class Main {
    public static void main(String[] args) {

        Specifier sf = new Specifier();
        sf.print1();
        sf.print2();
    }
}
