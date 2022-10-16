package al01;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {

        MySort sort = new MySort();

        ArrayList<Integer> list = new ArrayList<>(Arrays.asList(49, 97, 53, 5, 33, 65, 62, 51));

//        for(int i=0 ; i<10 ; i++) {
//            list.add((int)(Math.random()*50) + 1);
//        }
//        int cnt = 0;
//        int value = 0;
//        while(list.size() != 10) {
//            boolean isValue = false;
//            value = (int)(Math.random()*50) + 1;
//            for(int i=0 ; i<list.size()-1 ; i++) {
//                if(value == list.get(i)) {
//                    isValue = true;
//                }
//            }
//            if(!isValue) {
//                list.add(value);
//            }
//        }
        System.out.println("---------------------------------------");

        System.out.println("정렬 전: " + list);
        list = sort.mergeSort(list);
        System.out.println("정렬 후: " + list);

        System.out.println(sort.findMin(list));

        System.out.println(sort.factorial(1));

        System.out.println(sort.factorialList(list));
        System.out.println(sort.numberOfCase(5));
        System.out.println(sort.fibonacciForRecursiveCall(10));
        System.out.println(sort.fibonacciForDynamicProgramming(10));

        sort.splitForHalf(list);

        System.out.println("----------------------");

        Integer[] array = { 4, 1, 2, 5, 7, 3, 2, 6, 22, 32, 12 };
        list = new ArrayList<Integer>(Arrays.asList(array));
        sort.splitForPivot(list);

        System.out.println("----------------------");

        System.out.println(sort.quickSort(list));

    }
}
