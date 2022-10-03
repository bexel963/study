package note;

public class MyLinkedList <T> {

    private Node<T> head = null;

    class Node<T> {
        public T data;
        public Node next = null;

        public Node(T data) {
            this.data = data;
        }
    }

    public void add(T data) {
        if(head == null){
            head = new Node<T>(data);
        }else{
            Node<T> tmp = this.head;
            while(tmp.next != null) {
                tmp = tmp.next;
            }
            tmp.next = new Node<T>(data);
        }
    }
    public void add(T data, int idx) {
        if(head == null) {
            return;
        }
        if(idx == 0) {
            Node<T> newNode = new Node<T>(data);
            newNode.next = head;
            head = newNode;
        } else {
            Node<T> tmp = this.head;
            for(int i=0 ; i<idx-1 ; i++) {
                tmp = tmp.next;
            }
            Node<T> newNode = new Node<T>(data);
            newNode.next = tmp.next;
            tmp.next = newNode;
        }
    }

    public void addIs(T data, T isData) {
        if(head == null) {
            return;
        }
        Node<T> tmp = this.head;

        boolean flag = false;
        while(tmp.next != null) {
            boolean search = tmp.data.equals(isData);
            if(search) {
                Node<T> newNode = new Node<T>(data);
                newNode.next = tmp.next;
                tmp.next = newNode;
                flag = true;
                break;
            }
            tmp = tmp.next;
        }
        if(!flag){
            add(data);
        }

    }

    public void print() {
        if(head != null){
            Node<T> tmp = this.head;
            System.out.print(tmp.data + " -> ");
            while(tmp.next != null) {
                tmp = tmp.next;
                System.out.print(tmp.data + " -> ");
            }
            System.out.println();
        }
    }
}
