package gram06_ObjectOrientedProgramming3;

/*
    - 다형성
        : '여러 가지 형태를 가질 수 있는 능력'
          -> 한 타입의 참조변수로 여러 타입의 객체를 참조할 수 있는 것.
          -> 조상클래스 타입의 참조변수로 자손클래스의 인스턴스를 참조할 수 있는 것.
        : 인스턴스의 타입과 참조변수의 타입이 일치하는 것이 보통이지만, 클래스들이 상속 관계에 있는 경우,
          조상 클래스 타입의 참조변수로 자손 클래스의 인스턴스를 참조하도록 하는 것이 가능하다.
                CaptionTv c = new CaptionTv();
                Tv        t = new CaptionTv();
          둘 다 같은 타입의 인스턴스지만 참조변수의 타입에 따라 사용할 수 있는 멤버의 개수가 달라진다.
        : 반대로 자손타입의 참조변수로 조상타입의 인스턴스를 참조하는 것은 불가능하다.
                CaptionTv c = new Tv();     // ERROR
          실제 인스턴스인 Tv의 멤버 개수보다 참조변수 c가 사용할 수 있는 멤버 개수가 더 많기 때문이다. 그래서 이를 허용하지 않는다.
          ==> 참조변수가 사용할 수 있는 멤버의 개수는 인스턴스의 멤버 개수보다 같거나 적어야 한다.
*/
class Tv_ {
    boolean power;
    int channel;

    void power() { power = !power; }
    void channelUp() { ++channel; }
    void channelDown() { ++channel; }
}
class CaptionTv extends Tv_{
    String text;
    void caption() { System.out.println(text); }
}

