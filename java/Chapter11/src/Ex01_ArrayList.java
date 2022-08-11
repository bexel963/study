import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Ex01_ArrayList {

	public static void main(String[] args) {

		// ���� 10 ¥���� ArrayList�� ��ü list1 ����
		ArrayList list1 = new ArrayList(10);
		// ���� 5,4,2,0,1,3 �߰� (��ü ���·� �߰�)
		list1.add(new Integer(5));
		list1.add(new Integer(4));
		list1.add(new Integer(2));
		list1.add(new Integer(0));
		list1.add(new Integer(1));
		list1.add(new Integer(3));
		// list1�� ����� 1��°���� 3��° ������ ��Ҹ� ���� ���ο� ArrayList�� ��ü list2 ����.
		ArrayList list2 = new ArrayList(list1.subList(1, 4));
		// list�� ����ϴ� �޼��带 ȣ���Ͽ� list1, list2�� ������ ���
		print(list1, list2);
		// list1, list2�� ����
		Collections.sort(list1);
		Collections.sort(list2);
		// list1, list2 ���
		print(list1, list2);
		// list2�� ��ü���� list1�� ��� ���ԵǾ��ִ��� Ȯ��
		System.out.println("list1.containsAll(list2) : " + list1.containsAll(list2));
		// list2�� �������� B, C�� ���ʷ� �߰��ϰ�, 3��° �ε����� A �߰�
		list2.add("B");
		list2.add("C");
		list2.add(3, "A");
		// list1, list2 ���
		print(list1, list2);
		// list2�� 3��° �ε����� ��Ҹ� AA�� ġȯ.
		list2.set(3, "AA");
		// list1, list2 ���
		print(list1, list2);
		// list1 ���� list2�� ��ġ�� �κи� ����� ��� ����(2���� ���)
		list1.retainAll(list2);
		// list1, list2 ���
		print(list1, list2);
		// list2���� list1�� ���Ե� ��ü���� ����
		list2.removeAll(list1);
		// list1, list2 ���
		print(list1, list2);
	}
	
	// ����Ʈ ��� �޼���
	public static void print(Collection list1, Collection list2) {
		System.out.println("list1 : " + list1);
		System.out.println("list2 : " + list2);
		System.out.println();
	}

}
