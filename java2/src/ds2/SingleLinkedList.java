package ds2;

public class SingleLinkedList<T> {

    public Node<T> head = null;

    public class Node<T> {
        T data;
        Node<T> next = null;

        public Node(T data) {
            this.data = data;
        }
    }
    public void addNode(T data) {
        if(head == null) {
            head = new Node<T>(data);
        }else {
            Node<T> tmpNode = this.head;
            while(tmpNode.next != null) {
                tmpNode = tmpNode.next;
            }
            tmpNode.next = new Node<T>(data);
        }
    }
    public Node<T> searchNode(T isData) {
        if(head == null) {
            return null;
        } else {
            Node<T> tmpNode = this.head;
            while(tmpNode != null) {
                if(tmpNode.data.equals(isData)) {
                    return tmpNode;
                } else {
                    tmpNode = tmpNode.next;
                }
            }
            return null;
        }
    }

    public int size() {
        int cnt = 0;
        if(head == null) {
            return 0;
        }else {
            Node<T> tmpNode = this.head;
            while(tmpNode.next != null) {
                tmpNode = tmpNode.next;
                cnt++;
            }
        }
        return cnt;
    }
    public int searchNodeIdx(T isData) {
        int idx = 0;
        if(head == null) {
            return -1;
        } else {
            Node<T> tmpNode = this.head;
            while(tmpNode != null) {
                if(tmpNode.data.equals(isData)){
                    return idx;
                } else {
                    idx++;
                    tmpNode = tmpNode.next;
                }
            }
            return -1;
        }
    }
/*
    public void removeNode(T data) {
        int idx = searchNodeIdx(data);
        if(idx == -1 || this.head == null) {
            System.out.println("삭제하려는 값이 없음");
            return;
        }else if(idx == 0) {
            this.head = this.head.next;
        } else {
            Node<T> afterNode = searchNode(data).next;
            Node<T> tmpNode = this.head;
            for(int i=1 ; i<idx ; i++) {
                tmpNode = tmpNode.next;
            }
            if(this.size() == idx){
                tmpNode.next = null;
            } else {
                tmpNode.next = afterNode;
            }

        }
    }
 */
    public boolean removeNode(T data) {
        if(this.head == null) {
            return false;
        } else {
            if(head.next == data) {
                head = head.next;
            } else {
                Node<T> tmpNode = this.head;
                while(tmpNode.next != null) {
                    if(tmpNode.next.data == data) {
                        tmpNode.next = tmpNode.next.next;
                        return true;
                    }
                    tmpNode = tmpNode.next;
                }
            }
            return false;
        }
    }
    public void inAddNode(T data, T isData) {
        Node<T> searchedNode = searchNode(isData);
        if(head == null || searchedNode == null) {
            this.addNode(data);
        } else {
            Node<T> newNode = new Node<>(data);
            newNode.next = searchedNode.next;
            searchedNode.next = newNode;
        }
    }
    public void printList() {
        if(head != null){
            Node<T> tmpNode = this.head;
            System.out.print(tmpNode.data + " -> ");
            while(tmpNode.next != null) {
                tmpNode = tmpNode.next;
                System.out.print(tmpNode.data + " -> ");
            }
        }
        System.out.println();
    }

    public void printListAll() {
        if(head != null){
            Node<T> tmpNode = this.head;
            System.out.print(tmpNode.data + "(" + tmpNode + ") -> ");
            while(tmpNode.next != null) {
                tmpNode = tmpNode.next;
                System.out.print(tmpNode.data + "(" + tmpNode + ") -> ");
            }
        }
        System.out.println();
    }
}