/*
    - 참조변수의 형변환
        : 기본형 변수의 형변환에서 작은 자료형에서 큰 자료형의 형변환은 생략이 가능하듯이, 참조변수의 형변환에서는
          자손타입의 참조변수를 조상타입으로 형변환하는 경우는 형변환을 생략할 수 있다. (Up-casting)
          조상타입의 참조변수를 자손타입으로 형변환하는 경우는 형변환을 생략할 수 없다. (Down-casting)
        : Car타입의 참조변수 c가 있다고 가정하자. 참조변수 c가 참조하고 있는 인스턴스는 아마도 Car인스턴스 이거나 자손인 FireEngine인스턴스 일것이다.
          Car타입의 참조변수 c를 Car타입의 조상인 Object타입의 참조변수로 형변환 하는 것은 참조변수가 다룰 수 있는 멤버의 개수가 실제 인스턴스가 갖고 있는
          멤버의 개수보다 적을 것이 분명하므로 문제가 되지 않는다. 그래서 형변환을 생략할 수 있도록 한 것이다.
          하지만, Car타입의 참조변수 c를 자손인 FireEngine타입으로 변환하는 것은 참조변수가 다룰 수 있는 멤버의 개수를 늘이는 것이므로, 실제 인스턴스의
          멤버 개수보다 참조변수가 사용할 수 있는 멤버의 개수가 더 많아지므로 문제가 발생할 가능성이 있다.
          (Car타입의 참조변수 c가 참조하고있는 인스턴스가 FireEngine라면 문제가 되지 않겠지만, Car라면 문제가 발생하는 것이다.)
          그래서 자손타입으로의 형변환은 생략할 수 없으며, 형변환을 수행하기 전에 instanceof연산자를 이용해서 참조변수가 참조하고 있는 실제 인스턴스의
          타입을 확인하는 것이 안전하다.
        : 형변환은 참조변수의 타입을 변환하는 것이지 인스턴스를 변환하는 것은 아니기 때문에 참조변수의 형변환은 인스턴스에 아무런 영향을 미치지 않는다.
          단지 참조변수의 형변환을 통해서, 참조하고 있는 인스턴스에서 사용할 수 있는 멤버의 범위(개수)를 조절하는 것 뿐이다.
*/
class Car {
    String color;
    int door;
    void drive() { System.out.println("drive, Brrr~~~"); }
    void stop() { System.out.println("stop!!!"); }
}
class FireEngine extends Car {
    void water() { System.out.println("water!!!"); }
}
class Ambulance extends Car {
    void siren() { System.out.println("beep~ beep~"); }
}
class CastingTest {
    void test1() {
        Car car = null;
        FireEngine fe = new FireEngine();
        FireEngine fe2 = null;
        car = fe;                   // 업캐스팅(형변환 생략 가능.)
        fe2 = (FireEngine) car;     // 다운캐스팅(형변환 생략 안 됨.)
    }
    void test2() {
        Car car = new Car();
        Car car2 = null;
        FireEngine fe = null;

        car.drive();
        fe = (FireEngine) car;      // 컴파일은 되지만 실행 시 ERROR!
                                    // car가 참조하고 있는 인스턴스는 Car인데 Car는 fe의 부모이다.
                                    // 자손타입의 참조변수로 부모 인스턴스는 참조할 수 없기 때문에 에러가 난다.
        // 컴파일 시에는 참조변수간의 타입만 체크하기 때문에 실행 시 생성될 인스턴스의 타입에 대해서는 전혀 알지 못한다.
        // 그래서 컴파일 시에는 문제가 없었지만, 실행 시에는 에러가 발생하여 실행이 비정상적으로 종료되는 것이다.
        // ==> 서로 상속관계에 있는 타입간의 형변환은 양방향으로 자유롭게 수행될 수 있으나, 참조변수가 가리키는 인스턴스의 자손타입으로 형변환은 허용되지 않는다.

        fe.drive();
        car2 = fe;
        car2.drive();
    }
    /*
        - instanceof연산자
            : 참조변수가 참조하고 있는 인스턴스의 실제 타입을 알아보기 위해 instanceof연산자를 사용한다.
              주로 조건문에 사용되며, instanceof의 왼쪽에는 참조변수를 오른쪽에는 타입(클래스명)이 피연산자로 위치한다.
              연산결과로 true를 얻었다는 것은 참조변수가 검사한 타입으로 형변환이 가능하다는 것을 뜻한다.
            : doWork(Car c)가 호출될 때, 매개변수로 Car클래스 또는 그 자손 클래스의 인스턴스를 넘겨 받겠지만 메서드 내에서는 정확히 어떤 인스턴스인지 모른다.
              그래서 instanceof연산자를 이용해서 참조변수 c가 가리키고 있는 인스턴스의 타입을 체크하고, 적절히 형변환한 다음에 작업을 해야한다.
    */
    void doWork(Car c) {
        if(c instanceof FireEngine) {
            // 조상타입의 참조변수로는 실제 인스턴스의 멤버들을 모두 사용할 수 없기 때문에, 실제 인스턴스와 같은 타입의 참조변수로 형변환을 해야한다.
            FireEngine fe = (FireEngine) c;
            fe.water();
        } else if(c instanceof Ambulance) {
            Ambulance a = (Ambulance) c;
            a.siren();
        }
    }
    /*
        - instanceofTest()
            : 생성된 인스턴스는 FireEngine타입인데도, Object타입과 Car타입의 instanceof연산에서도 true를 결과로 얻었다.
              그 이유는 FireEngine클래스는 Object클래스와 Car클래스의 자손 클래스이므로 조상의 멤버들을 상속받았기 때문에,
              FireEngine인스턴스는 Object인스턴스와 Car인스턴스를 포함하고 있는 셈이기 때문이다.
    */
    void instanceofTest() {
        FireEngine fe = new FireEngine();
        if(fe instanceof FireEngine) {  // true
            System.out.println("This is a FireEngine instance.");
        }
        if(fe instanceof Car) {         // true
            System.out.println("This is a Car instance.");
        }
        if(fe instanceof Object) {      // true
            System.out.println("This is a Object instance.");
        }

        System.out.println(fe.getClass().getName());    // 클래스의 이름 출력
    }
}
/*
    - 참조변수와 인스턴스의 연결
        : 메서드의 경우 조상 클래스의 메서드를 자손의 클래스에서 오버라이딩한 경우에도 참조변수의 타입에 관계없이 항상 실제 인스턴스의
          메서드(오버라이딩된 메서드)가 호출되지만, 멤버변수의 경우 참조변수의 타입에 따라 달라진다.
          멤버변수가 조상 클래스와 자손 클래스에 중복으로 정의된 경우, 조상타입의 참조변수를 사용했을 때는 조상 클래스에 선언도니 멤버변수가
          사용되고, 자손타입의 참조변수를 사용했을 때는 자손 클래스에 선언된 멤버변수가 사용된다.
          하지만 중복되지 않은 경우, 조상타입의 참조변수를 사용했을 때와 자손타입의 참조변수를 사용했을 때의 차이는 없다.
          (static메서드는 static변수처럼 참조변수의 타입에 영향을 받는다. 참조변수의 타입에 영향을 받지 않는 것은 인스턴스메서드 뿐이다.)
          (그래서 static메서드는 반드시 참조변수가 아닌 "클래스이름.메서드()"로 호출해야 한다.)
*/
class BindingTest {
    void test1() {
        Parent p = new Child();
        Child c = new Child();

        System.out.println("p.x = " + p.x); // 100
        p.method();                         // Child Method
        System.out.println("p.x = " + c.x); // 200
        c.method();                         // Child Method
    }
}
class Parent {
    int x = 100;
    void method() {
        System.out.println("Parent Method");
    }
}
class Child extends Parent {
    int x = 200;
    void method() {
        System.out.println("Child Method");
    }
}
/*
    - 매개변수의 다형성, 여러 종류의 객체를 배열로 다루기
*/
class Product {
    int price;
    int bonusPoint;
    Product() { }
    Product(int price) {
        this.price = price;
        bonusPoint = (int) (price / 10.0);
    }
}
class Tv extends Product {
    Tv() { super(100); }
    public String toString() { return "Tv"; }
}
class Computer extends Product {
    Computer() { super(200); }
    public String toString() { return "Computer"; }
}
class Audio extends Product {
    Audio() { super(50); }
    public String toString() { return "Audio"; }
}
class Buyer {
    int money = 1000;
    int bonusPoint = 0;
    Product[] item = new Product[10];
    int idx = 0;

    void buy(Product p) {
        if(money < p.price) {
            System.out.println("잔액이 부족합니다.");
            return;
        }
        money -= p.price;
        bonusPoint += p.bonusPoint;
        item[idx++] = p;
        System.out.println(p + "을/를 구입했습니다.");
    }
    void summary() {
        int sum = 0;
        String itemList = "";
        for(int i=0 ; i<item.length ; i++) {
            if(item[i]==null) break;
            sum += item[i].price;
            itemList += item[i] + ", ";
            System.out.println("구입하신 물품의 총금액은 " + sum + "만원입니다.");
            System.out.println("구입하신 제품은 " + itemList + "입니다.");
        }
    }
}
public class Main {

    public static void main(String[] args) {

        Buyer b = new Buyer();
        b.buy(new Tv());
        b.buy(new Computer());
        b.buy(new Audio());
        b.summary();
    }
}















