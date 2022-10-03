package al02;

import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {

        MySearch ms = new MySearch();

        ArrayList<Integer> list = new ArrayList<>();

        int cnt = 0;
        int value = 0;
        while(list.size() != 10) {
            boolean isValue = false;
            value = (int)(Math.random()*50) + 1;
            for(int i=0 ; i<list.size()-1 ; i++) {
                if(value == list.get(i)) {
                    isValue = true;
                }
            }
            if(!isValue) {
                list.add(value);
            }
        }

        System.out.println(list);
        System.out.println(ms.sequencialSearch(list, 21));

        Collections.sort(list);

        System.out.println(list);

        System.out.println(ms.binarySearch(list, 3));
    }
}
