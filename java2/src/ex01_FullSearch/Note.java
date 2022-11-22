package ex01_FullSearch;








/*
    <문제>
        - 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램 작성.
            1) 1부터 N까지 자연수 중에서 M개를 고른 수열
            2) 같은 수를 여러번 골라도 된다.
            입력: 첫째 줄에 자연수 N과 M이 주어진다. (1 <= M <= N <=7)
            출력: 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다.
                  ( 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 사전 순으로 증가하는 순서로 출력해야 한다. )
*/

import java.util.Arrays;

public class Note {
    static int[] arr = new int[4];

    public static void rec_func1(int k) {
        if(k == 4) {
            StringBuffer sb = new StringBuffer(5);
            for(int i=1 ; i<=3 ; i++) {
                sb.append(arr[i]).append(" ");
            }
            System.out.println(sb);
            return;
        }
        for(int i=1 ; i<=4 ; i++) {
            arr[k] = i;
            rec_func1(k+1);
        }
    }
    // rec_func1에서 중복을 허용하지 않는다는 조건 추가
    public static void rec_func2_1(int k) {
        if(k == 4) {
            StringBuffer sb = new StringBuffer(5);
            for(int i=1 ; i<=3 ; i++) {
                sb.append(arr[i]).append(" ");
            }
            System.out.println(sb);
            return;
        }
        for(int i=1 ; i<=4 ; i++) {
            boolean flag = false;
            for(int j=1 ; j<=3 ; j++) {
                if(arr[j] == i) {
                    flag = true;
                }
            }
            if(!flag) {
                arr[k] = i;
            } else {
                continue;
            }
            rec_func2_1(k+1);
            arr[k] = 0;
        }
    }

    // func2_1 에서 반복문 1개를 배열로 대체 -> 시간 복잡도 줄어듦.
    public static int[] mark = new int[5];
    public static void rec_func2_2(int k) {
        if(k == 4) {
            StringBuffer sb = new StringBuffer(5);
            for(int i=1 ; i<=3 ; i++) {
                sb.append(arr[i]).append(" ");
            }
            System.out.println(sb);
            return;
        }
        for(int i=1 ; i<=4 ; i++) {
            if(mark[i]==1) {
                continue;
            }
            arr[k] = i;
            mark[i] = 1;

            rec_func2_2(k+1);
            arr[k] = 0;
            mark[i] = 0;
        }
    }
    // func1에서 '고른 수열이 비내림차순' 이라는 조건 추가.
    /*
        1 1 1
        ....
        2 2 2
        2 2 3
        2 2 4
        2 3 3
        2 3 4
        2 4 4
        3 3 3
        3 3 4
        3 4 4
        4 4 4
    */
    public static void rec_func3(int k) {
        if(k == 4) {
            StringBuffer sb = new StringBuffer(5);
            for(int i=1 ; i<=3 ; i++) {
                sb.append(arr[i]).append(" ");
            }
            System.out.println(sb);
            return;
        }
        for(int i=1 ; i<=4 ; i++) {
            if(arr[k-1] > i) {
                continue;
            }
            arr[k] = i;
            rec_func3(k+1);
        }
    }

    // func1에서 '중복을 허용하지 않고 오름차순 정렬' 이라는 조건 추가
    public static void rec_func4(int k) {
        if(k == 4) {
            StringBuffer sb = new StringBuffer(5);
            for(int i=1 ; i<=3 ; i++) {
                sb.append(arr[i]).append(" ");
            }
            System.out.println(sb);
            return;
        }
        for(int i=1 ; i<=4 ; i++) {
            if(arr[k-1] >= i) {
                continue;
            }
            arr[k] = i;
            rec_func4(k+1);
        }
    }
    public static void main(String[] args) {

        rec_func4(1);
    }
}
