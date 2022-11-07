package al08;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

// 어디서부터 어디로 갔는지 표현하기 위한 클래스 (mst 경로 표시)
class Path {
    public String node1;
    public String node2;
    public int weight;

    public Path(String node1, String node2, int weight) {
        this.node1 = node1;
        this.node2 = node2;
        this.weight = weight;
    }

    public String toString() {
        return "(" + this.node1 + ", " + this.node2 + ", " + this.weight + ")";
    }
}
class Edge implements Comparable<Edge> {
    public String node;
    public int weight;

    public Edge(String node, int weight) {
        this.weight = weight;
        this.node = node;
    }

    public String toString() {
        return "(" + this.weight + ", " + this.node + ")";
    }

    @Override
    public int compareTo(Edge edge) {
        return this.weight - edge.weight;
    }
}
public class PrimImproved {

    public ArrayList<Path> improvedPrimFunc(HashMap<String, HashMap<String, Integer>> graph, String startNode) {

        ArrayList<Path> mst = new ArrayList<>();
        PriorityQueue<Edge> keys = new PriorityQueue<>();
        Edge edgeObject, poppedEdge, linkedEdge;
        HashMap<String, Edge> keysObjects = new HashMap<>();
        HashMap<String, String> mstPath = new HashMap<>();
        Integer totalWeight = 0;
        HashMap<String, Integer> linkedEdges;

        for (String key : graph.keySet()) {
            if (key == startNode) {
                edgeObject = new Edge(key, 0);
                mstPath.put(key, key);      // 해당 노드가 어떤 노드와 연결되어있는지에 대한 정보 저장
            } else {
                edgeObject = new Edge(key, Integer.MAX_VALUE);
                mstPath.put(key, null);
            }
            keys.add(edgeObject);
            // 우선순위 큐는 데이터를 넣거나 꺼낼 때 최소 값이 제일 앞에 오도록 하는 기능이 작동한다.
            //  -> 데이터를 넣거나 꺼내는 과정 없이 우선순위 큐의 요소의 내용이 업데이트 될 때 해당 요소를 삭제하고, 업데이트된 요소를 다시 넣는다.
            //  -> 이렇게 하기 위해 요소의 정보를 map형태로 하나 더 가지고 있는다.
            keysObjects.put(key, edgeObject);
        }

        while (keys.size() > 0) {
            poppedEdge = keys.poll();
            keysObjects.remove(poppedEdge.node);

            mst.add(new Path(mstPath.get(poppedEdge.node), poppedEdge.node, poppedEdge.weight));
            totalWeight += poppedEdge.weight;

            linkedEdges = graph.get(poppedEdge.node);   // 꺼낸 노드와 인접한 노드리스트 얻기
            for (String adjacent : linkedEdges.keySet()) {
                if (keysObjects.containsKey(adjacent)) {
                    linkedEdge = keysObjects.get(adjacent);

                    if (linkedEdges.get(adjacent) < linkedEdge.weight) {
                        linkedEdge.weight = linkedEdges.get(adjacent);
                        mstPath.put(adjacent, poppedEdge.node);

                        keys.remove(linkedEdge);
                        keys.add(linkedEdge);
                    }
                }
            }

        }
        System.out.println("totalWeight = " + totalWeight);
        return mst;
    }
}

















