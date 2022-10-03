package ds5;

import java.util.ArrayList;
import java.util.Collections;

/*
    - java.util.Collections
    - Collections.swap(List list, int a, int b)
*/
public class MyHeap {

    public ArrayList<Integer> list = null;

    public MyHeap(Integer data) {
        list = new ArrayList<>();
        list.add(null);
        list.add(data);
    }
    public boolean insert(Integer data) {

        Integer inserted_idx, parent_idx;

        if(list == null) {
            list = new ArrayList<>();
            list.add(null);
            list.add(data);
            return true;
        }

        this.list.add(data);
        inserted_idx = this.list.size() - 1;
        while(this.moveUp(inserted_idx)) {
            parent_idx = inserted_idx / 2;
            Collections.swap(this.list, inserted_idx, parent_idx);
            inserted_idx = parent_idx;
        }
        return true;
    }

    public boolean moveUp(Integer inserted_idx) {
        if(inserted_idx <= 1) {
            return false;
        } else {
            Integer parent_idx = inserted_idx / 2;
            if(this.list.get(inserted_idx) > this.list.get(parent_idx)) {
                return true;
            } else {
                return false;
            }
        }
    }

    public boolean moveDown(Integer popped_idx) {
        Integer leftChildOfPopped_idx, rightChildOfPopped_idx;

        leftChildOfPopped_idx = popped_idx * 2;
        rightChildOfPopped_idx = popped_idx * 2 + 1;

        // CASE1: 왼쪽 자식 노드도 없을 때 (완전이진트리이기 때문에 오른쪽만 있을수는 없다.) = 자식노드가 하나도 없을 때
        if(leftChildOfPopped_idx >= this.list.size()) {
            return false;
        // CASE2: 오른쪽 자식 노드만 없을 때
        } else if(rightChildOfPopped_idx >= this.list.size()) {
            if(this.list.get(popped_idx) < this.list.get(leftChildOfPopped_idx)) {
                return true;
            } else {
                return false;
            }
        // CASE3: 왼쪽/오른쪽 자식 노드가 모두 있을 때
        } else {
            if(this.list.get(leftChildOfPopped_idx) > this.list.get(rightChildOfPopped_idx)) {
                if(this.list.get(popped_idx) < this.list.get(leftChildOfPopped_idx)) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if(this.list.get(popped_idx) < this.list.get(rightChildOfPopped_idx)) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }

    public Integer pop() {

        Integer returnedData;
        Integer popped_idx, leftChildOfPopped_idx, rightChildOfPopped_idx;
        if(this.list == null) {
            return null;
        } else {
            returnedData = this.list.get(1);
            this.list.set(1, this.list.get(this.list.size() - 1));
            this.list.remove(this.list.size() - 1);

            popped_idx = 1;

            while(this.moveDown(popped_idx)) {
                leftChildOfPopped_idx = popped_idx * 2;
                rightChildOfPopped_idx = popped_idx * 2 + 1;
                // CASE1 은 moveDown()에서 처리하기 때문에 while문 안으로 안 들어온다.
                // CASE2: 오른쪽 자식 노드만 없을 때 (세부 조건은 moveDown에서 확인됨.)
                if(rightChildOfPopped_idx >= list.size()){
                    Collections.swap(list, popped_idx, leftChildOfPopped_idx);
                    popped_idx = leftChildOfPopped_idx;
                // CASE3: 왼쪽/오른쪽 자식 노드가 모두 있을 때 (세부 조건은 moveDown에서 확인됨.)
                } else {
                    if(this.list.get(leftChildOfPopped_idx) > this.list.get(rightChildOfPopped_idx)) {
                        Collections.swap(list, popped_idx, leftChildOfPopped_idx);
                        popped_idx = leftChildOfPopped_idx;
                    } else {
                        Collections.swap(list, popped_idx, rightChildOfPopped_idx);
                        popped_idx = rightChildOfPopped_idx;
                    }
                }
            }
            return returnedData;
        }
    }




    @Override
    public String toString() {
        return list.toString();
    }
}
