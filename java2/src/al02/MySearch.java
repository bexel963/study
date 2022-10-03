package al02;

import java.util.ArrayList;

public class MySearch {

    public int sequencialSearch(ArrayList<Integer> list, Integer value) {

        for(int index=0 ; index<list.size() ; index++) {
            if(list.get(index) == value) {
                return index;
            }
        }
        return -1;
    }

    public boolean binarySearch(ArrayList<Integer> list, Integer value) {

        if(list.size()==1 && value==list.get(0)) {
            return true;
        }
        if(list.size()==1 && value!=list.get(0)) {
            return false;
        }
        if(list.size()==0) {
            return false;
        }

        int midIdx = list.size() / 2;

        if(value == list.get(midIdx)) {
            return true;
        } else {
            if(value < list.get(midIdx)) {
                return this.binarySearch(new ArrayList<Integer>(list.subList(0, midIdx)), value);
            } else {
                return this.binarySearch(new ArrayList<Integer>(list.subList(midIdx, list.size())), value);
            }
        }

    }
}











