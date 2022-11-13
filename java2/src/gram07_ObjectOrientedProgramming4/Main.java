package gram07_ObjectOrientedProgramming4;

/*
    - 추상클래스
        : 추상 -> 낱낱의 구체적 표상이나 개념에서 공통된 성질을 뽑아 이를 일반적인 개념으로 파악하는 정신 작용.
        : 추상클래스는 추상메서드를 포함하고 있다는 것을 제외하고는 일반클래스와 같다.
        : 추상클래스로부터 상속받는 자손클래스는 오버라이딩을 통해 조상인 추상클래스의 추상 메서드를 모두 구현해주어야한다.
          만일 조상으로부터 상속받은 추상메서드 중 하나라도 구현하지 않는다면, 자손클래스 역시 추상클래스로 지정해 주어야 한다.
        : 메서드를 사용하는 쪽에서는 메서드가 실제로 어떻게 구현되어있는지 몰라도 메서드의 이름과 매개변수, 리턴타입, 즉 선언부만 아고 있으면 되므모
          내용이 없을 지라도 추상메서드를 사용하는 코드를 작성하는 것이 가능하며, 실제로는 자손클래스에 구현된 완성된 메서드가 호출되도록 할 수 있다.
        : 상속이 자손 클래스를 만드는데 조상 클래스를 사용하는 것이라면, 이와 반대로 추상화는 기존의 클래스의 공통부분을 뽑아내어 조상 클래스를 만드는 것이다.
          추상화 -> 클래스간의 공통점을 찾아내서 공통의 조상을 만드는 작업
          구체화 -> 상속을 통해 클래스를 구현, 확장하는 작업

    - Player
        : play(int pos), stop()를 추상메서드로 하는 대신, 아무 내용도 없는 메서드로 작성할 수도 있다. 이렇게 하면 어차피 자손 클래스에서 오버라이딩하여 자신의 클래스에 맞게 구현할 테니
          추상메서드로 선언하는 것과 내용없는 빈 몸통만 만들어 놓는 것이나 별 차이가 없어 보인다.
          그래도 굳이 abstract를 붙여서 추상메서드로 선언하는 이유는 자손클래스에서 추상메서드를 반드시 구현하도록 강요하기 위해서다.
          만일 추상메서드로 정의되어 있지 않고 빈 몸통만 가지도록 정의되어 있다면, 상속받는 자손 클래스에서는 이 메서드들이 온전히 구현된 것으로 인식하고 오버라이딩을 통해
          자신의 클래스에 맞도록 구현하지 않을 수도 있기 때문이다.
          하지만 추상메서드로 정의해놓으면, 자손 클래스를 작성할 때 이들이 추상메서드이므로 내용을 구현해주어야 한다는 사실을 인식하고 자신의 클래스에 알맞게 구현할 것이다.
*/
abstract class Player {
    boolean pause;
    int currentPos;

    Player() {
        pause = false;
        currentPos = 0;
    }
    abstract void play(int pos);    // 단지 괄호 {}만 있어도 추상메서드가 아닌 일반메서드로 간주된다.
    abstract void stop();

    void play() {
        play(currentPos);           // 추상메서드를 사용할 수 있다.
    }
    void pause() {
        if(pause) {
            pause = false;
            play(currentPos);       // 추상메서드를 사용할 수 있다.
        } else {
            pause = true;
            stop();
        }
    }
}

/*
    - Unit
        : 추상메서드로 선언도니 것에는, 앞으로 Unit클래스를 상속받아서 작성되는 클래스는 move메서드를 자신의 클래스에 알맞게
          반드시 구현해야 한다는 의미가 담겨있는 것이다.
*/
abstract class Unit {
    int x, y;
    abstract void move(int x, int y);
    void stop() {/*현재 위치에 정지*/}
}
class Marine extends Unit {
    void move(int x, int y) { /*지정된 위치로 이동*/}
    void stimPack() { };
}
class Tank extends Unit {
    void move(int x, int y) { /*지정된 위치로 이동*/}
    void changeMode() { };
}
class DropShip extends Unit {
    void move(int x, int y) { /*지정된 위치로 이동*/}
    void load() { };
    void unLoad() { };
}
class UnitTest {
    void test() {
        Unit[] group = new Unit[4];
        group[0] = new Marine();
        group[1] = new Tank();
        group[2] = new DropShip();
        group[3] = new Marine();
        /*
            - Unit클래스에 move()가 비록 추상메서드로 정의되어 있다 하더라도 이처럼 Unit클래스 타입의 참조변수로 move()를 호출하는 것이 가능하다.
              메서드는 참조변수의 타입에 관계없이 실제 인스턴스에 구현된 것이 호출되기 때문이다.
               group[i].move(100, 200)를 호출하는 것이 Unit클래스의 추상메서드인 move를 호출하는 것 처럼 보이지만 실제로는 이 추상메서드가 구현된
               Marine, Tank, DropShip인스턴스의 메서드가 호출되는 것이다.
        */
        for(int i=0 ; i<group.length ; i++) {
            group[i].move(100, 200);
        }

        Object[] objGroup = new Object[4];
        objGroup[0] = new Marine();
        objGroup[1] = new Tank();
        objGroup[2] = new DropShip();
        objGroup[3] = new Marine();
        /*
            - 모든 클래스의 조상인 Object클래스 타입의 배열로도 서로 다른 종류의 인스턴스를 하나의 묶음으로 다룰 수 있지만, Object클래스에는
              move()가 정의되어있지 않기 때문에 move()를 호출하는 부분에서 에러가 발생한다.
        */
        for(int i=0 ; i<objGroup.length ; i++) {
//            objGroup[i].move(100, 200);     // Error
        }
    }
}

/*
    -
*/
public class Main {
    public static void main(String[] args) {

    }
}
