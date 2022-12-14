package gram05_ObjectOrientedProgramming2;
/*
    - 클래스를 재사용하는 방법
        1)상속
            : 생성자와 초기화 블록은 상속되지 않는다. 멤버만 상속된다.
            : 자손 클래스의 인스턴스를 생성하면 조상 클래스의 멤버와 자손 클래스의 멤버가 합쳐진 하나의 인스턴스로 생성된다.
        2)포함관계
            : 클래스 간의 포함관계를 맺어주는 것은 한 클래스의 멤버변수로 다른 클래스 타입의 참조변수를 선언하는 것을 뜻한다.
        3)관계 설정
            3-1) 'is a' 관계 -> 상속
            3-2) 'has a' 관계 -> 포함

    - 단일 상속
        : C++에서는 여러 조상 클래스로부터 상속받는 것이 가능한 '다중상속'을 허용하지만 자바에서는 오직 단일 상속만을 허용한다.
          그래서 가장 하나의 클래스만 상속 받고, 나머지 클래스들은 포함을 시킨다.

    - Object클래스
        : 다른 클래스로부터 상속 받지 않는 모든 클래스들은 자동적으로 Object클래스를 상속받게 된다.
          컴파일러가 자동으로 'extends Object'를 추가해 준다.
        : 이미 어떤 클래스로부터 상속 받도록 작성된 클래스에 대해서는 컴파일러가 'extends Object'를 추가하지 않는다.
        : Object클래스에는 toString(), equals()와 같은 모든 인스턴스가 가져야 할 기본적인 11개의 메서드가 정의되어있다.

    - 오버라이딩의 조건
        1) 조상 클래스의 메서드와 이름, 매개변수, 반환타입 이 같아야 한다.
        2) 접근 제어자는 조상 클래스의 메서드보다 좁은 범위로 변경 할 수 없다.
        3) 조상 클래스의 메서드보다 많은 수의 예외를 선언할 수 없다.
        4) 인스턴스메서드를 static메서드로 또는 그 반대로 변경할 수 없다.
    - 오버로딩 vs 오버라이딩
        : 오버로딩 - 기존에 없는 새로운 메서드를 정의하는 것
        : 오버라이딩 - 상속받은 메서드의 내용을 변경하는 것

    - super
        : 멤버변수와 지역변수의 이름이 같을 때 this를 붙여서 구별했듯이 상속받은 멤버와 자신의 멤버와 이름이 같을 대는 super를 붙여서 구별할 수 있다.
          조상 클래스로부터 상속받은 멤버도 자손 클래스 자신의 멤버이므로 super대신 this를 사용할 수 있다. 그래도 조상 클래스의 멤버와 자손클래스의 멤버가
          중복 정의되어 서로 구별해야하는 경우에만 super를 사용하는 것이 좋다.
          모든 인스턴스메서드에는 자신이 속한 인스턴스의 주소가 지역변수로 저장되는데, 이것이 참조변수인 this와 super의 값이 된다.
          super를 이용해서 자식 클래스에서 오버라이딩한 메서드의 조상버전을 호출할 수 있다.

    - super()
        : 조상 클래스의 멤버변수는 조상의 생성자에 의해 초기화되도록 하는 것이 좋다.
          생성자의 첫 줄에서 조상클래스의 생성자를 호출해야하는 이유는 자손 클래스의 멤버가 조상 클래스의 멤버를 사용할 수도 있으므로 조상의 멤버들이 먼저
          초기화되어 있어야 하기 때문이다.
          그래서 Object클래스를 제외한 모든 클래스의 생성자는 첫 줄에 반드시 자신의 다른 생성자 또는 조상의 생성자를 호출해야 한다.
          그렇지 않으면 컴파일러는 생성자의 첫 줄에 'super();' 를 자동으로 추가한다.
          이 때, super()를 호출한 클래스의 조상클래스에는 super()가 호출될 수 있도록 기본생성자가 있어야 한다.
          (**컴파일러는 해당 클래스에 매개변수가 있는 생성자가 있으면 기본생성자를 자동으로 추가해주지 않는다.)

    - 패키지
        : 클래스의 묶음이다.
          하나의 소스파일에는 첫 번째 문장으로 단 한 번의 패키지 선언만을 허용한다.
          모든 클래스는 반드시 하나의 패키지에 속해야 한다.
          패키지는 점(.)을 구분자로 하여 계층구조로 구성할 수 있다.
          패키지는 물리적으로 클래스 파일(.class)을 포함하는 하나의 디렉토리이다.
          패키지명은 대소문자를 모두 허용하지만, 소문자로 하는 것을 원칙으로 한다.
          소스파일에 자신이 속한 패키지를 지정하지 않은 클래스는 자동적으로 '이름없는 패키지'에 속하게 된다.
        : 클래스의 실제 이름은 패키지명을 포함한 것이다.
        : 클래스패스는 컴파일러나 JVM 등이 클래스의 위치를 찾는데 사용되는 경로이다.

    - import문
        : 소스코드를 작성할 때 다른 패키지의 클래스를 사용하려면 패키지명이 포함된 클래스 이름을 사용해야 한다.
          import문의 역할은 컴파일러에게 소스파일에 사용된 클래스의 패키지에 대한 정보를 제공하는 것이다.
          컴파일 시에 컴파일러는 import문을 통해 소스파일에 사용된 클래스들의 패키지를 알아낸 다음, 모든 클래스 이름 앞에 패키지명을 붙여준다.
    - static import문
        : import문을 사용하면 클래스의 패키지명을 생략할 수 있는 것과 같이 static import문을 사용하면 static멤버를 호출할 때 클래스 이름을 생략할 수 있다.

    - 제어자
        : 제어자는 클래스, 변수, 메서드의 선언부에 함께 사용되어 부가적인 의미를 부여한다.
          제어자들 간의 순서는 관계없지만 주로 접근 제어자를 제일 왼쪽에 놓는 경향이 있다.

          1) static - 클래스의, 공통적인
            : 인스턴스메서드와 static메서드의 근본적인 차이는 메스드 내에서 인스턴스 멤버를 사용하는가의 여부에 있다.
              가능하다면 static메서드로 하는 것이 인스턴스를 생성하지 않고도 호출이 가능해서 더 편리하고 속도도 더 빠르다.

          2) final - 마지막의, 변경될 수 없는
            : final class -> 다른 클래스의 조상이 될 수 없다.
              메서드 -> 오버라이딩을 통해 재정의 될 수 없다.
              변수 -> 상수가 된다.
            : 생성자를 이용한 final멤버 변수의 초기화
                : final이 붙은 변수는 상수이므로 일반적으로 선언과 초기화를 동시에 하지만, 인스턴스 변수의 경우 생성자에서 초기화 되도록 할 수 있다.
                  클래스 내에 매개변수를 갖는 생성자를 선언하여, 인스턴스를 생성할 때 final이 붙은 멤버변수를 초기화하는데 필요한 값을 생성자의 매개변수로 부터 제공 받는것이다.
                  이 기능을 활용하면 각 인스턴스마다 final이 붙은 멤버변수가 다른 값을 갖도록 하는 것이 가능하다.
                  만일 이것이 불가능하다면 클래스에 선언된 final이 붙은 인스턴스변수는 모든 인스턴스에서 같은 값을 가져야만 할 것이다.

          3) abstract - 추상의, 미완성의
            : abstract class -> 클래스 내에 추상 메서드가 선언되어 있음을 알린다.
              abstract method() -> 선언부만 작성하고 구현부는 작성하지 않은 추상 메서드임을 알린다.
            : 의도적으로 여러 인터페이스를 구현한 클래스의 인스턴스를 생성하지 못하게 클래스 앞에 제어자 'abstract'를 붙여 놓는 경우도 있다.
              이렇게 하면 다른 클래스가 이 클래스를 상속받아서 일부의 원하는 메서드만 오버라이딩해도 된다는 장점이 있다.
              그렇지 않으면 아무런 내용도 없는 메서드들을 잔뜩 오버라이딩해야 한다.

          4) 접근 제어자
            : private -> 같은 클래스 내에서만 접근 가능
              (default) -> 같은 패키지 내에서만 접근 가능
              protected -> 같은 패키지 내에서 + 다른 패키지의 자손클래스에서 접근이 가능
              public -> 접근 제한이 없다.
            : 대상에 따라 사용할 수 있는 접근 제어자
                클래스          <- public, (default)
                메서드, 멤버변수 <- public, protected, (default), private
                지역변수        <- 없음
            : 접근제어자를 사용하는 이유
                1) 외부로부터 데이터를 보호하기 위해서
                    : 데이터가 유효한 값을 유지하도록 데이터를 외부에서 함부로 변경하지 못하도록 한다.
                2) 외부에는 불필요한, 내부적으로만 사용되는 부분을 감추기 위해서
                    : 만일 멤버 하나를 변경해야 한다고 가정했을 때, 이 멤버의 접근제어자가 public이라면 멤버를 변경한 후에 오류가 없는지 테스트해야 하는 범위가 넓다.
                      그러나 접근제어자가 default라면 패키지 내부만 확인해 보면 되고, private라면 클래스 하나만 살펴보면 된다.
                ** 하나의 소스파일(*.java)에는 public클래스가 단 하나만 존재할 수 있으며, 소스파일의 이름은 반드시 public클래스와 이름이 같아야한다.
            : 생성자의 접근 제어자
                : 생성자에 접근 제어자를 사용함으로써 인스턴스의 생성을 제한할 수 있다.
                  생성자의 접근 제어자를 private로 지정하면, 외부에서 생성자에 접근할 수 없으므로 인스턴스를 생성할 수 없게 된다.
                  그래도 클래스 내부에서는 인스턴스를 생성할 수 있다.
                  생성자를 통해 직접 인스턴스를 생성하지 못하게 하고 public메서드를 통해 인스턴스에 생성 함으로써 사용할 수 있는 인스턴스의 개수를 제한할 수 있다.
                : 생성자가 private인 클래스는 다른 클래스의 조상이 될 수 없다.
                  자손클래스의 인스턴스를 생성할 대 조상클래스의 생성자를 호출해야만 하는데, 생성자의 접근 제어자가 private이므로 자손클래스에서 호출이 불가능하기 때문이다.
                  그래서 이 때는 클래스 앞에 final을 더 추가하여 상속할 수 없는 클래스라는 것을 알리는 것이 좋다.

    - 대상에 따라 사용할 수 있는 제어자
        클래스   -> public, (default), final, abstract
        메서드   -> 모든 접근 제어자, final, abstract, static
        멤버변수 -> 모든 접근 제어자, final, static
        지역변수 -> final

    - 제어자를 조합해서 사용할 때 주의사항
        1) 메서드에 static과 abstract를 함께 사용할 수 없다.
            : static은 몸통이 있는 메서드에만 사용할 수 있기 때문이다.
        2) 클래스에 abstract와 final을 동시에 사용할 수 없다.
            : 클래스에서 사용되는 final은 클래스를 확장할 수 없다는 의미이고 abstract는 상속을 통해서 완성되어야 한다는 의미이므로 서로 모순되기 때문이다.
        3) abstract메서드의 접근제어자가 private일 수 없다.
            : abstract메서드는 자손클래스에서 구현해주어야 하는데 접근 제어자가 private면, 자손클래스에서 접근할 수 없기 때문이다.
        4) 메서드에 private와 final을 같이 사용할 필요는 없다.
            : 접근 제어자가 private인 메서드는 오버라이딩될 수 없기 때문이다. 이 둘 중 하나만 사용해도 의미가 충분하다.

*/
final class Singleton {
    // static메서드인 getInstance()에서 사용될 수 있도록 인스턴스가 미리 생성되어야 하므로 static이어야 한다.
    private static Singleton s;

    private Singleton() {

    }
    // 인스턴스를 생성하지 않고도 호출할 수 있어야 하므로 static이어야 한다.
    public static Singleton getInstance() {
        if(s==null) {
            s = new Singleton();
        }
        return s;
    }
}
public class Main {
    public static void main(String[] args) {
        Singleton s = Singleton.getInstance();
        System.out.println(s);
    }
}














