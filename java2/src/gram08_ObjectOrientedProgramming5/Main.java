package gram08_ObjectOrientedProgramming5;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane;

/*
    - 인터페이스
        : 모든 멤버변수는 public static final 이어야 하며, 이를 생량할 수 있다.
        : 모든 메서드는 public abstract이어야 하며, 이를 생략할 수 있다. (단, staitc메서드와 디폴트메서드는 예외)
        : 생략된 제어자는 컴파일 시에 컴파일러가 자동적으로 추가해준다.
        : 만일 구현하는 인터페이스의 메서드 중 일부만 구현한다면, abstract를 붙여서 추상클래스로 선언해야 한다.
        : 인터페이스는 상속 대신 구현이라는 용어를 사용하지만, 인터페이스로부터 상속받은 추상메서드를 구현하는 것이기 때문에
          인터페이스도 조금은 다른 의미의 조상이라고 할 수 있다.
        : 인터페이스를 구현한 클래스에서 인터페이스의 추상메서드를 오버라이딩 할 때는 오버라이딩 규칙에 의해 조상의 메서드 보다
          넓은 범위의 접근 제어자를 지정해야한다. (=> public으로 지정해야한다.)
*/
interface  Fightable extends Movable, Attackable { }
interface  Movable { void move(int x, int y); }
interface  Attackable { void attack(Unit_ u); }
class Unit_ {
    int currentHP;
    int x, y;
}
class Fighter extends Unit_ implements Fightable {
    @Override
    public void move(int x, int y) { /*구현*/ }
    @Override
    public void attack(Unit_ u) { /*구현*/ }
}
class FighterTest {
    void test() {
        Fighter f = new Fighter();

        if(f instanceof Unit_) System.out.println("f는 Unit클래스의 자손입니다.");                      // true
        if(f instanceof Fightable) System.out.println("f는 Fightable인터페이스를 구현했습니다..");       // true
        if(f instanceof Movable) System.out.println("f는 Movable인터페이스를 구현했습니다.");            // true
        if(f instanceof Attackable) System.out.println("f는 Attackable인터페이스를 구현했습니다.");      // true
        if(f instanceof Object) System.out.println("f는 Object클래스의 자손입니다.");                   // true
    }
}

/*
    - 인터페이스를 이용한 다중상속
        : 두 조상으로부터 상속받는 멤버 중에서 멤버변수의 이름이 같거나 메서드의 선언부가 일치하고 구현 내용이 다르다면 이 두 조상으로부터
          상속받는 자손클래스는 어느 조상의 것을 상속받게 되는 것인지 알 수 없다.
          그래서 두 개의 클래스로부터 상속을 받아야 할 상황이라면, 두 조상클래스 중에서 비중이 높은 쪽을 상속 받고 다른 한쪽은 클래스 내부에
          포함시키는 방식으로 처리하거나 어느 한쪽의 필요한 부분을 뽑아서 인터페이스로 만든 다음 구현하도록 한다.
*/
class Tv {
    protected boolean power;
    protected int channel;
    protected int volume;

    public void power() { power =! power; }
    public void channelUp() { channel++; }
    public void channelDown() { channel--; }
    public void volumeUp() { volume++; }
    public void volumeDown() { volume--; }
}
class VCR {
    protected int counter;

    public void play() {/*Tape재생*/}
    public void stop() {/*멈춤*/}
    public void reset() { counter = 0; }
    public int getcounter() { return counter; }
    public void setCounter(int c) { counter = c; }
}
interface IVCR {
    public void play();
    public void stop();
    public void reset();
    public int getcounter();
    public void setCounter(int c);
}
/*
    - TVCR클래스를 작성하기 위해 두 클래스(TV, IVCR)로부터 상속받을 수만 있으면 좋겠짐나 다중상속을 허용하지 않으므로, 한 쪽만 선택하여
      상속받고 나머지 한 쪽은 클래스 내에 포함시켜서 내부적으로 인스턴스를 생성해서 사용하도록 한다.
      IVCR인터페이스를 구현하기 위해서는 새로 메서드를 작성해야하는 부담이 있지만 이처럼 VCR클래스의 인스턴스를 사용하면 손쉽게 다중상속을 구현할 수 있다.
      또한 VCR클래스의 내용이 변경되어도 변경된 내용이 TVCR클래스에도 자동적으로 반영되는 효과도 얻을 수 있다.
      사실 인터페이스를 새로 작성하지 않고도 VCR클래스를 TVCR클래스에 포함시키는 것만으로도 충분하지만,
      인터페이스를 이용하면 다형적 특성을 이용할 수 있다는 장점이 있다.
*/
class TVCR extends Tv implements IVCR {
    VCR vcr = new VCR();    // VCR클래스 타입의 참조변수를 멤버변수로 선언하여 IVCR인터페이스의 추상메서드를 구현하는데 사용한다.

