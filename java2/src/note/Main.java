package note;

import java.sql.Array;
import java.util.*;


class SingleLinkedList<T> {

    Node<T> head = null;

    public class Node<T> {
        T data;
        Node<T> next;

        public Node(T data, Node<T> next) {
            this.data = data;
            this.next = next;
        }
    }
    // 1. 추가(끝에)
    public boolean add(T data) {

        if(head==null) {
            head = new Node<T>(data, null);
        } else {
            Node<T> pointer = head;
            while(pointer.next != null) {
                pointer = pointer.next;
            }
            pointer.next = new Node<T>(data, null);
        }

        return true;
    }
    // 2. 추가(특정 숫자 앞에)
    public boolean addPrev(T num, T data) {

        Node<T> findedNode, prevNode, addNode;
        boolean isFind = false;

        if(head == null) {
            this.add(data);
        } else if(head.data == num) {
            addNode = new Node<T>(data, head);
            head = addNode;
        }else {
            // 특정 숫자를 찾는다.
            findedNode = head;
            prevNode = head;
            while(findedNode != null) {
                if(findedNode.data == num) {
                    isFind = true;
                    break;
                }
                prevNode = findedNode;
                findedNode = findedNode.next;
            }
            if(!isFind) {
                return false;
            }
            // 추가할 노드의 next로 특정 숫자가진 노드를 참조한다.
            addNode = new Node<T>(data, findedNode);
            // 원래 특정 숫자 앞에 있던 노드의 next로 추가한 노드를 참조한다.
            prevNode.next = addNode;
        }
        return true;
    }
    // 3. 추가(특정 숫자 뒤에)
    public boolean addNext(T num, T data) {

        Node<T> addNode;
        boolean isFind = false;

        if(head == null) {
            this.add(data);
        } else if(head.data == num){
            addNode = new Node<T>(data, head.next);
            head.next = addNode;
        } else {
            Node<T> findedNode = head;
            // data가 num인 노드를 찾는다.
            while(findedNode != null) {
                if(findedNode.data == num) {
                    isFind = true;
                    break;
                }
                findedNode = findedNode.next;
            }
            if(!isFind) return false;
            // 추가할 노드의 next로 data가 num인 노드의 뒤에 있는 노드를 참조한다.
            addNode = new Node<T>(data, findedNode.next);
            // data가 num인 노드의 next로 추가할 노드를 참조한다.
            findedNode.next = addNode;
        }
        return true;
    }
    // 4. 추가(특정 인덱스에)
    public boolean add(int idx, T data) {

        Node<T> addNode;

        if(head == null) {
            this.add(data);
        } else if(idx == 0) {
            addNode = new Node<T>(data, head);
            head = addNode;
        }else {
            Node<T> pointer = head;
            for(int i=1 ; i<idx ; i++) {
                pointer = pointer.next;
            }
            if(pointer == null) return false;
            addNode = new Node<T>(data, pointer.next);
            pointer.next = addNode;
        }

        return true;
    }

    // 5. 삭제
    public Node<T> remove(T data) {

        if(head == null) {
            return null;
        } else if(head.data == data) {
            Node<T> findedNode = head;
            head = head.next;
            return findedNode;
        }else {
            Node<T> prevNode = head;
            Node<T> findedNode = head;
            boolean isFind = false;

            while(findedNode != null) {
                if(findedNode.data == data) {
                    isFind = true;
                    break;
                }
                prevNode = findedNode;
                findedNode = findedNode.next;
            }
            if(!isFind) return null;

            prevNode.next = findedNode.next;

            return findedNode;
        }
    }
    public void print() {
        Node pointer = head;
        while(pointer != null) {
            System.out.print(pointer.data + " -> ");
            pointer = pointer.next;
        }
        System.out.println();
    }
}
class DoubleLinkedList<T> {

    public Node<T> head, tail;

    public class Node<T> {
        public T data;
        public Node<T> prev = null;
        public Node<T> next = null;

        public Node(T data) {
            this.data = data;
        }
    }

    public boolean add(T data) {

        if(head==null) {
            head = new Node<T>(data);
        } else {
            Node<T> pointer = head;
            while(pointer.next!=null) {
                pointer = pointer.next;
            }
            pointer.next = new Node<T>(data);
            pointer.next.prev = pointer;
            tail = pointer.next;
        }

        return true;
    }

    public boolean add(T num, T data) {

        Node<T> addNode;

        if(head==null) {
            this.add(data);
        } else if(head.data == data) {
            addNode = new Node<T>(data);
            addNode.next = head;
            head.prev = addNode;
            head = addNode;
            tail = addNode.next;
        } else {
            Node<T> findedNode = searchNode(num);
            addNode = new Node<>(data);
            if(findedNode.next == null) {
                findedNode.next = addNode;
                addNode.prev = findedNode;
                tail = addNode;
                System.out.println(tail.data);
            } else {
                addNode.next = findedNode.next;
                findedNode.next.prev = addNode;
                findedNode.next = addNode;
                addNode.prev = findedNode;
            }
        }
        return true;
    }

    public Node<T> searchNode(T num) {
        Node<T> searchedNode = head;
        while(searchedNode != null) {
            if(searchedNode.data == num) {
                break;
            }
            searchedNode = searchedNode.next;
        }
        return searchedNode;
    }

    public void print() {
        Node<T> pointer = head;
        while(pointer!=null) {
            System.out.print(pointer.data + " -> ");
            pointer = pointer.next;
        }
        System.out.println();
    }
    public void printReverse() {
        Node<T> pointer = tail;
        while(pointer!=null) {
            System.out.print(pointer.data + " -> ");
            pointer = pointer.prev;
        }
        System.out.println();
    }
}
public class Main {

    public static void main(String[] args) {



    }

}









