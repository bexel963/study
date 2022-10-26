package al07;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

class Edge implements Comparable<Edge> {
    public int weight;
    public String node1;
    public String node2;

    public Edge(int weight, String node1, String node2) {
        this.weight = weight;
        this.node1 = node1;     // 본인 노드
        this.node2 = node2;     // 본인 노드와 연결된 다른 노드
    }
    public String toString() {
        return "(" + this.weight + ", " + this.node1 + ", " + this.node2 + ")";
    }
    @Override
    public int compareTo(Edge edge) {
        return this.weight - edge.weight;
    }
}
/*
    0. 모든 간선 정보를 저장(adjacentEdges)
    1. 임의의 정점을 선택, '연결된 노드 집합(connectedNodes)'에 삽입.
    2. 선택된 정점에 연결된 간선들을 간선 리스트(candidateEdgeList)에 삽입.
    3. 간선 리스트에서 최소 가중치를 가지는 간선부터 추출해서,
        - 해당 간선에 연결된 인접 정점이 '연결된 노드 집합'에 이미 들어있다면, 스킵함(cycle 발생을 막기 위함.)
        - 해당 간선에 연결된 인접 정점이 '연결된 노드 집합'에 들어 있지 않으면, 해당 간선을 선택하고, 해당 간선 정보를 '최소 신장 트리(mst)'에 삽입
            - 해당 간선에 연결된 인접 정점의 간선들 중, '연결된 노드 집합(connectedNodes)' 에 없는 노드와 연결된 간선들만 간선 리스트(candidateEdgeList)에 삽입
                * 연결된 노드 집합(connectedNodes)'에 있는 노드와 연결된 간선들을 간선 리스트에 삽입해도, 해당 간선은 스킵될 것이기 때문임.
                * 어차피 스킵될 간선을 간선 리스트(candidateEdgeList)에 넣지 않으므로 해서, 간선 리스트(candidateEdgeList)에서 최소 가중치를 가지는 간선부터
                  추출하기 위한 자료구조 유지를 위한 effort를 줄일 수 있음 (ex. 최소힙 구조 사용)
    4. 추출한 간선은 간선 리스트에서 제거
    5. 간선 리스트에 더 이상의 간선이 없을 때까지 3~4번을 반복
*/
public class PrimPath {

    public ArrayList<Edge> primFunc(String startNode, ArrayList<Edge> edges) {

        Edge currentEdge, poppedEdge, adjacentEdgeNode;
        ArrayList<String> connectedNodes = new ArrayList<String>();         // (선택된)연결된 vertex만 문자열로 저장
        ArrayList<Edge> candidateEdgeList = new ArrayList<>();              // (선택된)연결된 vertex와 연결된 간선들을 저장
        ArrayList<Edge> mst = new ArrayList<>();                            // 선택된 간선 리스트
        HashMap<String, ArrayList<Edge>> adjacentEdges = new HashMap<>();   // vertex 연결된 간선들(간선 정보)(key: vertex, value: vertex에 연결된 간선들을 배열로 저장)
        ArrayList<Edge> currentEdgeList;
        PriorityQueue<Edge> priorityQueue = new PriorityQueue<>();
        ArrayList<Edge> adjacentEdgeNodes;

        // 초기화1 : vertex들을 모두 adjacentEdges에 key값으로 설정
        for(int i=0 ; i<edges.size() ; i++) {
            currentEdge = edges.get(i);
            if(!adjacentEdges.containsKey(currentEdge.node1)) {
                adjacentEdges.put(currentEdge.node1, new ArrayList<>());
            }
            if(!adjacentEdges.containsKey(currentEdge.node2)) {
                adjacentEdges.put(currentEdge.node2, new ArrayList<>());
            }
        }
        // 초기화2 : 해당 vertex(key값)에 연결된 노드들을 adjacentEdges에 value값으로 설정
        for(int i=0 ; i<edges.size() ; i++) {
            currentEdge = edges.get(i);
            currentEdgeList = adjacentEdges.get(currentEdge.node1);
            currentEdgeList.add(new Edge(currentEdge.weight, currentEdge.node1, currentEdge.node2));
            currentEdgeList = adjacentEdges.get(currentEdge.node2);
            currentEdgeList.add(new Edge(currentEdge.weight, currentEdge.node2, currentEdge.node1));
        }
        // 초기화3
        // 3-1 : 임의로 선택된 첫 노드를 연결된 노드리스트에 넣는다.
        connectedNodes.add(startNode);
        // 3-2 : 임의로 선택된 노드와 연결되어있는 간선들을 간선리스트에 저장
        candidateEdgeList = adjacentEdges.getOrDefault(startNode, new ArrayList<>());
        // 3-3 : 간선리스트의 요소들을 우선순위 자료구조로 정렬
        for(int i=0 ; i<candidateEdgeList.size() ; i++) {
            priorityQueue.add(candidateEdgeList.get(i));
        }

        // 기능 구현
        while(priorityQueue.size() > 0) {
            poppedEdge = priorityQueue.poll();
            // 연결된 노드리스트에(처음엔 startNode 하나 들어있음) 간선리스트에서 꺼낸 노드와 연결된 노드(node2)가 있는지 확인.
            // poppedEdge.node1 이 본인 노드
            // poppedEdge.node2 가 본인 노드에 연결된 노드
            if(!connectedNodes.contains(poppedEdge.node2)) {
                // 해당 edge를 mst에 추가
                connectedNodes.add(poppedEdge.node2);
                mst.add(new Edge(poppedEdge.weight, poppedEdge.node1, poppedEdge.node2));
                // 연결된 노드랑 또 그와 연결된 노드리스트 가져오기.
                adjacentEdgeNodes = adjacentEdges.getOrDefault(poppedEdge.node2, new ArrayList<>());
                for(int i=0 ; i<adjacentEdgeNodes.size() ; i++) {
                    adjacentEdgeNode = adjacentEdgeNodes.get(i);
                    if(!connectedNodes.contains(adjacentEdgeNode.node2)) {
                        priorityQueue.add(adjacentEdgeNode);
                    }
                }
            }
        }
        return mst;
    }
}












