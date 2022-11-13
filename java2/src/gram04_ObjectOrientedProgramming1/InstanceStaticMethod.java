package gram04_ObjectOrientedProgramming1;

class MemberCall {
    int iv = 10;
    static int cv = 20;

    int iv2 = cv;                             // 인스턴스 변수는 클래스변수 사용 가능.
//    static int cv3 = iv;                    // ERROR. 클래스변수는 인스턴스 변수 사용 못함.
    static int cv4 = new MemberCall().iv;     // 이렇게 객체를 생성해야 사용 가능.

    static void staticMethod1() {
        System.out.println(cv);
//        System.out.println(iv);     // ERROR. 클래스 메서드에서 인스턴스변수 사용 못함.
        MemberCall c = new MemberCall();
        System.out.println(c.iv);   // 이렇게 객체를 생성한 후에 인스턴스변수 참조 가능
    }
    void instanceMethod1() {
        System.out.println(cv);
        System.out.println(iv);
    }
    static void staticMethod2() {
        staticMethod1();
//        instanceMethod1();                // ERROR. 클래스 메서드에서는 인스턴스 메서드 호출 못함.
        MemberCall c = new MemberCall();
        c.instanceMethod1();                // 이렇게 객체를 생성한 후에 인스턴스메서드 호출 가능.
        new MemberCall().instanceMethod1(); // 이렇게도 가능.
    }
    void instanceMethod2() {
        instanceMethod1();
        staticMethod1();
    }
}
class MyMath {

    long a, b;

    // 인스턴스 변수 a, b 만을 이용해서 작업하므로 매개변수가 필요없다.
    long add() { return a + b; }
    long sub() { return a - b; }
    long mul() { return a * b; }
    long div() { return a / b; }

    // 인스턴스변수와 관계없이 매개변수만으로 작업이 가능하다.
    static long add(long a, long b) { return a + b; }
    static long sub(long a, long b) { return a - b; }
    static long mul(long a, long b) { return a * b; }
    static long div(long a, long b) { return a / b; }
}
public class InstanceStaticMethod {
    public static void main(String[] args) {

        MyMath mm = new MyMath();
        mm.a = 200L;
        mm.b = 100L;
        System.out.println(mm.add());
        System.out.println(mm.sub());
        System.out.println(mm.mul());
        System.out.println(mm.div());

        System.out.println(MyMath.add(200L, 100L));
        System.out.println(MyMath.sub(200L, 100L));
        System.out.println(MyMath.mul(200L, 100L));
        System.out.println(MyMath.div(200L, 200L));
    }
}
