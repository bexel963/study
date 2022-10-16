package al01;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class MySort {

    private Integer cnt = 0;

    public Integer getCnt() {
        return cnt;
    }

    public ArrayList<Integer> bubbleSort(ArrayList<Integer> list) {

        boolean isSwap = false;

        for(int i=0 ; i<list.size()-1 ; i++) {
            for(int j=0 ; j<list.size()-1-i ; j++) {
                cnt++;
                if(list.get(j) > list.get(j+1)) {
                    Collections.swap(list, j, j+1);
                    isSwap = true;
                }
            }
            if(!isSwap) break;
        }
        return list;
    }

    public ArrayList<Integer> selectSort(ArrayList<Integer> list) {

        int minIdx = 0;
        for(int i=0 ; i<list.size()-1 ; i++) {
            minIdx = i;
            for(int j=i+1 ; j<list.size() ; j++) {
                if(list.get(minIdx) > list.get(j)) {
                    minIdx = j;
                }
            }
            Collections.swap(list, i, minIdx);
        }
        return list;
    }

    public ArrayList<Integer> insertSort(ArrayList<Integer> list) {

        for(int i=0 ; i<list.size()-1 ; i++) {
            for(int j=i+1 ; j>0 ; j--) {
                if(list.get(j) < list.get(j-1)) {
                    Collections.swap(list, j, j-1);
                }
            }
        }
        return list;
    }
    public Integer findMin(ArrayList<Integer> list) {

        int minIdx = 0;

        for(int i=1 ; i<list.size()-1 ; i++) {

            if(list.get(0) > list.get(i)) {
                minIdx = i;
            }
        }

        return list.get(minIdx);
    }

    // < 병합 정렬 (분할정복 기법 적용) >
    public int factorial(int n) {
        if(n < 2) {
            return 1;
        }
        return (n) * factorial(n-1);
    }

    public int factorialList(ArrayList<Integer> dataList) {

        if(dataList.size() < 1) {
            return 0;
        }
        return dataList.get(0) + this.factorialList(new ArrayList<Integer>(dataList.subList(1, dataList.size())));
    }

    // 정수 n이 입력으로 주어졌을 때 n을 1, 2, 3의 합으로 나타낼 수 있는 방법의 수 구하기
    /*
        n : 4
        1) 1 + 1 + 1 + 1
        2) 1 + 1 + 2
        3) 1 + 2 + 1
        4) 2 + 1 + 1
        5) 2 + 2
        6) 1 + 3
        7) 3 + 1
    */
    // n=1 -> 1
    // n=2 -> 2
    // n=3 -> 4
    // n=4 -> 7
    // n=5 -> 13
    // ==> 해당 값 으로부터 앞에꺼 3개 더하면 해당 값이 나옴.
    public int numberOfCase(int value) {
        if(value==1) {
            return 1;
        } else if(value==2) {
            return 2;
        } else if(value==3) {
            return 4;
        }
        return this.numberOfCase(value-1) + this.numberOfCase(value-2) + this.numberOfCase(value-3);
    }

    // 분할 정복법(Divide and Conquer)
    // 하위 값을 미리 계산해서 저장해두지 않기 때문에 상위 값을 구하기 위해 하위 값을 구하는 함수를 각각 호출하여 수행한 후 이들을 병합한다.
    // 공간 복잡도를 낮추고 시간 복잡도를 높인다.
    public int fibonacciForRecursiveCall(int value) {
//        if(value==0) {
//            return 0;
//        } else if(value==1) {
//            return 1;
//        } else if(value==2) {
//            return 1;
//        }
        if(value <= 1) {
            return value;
        }
        return fibonacciForRecursiveCall(value-2) + fibonacciForRecursiveCall(value-1);
    }

    // 동적 계획법(Dynamic Programming)
    // 아주 작은 값을 미리 저장해 두고 이 값을 계속 활용하여 상위값을 구해나간다.
    // 공간 복잡도를 높이고 시간 복잡도를 낮춘다.
    public int fibonacciForDynamicProgramming(int value) {

        Integer[] cache = new Integer[value + 1];
        cache[0] = 0;
        cache[1] = 1;
        for(int index=2 ; index<value+1 ; index++) {
            cache[index] = cache[index-1] + cache[index-2];     // Memorization기법
        }
        return cache[value];
    }

    public void splitForHalf(ArrayList<Integer> list) {

        if(list.size() < 2) {
            return;
        } else {
            int mid = list.size() / 2;
            ArrayList<Integer> leftList = new ArrayList<Integer>(list.subList(0, mid));
            ArrayList<Integer> rightList = new ArrayList<Integer>(list.subList(mid, list.size()));

            System.out.println(leftList);
            System.out.println(rightList);
        }
    }

    // 분할 정복법 적용
    public ArrayList<Integer> mergeSort(ArrayList<Integer> list) {
        if(list.size() < 2) {
            return list;
        }
        int mid = list.size() / 2;
        ArrayList<Integer> leftList = new ArrayList<Integer>();
        ArrayList<Integer> rightList = new ArrayList<Integer>();
        ArrayList<Integer> mergeList = new ArrayList<>();

        leftList = mergeSort(new ArrayList<Integer>(list.subList(0, mid)));
        System.out.println("leftList: " + leftList);
        rightList = mergeSort(new ArrayList<Integer>(list.subList(mid, list.size())));
        System.out.println("rightList: " + rightList);

        mergeList = mergeFunc(leftList, rightList);
        System.out.println(cnt + ". " + mergeList);



        return mergeList;
    }

    public ArrayList<Integer> mergeFunc(ArrayList<Integer> leftList, ArrayList<Integer> rightList) {

        ArrayList<Integer> mergedList = new ArrayList<Integer>();
        int leftPoint = 0;
        int rightPoint = 0;

        // CASE1: left/right 둘 다 있을 때
        while(leftList.size() > leftPoint && rightList.size() > rightPoint) {
            if(leftList.get(leftPoint) > rightList.get(rightPoint)) {
                mergedList.add(rightList.get(rightPoint));
                rightPoint++;
            } else {
                mergedList.add(leftList.get(leftPoint));
                leftPoint++;
            }
        }
        // CASE2: right 데이터가 없을 때 (오른쪽 데이터 먼저 전부 처리 되었을 때)
        while(leftList.size() > leftPoint) {
            mergedList.add(leftList.get(leftPoint));
            leftPoint++;
        }
        // CASE3: left 데이터가 없을 때
        while(rightList.size() > rightPoint) {
            mergedList.add(rightList.get(rightPoint));
            rightPoint++;
        }
        cnt++;
        return mergedList;
    }
    // < 퀵 정렬 (분할정복 전력 적용) >
    // 1. 해당 리스트를 맨 앞에 데이터를 기준으로 작은 데이터는 left변수에, 그렇지 않은 데이터는 right 변수에 넣기
    public void splitForPivot(ArrayList<Integer> list) {
        if(list.size() <= 1) {
            return;
        }
        int pivot = list.get(0);

        ArrayList<Integer> leftArr = new ArrayList<>();
        ArrayList<Integer> rightArr = new ArrayList<>();

        for(int index=1 ; index<list.size() ; index++) {
            if(list.get(index) > pivot) {
                rightArr.add(list.get(index));
            } else {
                leftArr.add(list.get(index));
            }
        }

        System.out.println(leftArr);
        System.out.println(pivot);
        System.out.println(rightArr);

        // 2. 분할한 것을 다시 합치기
        ArrayList<Integer> mergedArr = new ArrayList<Integer>();
        mergedArr.addAll(leftArr);
        mergedArr.addAll(Arrays.asList(pivot)); // pivot을 배열로 만들어 주기
        mergedArr.addAll(rightArr);

        System.out.println(mergedArr);
    }

    // 3. 퀵 정렬 구현
    public ArrayList<Integer> quickSort(ArrayList<Integer> list) {
        if(list.size() <= 1) {
            return list;
        }
        int pivot = list.get(0);

        ArrayList<Integer> leftArr = new ArrayList<>();
        ArrayList<Integer> rightArr = new ArrayList<>();

        for(int index=1 ; index<list.size() ; index++) {
            if(list.get(index) > pivot) {
                rightArr.add(list.get(index));
            } else {
                leftArr.add(list.get(index));
            }
        }

        ArrayList<Integer> mergedArr = new ArrayList<Integer>();
        mergedArr.addAll(this.quickSort(leftArr));
        mergedArr.addAll(Arrays.asList(pivot));
        mergedArr.addAll(this.quickSort(rightArr));

        return mergedArr;
    }
}
