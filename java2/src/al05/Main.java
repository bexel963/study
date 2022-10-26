package al05;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.PriorityQueue;

class Edge implements Comparable<Edge> {
    public int distance;
    public String vertex;

    public Edge(int distance, String vertex) {
        this.distance = distance;
        this.vertex = vertex;
    }
    public String toString() {
        return "[vertex: " + this.vertex + ", distance: " + this.distance + "]";
    }
    @Override
    public int compareTo(Edge edge) {
        return this.distance - edge.distance;
    }   // 우선순위 큐가 잘 작동하도록....
}
public class Main {
    public static void main(String[] args) {

        // 우선순위 큐 사용 예
        // 항상 가장 작은 값이 pop() 될 수 있도록 내부적으로 자동 정렬 된다.
        PriorityQueue<Edge> queue = new PriorityQueue<>();
        queue.add(new Edge(2, "A"));
        queue.add(new Edge(5, "B"));
        queue.offer(new Edge(1, "C"));
        queue.offer(new Edge(7, "D"));
        System.out.println(queue);
        System.out.println(queue.peek());   // 맨 앞 데이터 보기 (꺼내진 않음.)
        System.out.println(queue.poll());   // 맨 앞 데이터 꺼냄.
        System.out.println(queue);          // 하나 꺼내고 나면 제일 작은 값이 제일 앞에 오도록 자동 정렬 됨.
        System.out.println(queue.size());

        System.out.println("\n-------------------------그래프를 변수로 만들기-------------------------");

        HashMap<String, ArrayList<Edge>> graph = new HashMap<String, ArrayList<Edge>>();
        graph.put("A", new ArrayList<Edge>(Arrays.asList(new Edge(8, "B"), new Edge(1,"C"), new Edge(2, "D"))));
        graph.put("B", new ArrayList<Edge>());
        graph.put("C", new ArrayList<Edge>(Arrays.asList(new Edge(5, "B"), new Edge(2, "D"))));
        graph.put("D", new ArrayList<Edge>(Arrays.asList(new Edge(3, "E"), new Edge(5, "F"))));
        graph.put("E", new ArrayList<Edge>(Arrays.asList(new Edge(1, "F"))));
        graph.put("F", new ArrayList<Edge>(Arrays.asList(new Edge(5, "A"))));

        System.out.println("\n-------------------------Hashmap의 모든 key 가져오기-------------------------");

        for(String key : graph.keySet()) {
            System.out.println(key);
            System.out.println(graph.get(key));
        }

        System.out.println("\n-------------------------Hashmap 에서 각 키에 해당하는 값, 즉 ArrayList의 모든 Edge 객체 추출하기-------------------------");

        ArrayList<Edge> nodeList = graph.get("A");
        for(int index=0 ; index<nodeList.size() ; index++) {
            System.out.println(nodeList.get(index));
        }

        System.out.println("\n-------------------------Dijkstra 테스트-------------------------");

        Dijkstra dijkstra = new Dijkstra();
        HashMap<String, Integer> map = dijkstra.sort(graph, "A");
        System.out.println(map);
    }
}
