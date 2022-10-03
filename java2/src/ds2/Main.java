package ds2;

public class Main {
    public static void main(String[] args) {
//        SingleLinkedList<Integer> list = new SingleLinkedList<>();
//
//        list.addNode(1);
//        list.addNode(2);
//        list.addNode(3);
//        list.addNode(4);
//
//        list.printList();
//
//        list.inAddNode(89, 1);
//
//        list.printList();
//
//        list.inAddNode(99, 5);
//
//        list.printList();
//
//        System.out.println(list.searchNodeIdx(99));
//
//        list.removeNode(99);
//        list.printList();
//
//        System.out.println("======================");
//        list.printListAll();

        DoubleLinkedList<Integer> list = new DoubleLinkedList<>();

        list.addNode(1);
        list.addNode(2);
        list.addNode(3);
        list.addNode(4);
        list.addNode(5);
        list.print();

        System.out.println(list.insertToFront(0, 1));

        list.print();

    }
}
