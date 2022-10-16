package al05;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

public class Dijkstra {

    public HashMap<String, Integer> sort(HashMap<String, ArrayList<Edge>> graph, String start) {

        // 1. 초기화
        //      - 첫 정점을 기준으로 배열을 선언하여 첫 정점에서 각 정점까지의 거리를 저장
        //          - 초기에는 첫 정점의 거리는 0, 나머지는 무한대로 저장(inf 라고 표현함)
        HashMap<String, Integer> distances = new HashMap<String, Integer>();    // 거리 저장 배열
        for(String key : graph.keySet()) {
            distances.put(key, Integer.MAX_VALUE);
        }
        distances.put(start, 0);

        PriorityQueue<Edge> priorityQueue = new PriorityQueue<>();
        priorityQueue.add(new Edge(distances.get(start), start));

        // 알고리즘 작성
        ArrayList<Edge> nodeList;
        Edge edgeNode;
        int currentDistance;
        String currentNode;
        while(priorityQueue.size() > 0) {
            edgeNode = priorityQueue.poll();
            currentDistance = edgeNode.distance;
            currentNode = edgeNode.vertex;

            if(distances.get(currentNode) < currentDistance) {
                continue;
            }

            nodeList = graph.get(currentNode);  // currentNode와 인접한 Edge 목록
            Edge adjacentNode;                  // currentNode와 인접한 Edge
            String adjacent;                    // Edge의 vertex
            int weight;                         // Edge의 가중치
            int distance;                       // Edge의 가중치와 currentNode의 가중치의 합
            for(int index=0 ; index<nodeList.size() ; index++) {
                adjacentNode = nodeList.get(index);
                adjacent = adjacentNode.vertex;
                weight = adjacentNode.distance;
                distance = currentDistance + weight;

                if(distance < distances.get(adjacent)) {
                    distances.put(adjacent, distance);
                    priorityQueue.add(new Edge(distance, adjacent));
                }
            }
        }
        return distances;
    };
}
















