package al03;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {

        System.out.println("-----------------------------map(CRUD)-----------------------------");
        // 데이터를 다루는 기능은 항상 CRUD 순으로 사용법을 익힌다.
        // 생성 및 선언 - C
        HashMap<String, Integer> map1 = new HashMap<String, Integer>();
        HashMap<String, Integer> map2 = new HashMap<String, Integer>(map1);
        HashMap<String, Integer> map3 = new HashMap<String, Integer>(10);
        HashMap<String, ArrayList<String>> map4 = new HashMap<String, ArrayList<String>>();

        map1.put("A", 1);
        map1.put("B", 2);
        // 읽기 - R
        System.out.println(map1);
        System.out.println(map1.get("A"));
        // 수정 - U
        map1.put("B", 222);
        System.out.println(map1);
        // 삭제 - D
        map1.remove("A");
        System.out.println(map1);

        System.out.println("\n-----------------------------Graph-----------------------------");

        // 그래프를 Map과 ArrayList로 표현하기
        HashMap<String, ArrayList<String>> graph = new HashMap<String, ArrayList<String>>();

        graph.put("A", new ArrayList<String>(Arrays.asList("B", "C")));
        graph.put("B", new ArrayList<String>(Arrays.asList("A", "D")));
        graph.put("C", new ArrayList<String>(Arrays.asList("A", "G", "H", "I")));
        graph.put("D", new ArrayList<String>(Arrays.asList("B", "E", "F")));
        graph.put("E", new ArrayList<String>(Arrays.asList("D")));
        graph.put("F", new ArrayList<String>(Arrays.asList("D")));
        graph.put("G", new ArrayList<String>(Arrays.asList("C")));
        graph.put("H", new ArrayList<String>(Arrays.asList("C")));
        graph.put("I", new ArrayList<String>(Arrays.asList("C", "J")));
        graph.put("J", new ArrayList<String>(Arrays.asList("I")));

        System.out.println(graph);

        System.out.println("\n-----------------------------ArrayList로 Queue역할 하기-----------------------------");

        ArrayList<String> aList = new ArrayList<String>();
        aList.add("A");
        aList.add("B");
        aList.add("C");
        String node = aList.remove(0);  // 0번지 삭제 후 뒤에 꺼 앞으로 한 칸씩 땡김.
        System.out.println(node);
        System.out.println(aList);

        // needVisit큐에서 데이터 하나 꺼내어 Visited큐에 넣으려 할 때, 이미 그 데이터가 Visited큐에 있는지 확인
        System.out.println(aList.contains("A"));

        System.out.println("\n-----------------------------map의 값들을 차례로 큐에 넣기-----------------------------");

        ArrayList<String> aList2 = new ArrayList<String>();
        aList2.add("C");
        aList2.addAll(graph.get("A"));
        System.out.println(aList2);     // C, B, C

        System.out.println("\n-----------------------------Bfs테스트-----------------------------");

        BfsAndDfs bfs = new BfsAndDfs();

        ArrayList<String> list = bfs.bfsFunc(graph, "A");
        System.out.println(list);

        System.out.println("\n-----------------------------ArrayList로 Stack역할 하기-----------------------------");

        ArrayList<String> sList = new ArrayList<String>();
        sList.add("A");
        sList.add("B");
        String sNode = sList.remove(sList.size()-1);
        System.out.println(sNode);
        System.out.println(sList);

        System.out.println("\n-----------------------------Dfs테스트-----------------------------");

        list = bfs.dfsFunc(graph, "A");
        System.out.println(list);
    }
}












