package ds1;

import java.util.ArrayList;
import java.util.Iterator;

public class MyStack<T> {

    private ArrayList<T> stack = new ArrayList<>();

    public boolean push(T element) {
        return stack.add(element);
    }

    public T pop() {
        int cnt = 0;
        if(stack.isEmpty()){
            System.out.println("비어있음.");
            return null;
        }
        cnt = stack.size();
        return stack.remove(cnt-1);
    }

    public void print() {
        System.out.println("size : " + stack.size());
        Iterator<T> it = stack.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }
    }
}
