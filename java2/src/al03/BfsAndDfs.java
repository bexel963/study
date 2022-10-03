package al03;

import java.util.ArrayList;
import java.util.HashMap;

public class BfsAndDfs {

    public ArrayList<String> bfsFunc(HashMap<String, ArrayList<String>> graph, String startNode) {

        // 1. 큐를 두 개 만든다.
        ArrayList<String> visited = new ArrayList<String>();
        ArrayList<String> needVisit = new ArrayList<String>();

        needVisit.add(startNode);
        int cnt = 0;
        // 방문할 노드가 없을 때까지 반복
        while(needVisit.size() > 0) {
            // 방문할 노드 하나 꺼냄.
            String node = needVisit.remove(0);

            // 꺼낸 노드가 방문 했었던 노드인지 확인
            if (!visited.contains(node)) {
                // 방문 했던 노드가 아니면 방문
                visited.add(node);
                needVisit.addAll(graph.get(node));
            }
            cnt++;
        }
        System.out.println(cnt);    // 노드 수 + 간선 수 만큼 반복한다.
        return visited; // visited에는 방문한 노드들이 기록이 되어있다.
    }

    public ArrayList<String> dfsFunc(HashMap<String, ArrayList<String>> graph, String startNode) {

        ArrayList<String> visited = new ArrayList<>();
        ArrayList<String> needVisit = new ArrayList<>();

        needVisit.add(startNode);

        while(needVisit.size() > 0) {
            String node = needVisit.remove(needVisit.size() - 1);
            if(!visited.contains(node)) {
                visited.add(node);
                needVisit.addAll(graph.get(node));
            }
        }
        return visited;
    }
}