    @Override
    public void play() { vcr.play(); }  // 코드를 작성하는 대신 VCR인스턴스의 메서드를 호출한다.
    @Override
    public void stop() { vcr.stop(); }
    @Override
    public void reset() { vcr.reset(); }
    @Override
    public int getcounter() { return vcr.getcounter(); }
    @Override
    public void setCounter(int c) { vcr.setCounter(c); }
}

/*
    - 인터페이스를 이용한 다형성
        : 다형성은 자손클래스의 인스턴스를 조상타입의 참조변수로 참조하는 것이다.
          인터페이스 역시 이를 구현한 클래스의 조상이라 할 수 있으므로 해당 인터페이스 타입의 참조변수로 이를 구현한 클래스의 인스턴스를
          참조할 수 있으며, 인터페이스 타입으로의 형변환도 가능하다.
          => 인터페이스 타입의 매개변수가 갖는 의미는 메서드 호출 시 해당 인터페이스를 구현한 클래스의 인스턴스를 매개변수로 제공해야한다는 것이다.
          => 리턴타입이 인터페이스라는 것은 메서드가 해당 인터페이스를 구현한 클래스의인스턴스를 반환한다는 것을 의미한다.
*/
interface Parseable {
    public abstract void parse(String fileName);
}
class ParseManager {
    public static Parseable getParser(String type) {
        if(type.equals("XML")) {
            return new XMLParser();     // 만일 나중에 새로운 종류의 XML구문분석기 NewXMLPaser클래스가 나와도 ParserTest클래스는 변경할 필요 없이
                                        // 여기만 NewXMLPaser로 변경해주면 된다.
                                        // 이러한 장점은 분산환경 프로그래밍에서 위력을 발휘한다.
                                        //  - 사용자 컴퓨터에 설치된 프로그램을 변경하지 않고, 서버측의 변경만으로 사용자가 새로 개정된 프로그램을 사용하는 것이 가능하다.
        } else {
            Parseable p = new HTMLParser();
            return p;
        }
    }
}
class XMLParser implements Parseable {
    @Override
    public void parse(String fileName) {    // 접근제어자 public이어야 함.
        System.out.println(fileName + "- XML parsing completed");
    }
}
class HTMLParser implements Parseable {
    @Override
    public void parse(String fileName) {
        System.out.println(fileName + "- HTMLParser parsing completed");
    }
}
class ParserTest {
    void test() {
        Parseable parser = ParseManager.getParser("XML");   // new XMLParser()
        parser.parse("document.xml");
        parser = ParseManager.getParser("HTML");            // new HTMLParser()
        parser.parse("document2.html");
    }
}

