package gram07_Class;
/*
    - 내부 클래스에서 외부 클래스의 멤버들을 쉽게 접근할 수 있다.
    - 캡슐화
    - 내부 클래스는 외부 클래스를 제외하고는 다른 클래스에서 잘 사용되지 않는 것이어야함.
    - 인스턴스 클래스 : 주로 외부 클래스의 인스턴스 멤버들과 관련된 작업에 사용될 목적으로 선언됨.
    - 스태틱 클래스 : 주로 외부 클래스의 static멤버, 특히 static메서드에서 사용될 목적으로 선언
*/
class OuterClass {
    class InstanceInner {
        int iv = 100;
//        static int cv = 100;          // static변수 선언 x
        final static int CONST = 100;   // 상수는 가능
    }
    static class StaticInner {
        int iv = 200;
        static int cv = 200;
    }
    void method() {
        class LocalInner {
            int iv = 300;
            //            static int cv = 300;     // static변수 선언 x
            final static int CONST = 300;
        }
    }
}
public class InnerClass {
    public static void main(String[] args) {
        OuterClass oc = new OuterClass();
        OuterClass.InstanceInner ii = oc.new InstanceInner();

        System.out.println(ii.CONST);
        System.out.println(OuterClass.StaticInner.cv);
    }
}
