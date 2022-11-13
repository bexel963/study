package gram04_ObjectOrientedProgramming1;

class Car {
    String color;
    String gearType;
    int door;

    Car() {
        this("white", "auto", 4);
    }
    Car(String color, String gearType, int door) {
        this.color = color;
        this.gearType = gearType;
        this.door = door;
    }

    // 인스턴스의 복사를 위한 생성자.
    Car(Car c) {
        this(c.color, c.gearType, c.door);
    }

    @Override
    public String toString() {
        return "[" + color + ", " + gearType + ", " + door + "]";
    }
}
public class CloneInstance {
    public static void main(String[] args) {

        Car car = new Car();
        Car car2 = new Car("red", "manual", 2);

        System.out.println("차1" + car);
        System.out.println("차2" + car2);

        Car cloneCar = new Car(car2);
        System.out.println("복사된 차: " + cloneCar);
    }
}
