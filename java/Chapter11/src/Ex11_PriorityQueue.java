import java.util.PriorityQueue;
import java.util.Queue;

// PriorityQueue는 저장 순서와 상관없이 우선 순위가 높은거 부터 차례로 꺼낸다.

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
