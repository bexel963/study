import java.util.PriorityQueue;
import java.util.Queue;

// PriorityQueue�� ���� ������ ������� �켱 ������ ������ ���� ���ʷ� ������.

public class Ex11_PriorityQueue {

	public static void main(String[] args) {

		Queue q = new PriorityQueue();
		
		q.offer(3);
		q.offer(1);
		q.offer(5);
		q.offer(2);
		q.offer(4);
		System.out.println(q);
		
		Object obj = null;
		
		while((obj=q.poll())!=null) {
			System.out.println(obj);
		}
	}

}
