package gram01;

class OuterClass2 {

    class InstanceInner { }
    static class StaticInner { }

    InstanceInner iv = new InstanceInner();
    StaticInner cv = new StaticInner();

    public static void staticMethod() {
//        InstanceInner obj1 = new InstanceInner();   // static멤버는 인스턴스멤버에 직접 접근 x
        StaticInner obj2 = new StaticInner();

        // 굳이 접근하려면 아래와 같이 객체를 생성해야 한다.
        // 인스턴스 클래스는 외부 클래스를 먼저 생성해야만 생성할 수 있다.
        OuterClass2 outer = new OuterClass2();
        InstanceInner obj1 = outer.new InstanceInner();
    }
    public void instanceMethod() {
        // 인스턴스 메서드에서는 인스턴스 멤버와 static 멤버 모두 접근 가능하다.
        InstanceInner obj1 = new InstanceInner();
        StaticInner obj2 = new StaticInner();
//        LocalInner lv = new LocalInner();   // 메서드 내에 지역적으로 선언된 내부 클래스는 외부에서 접근 x
    }
    public void myMethod() {
        class LocalInner { }
        LocalInner iv = new LocalInner();
    }
}

public class InnerClass2 {
    public static void main(String[] args) {

    }
}
