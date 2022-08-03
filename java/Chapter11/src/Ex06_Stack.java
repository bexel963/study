import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Ex06_Stack {

	public static void main(String[] args) {
		// ���� ����
		Stack s = new Stack();
		// ť ����
		Queue q = new LinkedList();
		
		// ���ÿ� 0, 1, 2 �߰�
		s.push("0");
		s.push("1");
		s.push("2");
		// ť�� 0, 1, 2 �߰�
		q.offer("0");
		q.offer("1");
		q.offer("2");
		
		// ���� �ϳ��� ������
		System.out.println("== Stack ==");
		while(!s.empty()) {
			System.out.println("     " + s.pop());
		}
		// ť �ϳ��� ������
		System.out.println("== Queue ==");
		while(!q.isEmpty()) {
			System.out.println("     " + q.poll());
		}
	}

}
