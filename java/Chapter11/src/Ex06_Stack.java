import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Ex06_Stack {

	public static void main(String[] args) {
		// 스택 생성
		Stack s = new Stack();
		// 큐 생성
		Queue q = new LinkedList();
		
		// 스택에 0, 1, 2 추가
		s.push("0");
		s.push("1");
		s.push("2");
		// 큐에 0, 1, 2 추가
		q.offer("0");
		q.offer("1");
		q.offer("2");
		
		// 스택 하나씩 꺼내기
		System.out.println("== Stack ==");
		while(!s.empty()) {
			System.out.println("     " + s.pop());
		}
		// 큐 하나씩 꺼내기
		System.out.println("== Queue ==");
		while(!q.isEmpty()) {
			System.out.println("     " + q.poll());
		}
	}

}
