package al04;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

// 정렬 기준 만들기 용 클래스
class Edge implements Comparable<Edge>{
    public Integer distance;
    public String vertex;

    public Edge(Integer distance, String vertex) {
        this.distance = distance;
        this.vertex = vertex;
    }
    // Comparable 인터페이스: compareTo()를 override해서 구현
    //      - 일반적으로는 정렬할 객체에 implements로 Comparable 인터페이스를 추가하여 구현
    // Comparator 인터페이스: compare()를 override해서 구현
    //      - 일반적으로는 별도 클래스를 정의해서 구현한다.
    //      - 따라서, 동일 객체에 다양한 정렬 기준을 가진 클래스를 작성 가능.
    @Override
    public int compareTo(Edge e) {
        return this.distance - e.distance;  // 오름차순 정렬
    }
}

public class Main {
    public static void main(String[] args) {

        Greed gd = new Greed();

        ArrayList<Integer> coinList = new ArrayList<Integer>(Arrays.asList(500, 100, 50, 1));

        gd.coinFunc(4720, coinList);

        System.out.println("\n-------------------------------기본정렬-------------------------------");

        Integer[] arr = new Integer[]{1, 10, 4, 3, 2};
        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));

        System.out.println("\n-------------------------------새로만든 기준으로 정렬-------------------------------");

        Edge edge1 = new Edge(12, "A");
        Edge edge2 = new Edge(10, "A");
        Edge edge3 = new Edge(13, "A");

        Edge[] edges = new Edge[]{edge1, edge2, edge3};

        // 1. Comparable 로 만든 기준 적용
        Arrays.sort(edges);

        for(int index=0 ; index<edges.length ; index++) {
            System.out.print(edges[index].distance + " ");
        }
        System.out.println();

        // 2. Comparator 로 만든 기준 적용
        Arrays.sort(edges, new Comparator<Edge>(){
           @Override
           public int compare(Edge objItem1, Edge objItem2) {
               return objItem2.distance - objItem1.distance;
           }
        });

        for(int index=0 ; index<edges.length ; index++) {
            System.out.print(edges[index].distance + " ");
        }
        // 정렬 기준이 2개 모두 있으면 Comparator가 우선한다. (Comparable을 덮어쓴다.)

        System.out.println("\n-------------------------------가방문제 테스트-------------------------------");

        // 1. 위 표를 자료구조화 한다. (2차원 배열로 작성해보기)
        Integer[][] objList = { {10,10}, {15,12}, {20,10}, {25,8}, {30,5}};

        gd.knapsackFunc(objList, 30.0);
    }
}


