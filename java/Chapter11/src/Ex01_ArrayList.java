import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Ex01_ArrayList {

	public static void main(String[] args) {

		// 길이 10 짜리인 ArrayList의 객체 list1 생성
		ArrayList list1 = new ArrayList(10);
		// 숫자 5,4,2,0,1,3 추가 (객체 형태로 추가)
		list1.add(new Integer(5));
		list1.add(new Integer(4));
		list1.add(new Integer(2));
		list1.add(new Integer(0));
		list1.add(new Integer(1));
		list1.add(new Integer(3));
		// list1의 요소중 1번째부터 3번째 까지의 요소를 갖는 새로운 ArrayList의 객체 list2 생성.
		ArrayList list2 = new ArrayList(list1.subList(1, 4));
		// list를 출력하는 메서드를 호출하여 list1, list2의 내용을 출력
		print(list1, list2);
		// list1, list2를 정렬
		Collections.sort(list1);
		Collections.sort(list2);
		// list1, list2 출력
		print(list1, list2);
		// list2의 객체들이 list1에 모두 포함되어있는지 확인
		System.out.println("list1.containsAll(list2) : " + list1.containsAll(list2));
		// list2의 마지막에 B, C를 차례로 추가하고, 3번째 인덱스에 A 추가
		list2.add("B");
		list2.add("C");
		list2.add(3, "A");
		// list1, list2 출력
		print(list1, list2);
		// list2의 3번째 인덱스의 요소를 AA로 치환.
		list2.set(3, "AA");
		// list1, list2 출력
		print(list1, list2);
		// list1 에서 list2와 겹치는 부분만 남기고 모두 삭제(2가지 방법)
		list1.retainAll(list2);
		// list1, list2 출력
		print(list1, list2);
		// list2에서 list1에 포함된 객체들을 삭제
		list2.removeAll(list1);
		// list1, list2 출력
		print(list1, list2);
	}
	
	// 리스트 출력 메서드
	public static void print(Collection list1, Collection list2) {
		System.out.println("list1 : " + list1);
		System.out.println("list2 : " + list2);
		System.out.println();
	}

}
