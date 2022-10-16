package al06;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

class Edge implements Comparable<Edge> {
    public int weight;
    public String nodeV;
    public String nodeU;

    Edge(int weight, String nodeV, String nodeU) {
        this.weight = weight;
        this.nodeV = nodeV;
        this.nodeU = nodeU;
    }
    public String toString() {
        return "(" + this.weight + ", " + this.nodeV + ", " + this.nodeU + ")";
    }
    @Override
    public int compareTo(Edge edge) {
        return this.weight - edge.weight;
    }
}
public class Mst {
    HashMap<String, String> parent = new HashMap<>();   // 노드 -> 부모노드
    HashMap<String, Integer> rank = new HashMap<>();    // 노드 -> 높이(rank)

    // 노드의 부모 찾기
    public String find(String node) {
        // path compression 기법
        if(parent.get(node) != node) {
            parent.put(node, find(parent.get(node)));
        }
        return parent.get(node);
    }
    // 트리 합치기
    public void union(String nodeV, String nodeU) {
        String root1 = find(nodeV);
        String root2 = find(nodeU);

        // union-by-rank 기법
        if(rank.get(root1) > rank.get(root2)) {
            parent.put(root2, root1);
        } else {
            parent.put(root1, root2);
            if(rank.get(root1) == rank.get(root2)) {
                rank.put(root2, rank.get(root2) + 1);
            }
        }
    }
    // 초기화
    public void makeSet(String node) {
        parent.put(node, node);
        rank.put(node, 0);
    }
    // Mst알고리즘 구현
    public ArrayList<Edge> kruskalFunc(ArrayList<String> vertices, ArrayList<Edge> edges) {
        ArrayList<Edge> mst = new ArrayList<Edge>();
        Edge currentEdge;

        // 1. 초기화
        for(int index=0 ; index<vertices.size() ; index++) {
            makeSet(vertices.get(index));
        }
        // 2. 간선 weight 기반 sorting
        Collections.sort(edges);
        for(int index=0 ; index<edges.size() ; index++) {
            // 현재 상황에서 최선의 정책을 선택 (탐욕알고리즘)
            currentEdge = edges.get(index);
            // 부모가 다르면 합쳐도 사이클이 생기지 않는다.
            if(find(currentEdge.nodeV) != find(currentEdge.nodeU)) {
                union(currentEdge.nodeV, currentEdge.nodeU);
                mst.add(currentEdge);
            }
        }

        return mst;
    }
}























