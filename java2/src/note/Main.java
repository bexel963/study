package note;

class Person {
    String name = "A";
    int age = 200;

    public void run() {
        System.out.println("today");
        System.out.println("run!!!");
        System.out.println("tomorrow");
    }
}
public class Main {

    public static void function1() {
        System.out.println("111");
        Person person = new Person();
        person.run();
        function2();
        System.out.println("222");
    }
    public static void function2() {
        System.out.println("function2");
    }
    public static void main(String[] args) {

        System.out.println("START!!!");
        function1();
        System.out.println("END!!!");
    }
}
