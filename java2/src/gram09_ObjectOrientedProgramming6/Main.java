package gram09_ObjectOrientedProgramming6;


import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/*
    - 내부 클래스
        1) 내부 클래스에서 외부 클래스의 멤버들을 쉽게 접근할 수 있다.
        2) 코드의 복잡성을 줄일 수 있다. (캡슐화)
        : 내부 클래스는 그 클래스의 외부 클래스를 제외하고는 다른 클래스에서 잘 사용되지 않는 것이어야 한다.
        : 내부 클래스의 유효범위와 성질은 멤버 변수와 유사하다.
        : 내부 클래스는 외부 클래스의 멤버와 같이 간주되고, 인스턴스멤버와 static멤버 간의 규칙이 내부 클래스에도 똑같이 적용된다.
        : 내부 클래스도 클래스이기 때문에 abstract, final과 같은 제어자를 사용할 수 있고, 멤버변수들 처럼 private, protected과
          접근 제어자도 사용이 가능하다.
        : 내부 클래스를 가지고 있는 클래스를 컴파일 했을 때 생성되는 파일명은 "외부 클래스명$내부 클래스명.class" 형식이다.
*/
class Outer1 {
    class InstanceInner {
        int iv = 100;
        //static int cv = 100;            // ERROR. static변수를 선언할 수 없다.
        final static int CONST = 100;     // final static은 상수이므로 가능.
    }
    static class StaticInner {
        int iv = 200;
        static int cv = 200;    // static클래스만 static멤버를 정의할 수 있다.
    }
    void method() {
        class LocalInner {
            int iv = 300;
            //static int cv = 300;            // ERROR. static변수를 선언할 수 없다.
            final static int CONST = 300;     // final static은 상수이므로 가능.
        }
    }
}
class InnerClassTest1 {
    void test() {
        System.out.println(Outer1.InstanceInner.CONST);    // 100
        System.out.println(Outer1.StaticInner.cv);         // 200
    }
}

/*
    - 인스턴스 멤버는 같은 클래스에 있는 인스턴스 멤버와 static멤버 모두 직접 호출이 가능하지만, static멤버는 인스턴스 멤버를 직접
      호출할 수 없는 것처럼, 인스턴스 클래스는 외부 클래스의 인스턴스 멤버를 객체생성 없이 바로 사용할 수 있지만,
      스태틱 클래스는 외부 클래스의 인스턴스 멤버를 객체생성 없이 사용할 수 없다.
      마찬가지로 인스턴스 클래스는 스태틱 클래스의 멤버들을 객체생성 없이 사용할 수 있지만, 스태틱 클래스에서는 인스턴스 클래스의
      멤버들을 객체생성 없이 사용할 수 없다.
*/
class Outer2 {
    class InstanceInner {

    }
    static class StaticInner {

    }
    InstanceInner iv = new InstanceInner();     // 인스턴스 멤버 간에는 서로 접근이 가능하다.
    static StaticInner cv = new StaticInner();  // 스태틱 멤버 간에는 서로 접근이 가능하다.

    static void staticMethod() {
        //InstanceInner obj1 = new InstanceInner();           // ERROR. static멤버는 인스턴스멤버에 직접 접근할 수 없다.
        StaticInner obj2 = new StaticInner();
        Outer2 outer = new Outer2();                          // 인스턴스클래스는 외부 클래스를 먼저 생성해야만 생성할 수 있다.
        InstanceInner obj1 = outer.new InstanceInner();       // 굳이 접근하려면 객체를 생성해야 한다.
    }
    void instanceMethod() {
        // 인스턴스메서드에서는 인스턴스멤버와 static멤버 모두 접근 가능하다.
        InstanceInner obj1 = new InstanceInner();
        StaticInner obj2 = new StaticInner();
        //LocalInner lv = new LocalInner();       // 메서드 내에 지역적으로 선언된 내부 클래스는 외부에서 접근할 수 없다.
    }
    void myMethod() {
        class LocalInner{ }
        LocalInner lv = new LocalInner();
    }
}
class Outer3 {
    private int outerIv = 0;
    static int outerCv = 0;

    class InstanceInner {
        int iiv = outerIv;  // 외부 클래스의 private멤버도 접근 가능하다.
        int iiv2 = outerCv;
    }
    static class StaticInner {
        //int siv = outerIv;  // 스태틱 클래스는 외부 클래스의 인스턴스멤버에 접근할 수 없다.
        static int scv = outerCv;
    }
    void myMethod() {
        int lv = 0;
        final int LV = 0;   // JDK1.8 부터 final 생략 가능. - 컴파일러가 자동으로 붙여준다.

        class LocalInner {
            int liv = outerIv;
            int liv2 = outerCv;
            int liv3 = lv;
            int liv4 = LV;
        }
    }
}

/*
    - 외부 클래스가 아닌 다른 클래스에서도 내부 클래스를 생성하고 내부 클래스의 멤버에 접근할 수 있다.
*/
class Outer4 {
    class InstanceInner {
        int iv = 100;
    }
    static class StaticInner {
        int iv = 200;
        static int cv = 300;
    }
    void myMethod() {
        class LocalInner {
            int iv = 300;
        }
    }
}
class InnerClassTest2 {
    void test() {
        // 내부 인스턴스 클래스의 인스턴스 멤버에 접근 (내부 인스턴스 클래스에는 스태틱 멤버를 선언할 수 없다.)
        Outer4 oc = new Outer4();
        Outer4.InstanceInner ii = oc.new InstanceInner();
        System.out.println("ii.iv : " + ii.iv);

        // 내부 스태틱 클래스의 스태틱 멤버에 접근
        System.out.println("Outer4.StaticInner.cv : " + Outer4.StaticInner.cv);

        // 내부 스태틱 클래스의 인스턴스 멤버에 접근
        Outer4.StaticInner si = new Outer4.StaticInner();
        System.out.println("si.iv : " + si.iv);
    }
}

/*
    - 익명 클래스
        : 클래스의 선언과 객체의 생성을 동시에 하기 때문에 단 한번만 사용될 수 있고 오직 하나의 객체만을 생성할 수 있는 일회용 클래스이다.
        : 이름이 없기 때문에 생성자도 가질 수 없으며, 조상클래스의 이름이나 구현하고자 하는 인터페이스의 이름을 사용해서 정의하기 때문에
          하나의 클래스로 상속받는 동시에 인터페이스를 구현하거나 둘 이상의 인터페이스를 구현할 수 없다.
          오로지 단 하나의 클래스를 상속 받거나 단 하나의 인터페이스만을 구현할 수 있다.
        : 익명 클래스는 이름이 없기 때문에 "외부 클래스명$숫자.class"의 형식으로 클래스 파일명이 결정된다.
*/
class Outer5 {
    Object iv = new Object() {
        void method() {

        }
    };
    static Object cv = new Object() {
        void method() {

        }
    };
    void myMethod() {
        Object lv = new Object() {
            void method() {

            }
        };
    }
}

class EventHandler implements ActionListener {
    public void actionPerformed(ActionEvent e) {
        System.out.println("ActionEvent occurred!!");
    }
}
class AnonymousTest {
    void test() {
        Button b = new Button("Start");
        b.addActionListener(new EventHandler());        // 1. 일반 클래스의 인스턴스를 매개변수로 넘겨준다.
    }
}
public class Main {
    public static void main(String[] args) {
        Button b = new Button("Start");
        b.addActionListener(new ActionListener() {      // 2. 익명클래스를 매개변수로 넘겨준다.
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("ActionEvent occurred!!!");
            }
        });
    }
}
