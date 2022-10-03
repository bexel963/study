package ds1;

import java.util.ArrayList;
import java.util.Iterator;

public class MyQueue<T> {

    private ArrayList<T> queue = new ArrayList<>();

    public boolean enQueue(T element) {
        return queue.add(element);
    }
    public T deQueue() {
        if(queue.isEmpty()){
            System.out.println("비어있음.");
            return null;
        }
        return queue.remove(0);
    }

    public void print() {
        Iterator<T> it = queue.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }
    }
}
