package ds5;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    public static void main(String[] args) {

        MyHeap heap = new MyHeap(15);

        heap.insert(10);
        heap.insert(8);
        heap.insert(5);
        heap.insert(4);
        heap.insert(20);

        System.out.println(heap);
        System.out.println(heap.pop());
        System.out.println(heap);

    }
}
