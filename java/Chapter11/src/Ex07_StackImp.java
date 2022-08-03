import java.util.ArrayList;

/*
  - stack 구현 해보기
  	- push : 객체 하나 넣고 해당 넣은 객체 반환
  	- pop : 객체 하나 꺼내고 해당 꺼낸 해당 반환
  	- peek : 객체를 꺼내지 않고 꺼낼 객체 하나 반환
  	- empty : 비어 있으면 true 반환
  	- search : 찾고자 하는 객체의 위치 반환 (배열과 달리 1부터 시작)
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