/*
    - 인터페이스의 장점
        1) 개발시간을 단축시킬 수 있다.
            : 일단 인터페이스가 작성되면, 이를 사용해서 프로그램을 작성하는 것이 가능하다. 메서드를 호출하는 쪽에서는 메서드의 내용에 관계없이
              선언부만 알면 되기 때문이다.
              그리고 동시에 다른 한 쪽에서는 인터페이스를 구현하는 클래스를 작성하게 되면, 인터페이스를 구현하는 클래스가 작동될 때까지 기다리지 안고도
              양쪽에서 동시에 개발을 진행할 수 있다.
        2) 표준화가 가능하다.
            : 프로젝트에 사용되는 기본 틀을 인터페이스로 작성한 다음, 개발자들에게 인터페이스를 구현하여 프로그램을 작성하도록 함으로써 보다 일관되고
              정형화된 프로그램의 개발이 가능하다.
        3) 서로 관계없는 클래스들에게 관계를 맺어줄 수 있다.
            : 서로 상속관계에 있지도 않고, 같은 조상클래스를 가지고 있지 않은 서로 아무런 관계도 없는 클래스들에게 하나의 인터페이스를 공통적으로
              구현하도록 함으로써 관계를 맺어 줄 수 잇다.
        4) 독립적인 프로그래밍이 가능하다.
            : 클래스의 선언과 구현을 분리시킬 수 있기 때문에 실제구현에 독립적인 프로그램을 작성하는 것이 가능하다.
              클래스와 클래스간의 직접적인 관계를 인터페이스를 이용해서 간접적인 관계로 변경하면, 한 클래스의 변경이 관련된 다른 클래스에 영향을
              미치지 않는 독립적은 프로그래밍이 가능하다.
*/
/*
    - Unit  -   GroundUnit  - Marine
                            - SCV
                            - Tank
            -   AirUnit     - Dropship

    ==> 아무런 관련 없는 Tank, SCV, Dropshop을 interface로 묶어준다. (Repairable)
*/
interface  Repairable { }
class Unit {
    int hitPoint;
    final int MAX_HP;
    Unit(int hp) { MAX_HP = hp; }
}
class GroundUnit extends Unit {
    GroundUnit(int hp) { super(hp); }
}
class AireUnit extends Unit {
    AireUnit(int hp) { super(hp); }
}
class Tank extends GroundUnit implements Repairable {
    Tank() {
        super(150);
        hitPoint = MAX_HP;
    }
    public String toString() { return "Tank"; }
}
class Dropship extends AireUnit implements Repairable {
    Dropship() {
        super(125);
        hitPoint = MAX_HP;
    }
    public String toString() { return "Dropship"; }
}
class Marin extends GroundUnit {
    Marin() {
        super(40);
        hitPoint = MAX_HP;
    }
    public String toString() { return "Dropship"; }
}
class SCV extends GroundUnit implements Repairable {
    SCV() {
        super(60);
        hitPoint = MAX_HP;
    }
    void repair(Repairable r) {     // Repairable인터페이스를 구현한 클래스만 매개변수로 받을 수 있다.
        if(r instanceof Unit) {     // Repairable에 정의된 멤버가 없기 때문에 참조변수 r로는 할 수 있는 일은 아무것도 없다. => Unit타입으로 형변환 해준다.
            Unit u = (Unit)r;
            while(u.hitPoint != u.MAX_HP) {
                u.hitPoint++;
            }
            System.out.println(u.toString() + "의 수리가 끝났습니다.");
        }
    }
}

/*
    - 인터페이스의 이해
        : 클래스를 사용하는 쪽(user)과 클래스를 제공하는 쪽(Provider)이 있다.
        : 메서드를 사용(호출)하는 쪽(user)에서는 사용하려는 메서드(Provider)의 선언부만 알면 된다. (내용은 몰라도 됨.)
*/
/*
        class A {
            void methodA(B b) {
                b.methodB();
            }
        }
        class B {
            void methodB() {
                System.out.println("MethodB()");
            }
        }
        class InterfaceTest {
            void test() {
                A a = new A();
                a.methodA(new B());
            }
        }
        => 이와 같이 직접적인 관계의 두 클래스는 한 쪽(Provider-B)이 변경되면 다른 한 쪽(User-A)도 변경되어야 한다는 단점이 있다.
           그러나 클래스 A가 클래스 B를 직접 호출하지 않고 인터페이스를 매개체로 해서 클래스 A가 인터페이스를 통해서 클래스 B의 메서드에
           접근하도록 하면, 클래스 B에 변경사항이 생기거나 클래스 B와 같은 기능의 다른 클래스로 대체 되어도 클래스 A는 전혀 영향을
           받지 않도록 하는 것이 가능하다.
           두 클래스간의 관계를 간접적으로 변경하기 위해서는 먼저 인터페이스를 이용해서 클래스 B(Provider)의 선언과 구현을 분리해야 한다.
*/
/*
    - 클래스 A는 인터페이스를 통해 실제로 사용하는 클래스의 이름을 몰라도 되고 심지어는 실제로 구현된 클래스가 존재하지 않아도 문제되지 않는다.
      클래스 A는 오직 직접적인 관계에 있는 인터페이스 I의 영향만 받는다.
      (인터페이스 I는 실제 구현 내용(클래스 B)을 감싸고 있는 껍데기이며, 클래스 A는 껍데기 안에 어떤 알맹이(클래스)가 들어 있는지 몰라도 된다.
*/
class A {
    void autoPlay(I i) {    // 클래스 A를 작성하는데 클래스 B가 관련되지 않았다!!!
        i.play();
    }
}
interface I {
    public abstract void play();
}
class B implements I {
    public void play() {
        System.out.println("play in B class");
    }
}
class C implements I {
    public void play() {
        System.out.println("play in C class");
    }
}
class InterfaceTest {
    void test() {
        A a = new A();
        a.autoPlay(new B());
        a.autoPlay(new C());
    }
}

