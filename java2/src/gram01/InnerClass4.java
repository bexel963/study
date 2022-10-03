package gram01;

class OuterClass4 {
    class InstanceInner {
        int iv = 100;
    }
    static class StaticInner {
        int iv = 200;
        static int cv = 300;
    }
    void myMethod() {
        class LocalInner {
            int iv = 400;
        }
    }
}
public class InnerClass4 {
    public static void main(String[] args) {
        // 인스턴스클래스의 인스턴스를 생성하려면 외부 클래스의 인스턴스를 먼저 생성해야 한다.
        OuterClass4 outer = new OuterClass4();
        OuterClass4.InstanceInner li = outer.new InstanceInner();

        System.out.println("li.iv = " + li.iv);
        System.out.println("OuterClass4.Static.cv = " + OuterClass4.StaticInner.cv);

        // 스태틱 내부 클래스의 인스턴스는 외부 클래스를 먼저 생성하지 않아도 된다.
        OuterClass4.StaticInner si = new OuterClass4.StaticInner();
        System.out.println("si.iv = " + si.iv);
    }
}
