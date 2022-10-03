package ds2;

public class DoubleLinkedList<T> {

    public Node<T> head = null;
    public Node<T> tail = null;
    class Node<T> {
        T data;
        Node<T> prev = null;
        Node<T> next = null;

        Node(T data) {
            this.data = data;
        }
    }
    public void addNode(T data) {
        if(head == null) {
            head = new Node<T>(data);
            tail = head;
        }else {
            Node<T> pNode = head;
            while(pNode.next != null) {
                pNode = pNode.next;
            }
            pNode.next = new Node<T>(data);
            pNode.next.prev = pNode;
            tail = pNode.next;
        }
    }
    public void print() {
        if(head == null) {
            System.out.println("노드 없음.");
            return;
        } else {
            Node<T> pNode = head;
            while(pNode != null) {
                System.out.print(pNode.data + " -> ");
                pNode = pNode.next;
            }
            System.out.println();
        }
    }
    public int searchFromeEnd(T data) {
        int cnt = -1;
        if(head == null) {
            return cnt;
        } else {
            Node<T> pNode = head;
            while(pNode != null) {
                cnt++;
                if(pNode.data.equals(data)) {
                    return cnt;
                }
                pNode = pNode.next;
            }
        }
        return -1;
    }
    public int searchFromEnd(T data) {
        int cnt = -1;
        if(tail == null) {
            return cnt;
        } else {
            Node<T> pNode = tail;
            while(pNode != null) {
                cnt++;
                if(pNode.data.equals(data)) {
                    return cnt;
                }
                pNode = pNode.prev;
            }
        }
        return -1;
    }
    public boolean insertToFront(T data, T isData) {
        if(tail == null) {
            return false;
        } else if(head.data.equals(isData)) {
            head.prev = new Node<>(data);
            head.prev.next = head;
            head = head.prev;
            return true;
        }else {
            Node<T> pNode = tail;
            while(pNode != null) {
                if(pNode.data.equals(isData)) {
                    Node<T> tmpNode = pNode.prev;
                    pNode.prev = new Node<T>(data);
                    pNode.prev.prev = tmpNode;

                    pNode.prev.next = pNode;
                    tmpNode.next = pNode.prev;
                    return true;
                }
                pNode = pNode.prev;
            }
        }
        return false;
    }
}
