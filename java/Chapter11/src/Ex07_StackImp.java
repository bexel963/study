import java.util.ArrayList;

/*
  - stack ���� �غ���
  	- push : ��ü �ϳ� �ְ� �ش� ���� ��ü ��ȯ
  	- pop : ��ü �ϳ� ������ �ش� ���� �ش� ��ȯ
  	- peek : ��ü�� ������ �ʰ� ���� ��ü �ϳ� ��ȯ
  	- empty : ��� ������ true ��ȯ
  	- search : ã���� �ϴ� ��ü�� ��ġ ��ȯ (�迭�� �޸� 1���� ����)
 */
class MyStack {
	
	ArrayList list = new ArrayList(5);
	
	public Object push(Object o) {
		
		return list.add(o);
	}
	public Object pop() {
		if(!empty())
			return list.remove(list.size()-1);
		return null;
	}
	public Boolean empty() {
		
		if(list.size()==0) {
			return true;
		}
		return false;
	}
	public Object peek() {
		
		return list.get(list.size()-1);
	}
	public int search(Object o) {
		
		return list.indexOf(o);
	}
	@Override
	public String toString() {
		return "list=" + list;
	}
	
}
public class Ex07_StackImp {

	public static void main(String[] args) {

		MyStack ms = new MyStack();
		
		ms.push("a");
		ms.push("b");
		ms.push("c");
		ms.push("d");

		System.out.println(ms);
		System.out.println(ms.peek());
		System.out.println(ms.search("c"));
		
	}

}
