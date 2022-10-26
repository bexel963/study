package al07;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {

        PriorityQueue<Edge> priorityQueue = new PriorityQueue<>();
        priorityQueue.add(new Edge(2, "A", "B"));
        priorityQueue.add(new Edge(5, "B", "D"));
        priorityQueue.add(new Edge(3, "C", "A"));

        while(priorityQueue.size() > 0) {
            System.out.println(priorityQueue.poll());
        }
        // HashMap에 특정 키 존재 여부 확인
        HashMap<String, ArrayList<Edge>> graph = new HashMap<>();
        graph.put("A", new ArrayList<>());
        graph.put("B", new ArrayList<>());
        System.out.println(graph.containsKey("B"));

        // 찾는 키에 대한 값이 없을 때, 디폴트 값 반환하기
        System.out.println(graph.getOrDefault("C", new ArrayList<>()));

        System.out.println("\n-------------------------프림 테스트-------------------------\n");

        ArrayList<Edge> myEdges = new ArrayList<>();
        myEdges.add(new Edge(7, "A", "B"));
        myEdges.add(new Edge(5, "A", "D"));
        myEdges.add(new Edge(8, "B", "C"));
        myEdges.add(new Edge(9, "B", "D"));
        myEdges.add(new Edge(7, "D", "E"));
        myEdges.add(new Edge(5, "C", "E"));
        myEdges.add(new Edge(7, "B", "E"));
        myEdges.add(new Edge(6, "D", "F"));
        myEdges.add(new Edge(8, "E", "F"));
        myEdges.add(new Edge(9, "E", "G"));
        myEdges.add(new Edge(11, "F", "G"));

        PrimPath pp = new PrimPath();
        System.out.println(pp.primFunc("A", myEdges));



    }
}