/*
    - 위처럼 매개변수를 통해 동적으로 제공받을 수도 있지만 제3의 클래스를 통해서 제공받을 수도 있다.
*/
class AA {
    void methodAA() {
        /*
            - 인스턴스를 직접 생성하지 않고, getInstance()라는 메서드를 통해 제공받는다. 이렇게 하면, 나중에 다른 클래스의
              인스턴스로 변경 되어도 AA클래스의 변경없이 getInstance()만 변경하면 된다는 장점이 생긴다.
        */
        II i = InstanceManager.getInstance();
        i.methodBB();
        System.out.println(i.toString());
    }
}
class InterfaceTest2 {
    void test() {
        AA a = new AA();
        a.methodAA();
    }
}
interface II {
    public abstract void methodBB();
}
class BB implements II {
    public void methodBB() {
        System.out.println("methodBB in BB class");
    }
    public String toString() { return "class BB"; }
}
class InstanceManager {
    public static II getInstance() {
        return new BB();
    }
}

/*
    - static 메서드
        : 원래는 인터페이스에 추상 메서드만 선언할 수 있는데, JDK1.8부터 디폴트 메서드와 static메서드도 추가할 수 있게 되었다.
          static메서드는 인스턴스와 관계가 없는 독립적인 메서드이기 때문에 예전부터 인터페이스에 추가하지 못할 이유가 없었다.
          JDK1.8 이전에는 인터페이스와 관련된 static메서드를 별도의 클래스에 따로 두어야 했다.
          가장 대표적인 것으로 java.util.Collection인터페이스가 있는데, 이 인터페이스와 관련된 static메서드들이 인터페이스에는 추상 메서드만 선언할 수 있다는
          원칙 때문에 별도의 클래스, Collections라는 클래스에 들어가게 되었다.
          만일 인터페이스에 static메서드를 추가할 수 있었다면, Collections클래스는 존재하지 않았을 것이다.
          그리고 인터페이스의 static메서드 역시 접근 제어자가 항상 public이며, 생략할 수 있다.
    - 디폴트 메서드
        : 조상 클래스에 새로운 메서드를 추가하는 것은 별 일이 아니지만, 인터페이스에 메서드를 추가한다는 것은, 추상 메서드를 추가한다는 것이고,
          이 인터페이스를 구현한 기존의 모든 클래스들이 새로 추가된 메서드를 구현해야 하기 때문에 번거롭게 된다.
          그래서 디폴트 메서드라는것이 나오게 되었다.
          디폴트 메서드는 추상 메서드의 기본적인 구현을 제공하는 메서드로, 추상 메서드가 아니기 때문에 디폴트 메서드가 새로 추가 되어도 해당 인터페이스를
          구현한 클래스를 변경하지 않아도 된다. (조상 클래스에 새로운 메서드를 추가한 것과 동일해 지는 것이다.)
        : 여러 인터페이스의 디폴트 메서드간의 충돌이 있을 때는 인터페이스를 구현한 클래스에서 디폴트 메서드를 오버라이딩 해야한다.
        : 디폴트 메서드와 조상 클래스의 메서드 간의 충돌이 있을 때는 조상클래스의 메서드가 상속되고 디폴트 메서드는 무시된다.
*/
class Parent {
    public void method2() {
        System.out.println("method2() in Parent");
    }
}
interface MyInterface {
    default void method1() {
        System.out.println("method1() in MyInterface");
    }
    default void method2() {
        System.out.println("method2() in MyInterface");
    }
    static void staticMethod() {
        System.out.println("staticMethod() in MyInterface");
    }
}
interface MyInterface2 {
    default void method1() {
        System.out.println("method1() in MyInterface2");
    }
    static void staticMethod() {
        System.out.println("staticMethod() in MyInterface2");
    }
}
class Child extends Parent implements MyInterface, MyInterface2 {
    // 여러 인터페이스의 디폴트 메서드간의 충돌이 있을 때는 인터페이스를 구현한 클래스에서 디폴트 메서드를 오버라이딩 해야한다.
    @Override
    public void method1() {
        System.out.println("method() in Child");
    }
}
public class Main {
    public static void main(String[] args) {

        Child c = new Child();
        c.method1();    // method() in Child
        c.method2();    // method2() in Parent - 디폴트 메서드와 조상 클래스의 메서드 간의 충돌이 있을 때는 조상클래스의 메서드가 상속되고 디폴트 메서드는 무시된다.
        MyInterface.staticMethod();     // staticMethod() in MyInterface
        MyInterface2.staticMethod();    // staticMethod() in MyInterface2
    }
}










