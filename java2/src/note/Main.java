package note;

public class Main {
    public static void main(String[] args) {
        MyLinkedList<Integer> list = new MyLinkedList<>();

        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);

        list.print();

        list.addIs(999, 3);

        list.print();

        list.addIs(999, 6);

        list.print();

        list.addIs(999, 1);

        list.print();
    }
}