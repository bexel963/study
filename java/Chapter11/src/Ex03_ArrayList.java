import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

// 인터페이스 List를 구현하는 MyArrayList 클래스 작성하기

class MyArrayList implements List {
	
	static final int INITSIZE = 10;
	
	private Object[] objArr;
	private int index = 0;
	
	MyArrayList(int capacity) {
		objArr = new Object[capacity];
	}
	MyArrayList() {
		this(INITSIZE);
	}
	public void ensureCapacity(int minCapacity) {
		
	}
	public boolean add(Object obj) {
		if(index==objArr.length) {
			System.out.println("배열의 길이를 늘립니다.");
			Object[] newArr = new Object[objArr.length*2]; 
			for(int i=0 ; i<objArr.length ; i++) {
				newArr[i] = objArr[i];
			}
			objArr = newArr;
			System.out.println("새로운 배열의 길이 : " + objArr.length);
		}
		objArr[index] = obj;
		++index;

		return true;
	}
	public Object get(int index) {
		Object obj = null;
		try {
			obj = objArr[index];
		} catch(Exception e){
			System.out.println("인덱스 에러");
		}
		return obj;
		
	}
	public Object remove(int index) {
		if(index > objArr.length)
			return null;
		for(int i=index ; i<objArr.length-1 ; i++) {
			objArr[i] = objArr[i+1];
		}
		objArr[objArr.length-1] = null;
		
		return objArr;
	}
	public boolean remove(Object obj) {
		for(int i=0 ; i<objArr.length ; i++) {
			if(obj.equals(objArr[i])) {
				System.out.println(obj + "있음.");
				for(int j=i ; j<objArr.length-1 ; j++) {
					objArr[j] = objArr[j+1];
				}
				objArr[objArr.length-1] = null;
				return true;
			}
		}
		return false;
	}
	public void trimTosize() {
		
	}
	private void setCapacity(int capacity) {
		
	}
	public void clear() {
		for(int i=0 ; i<objArr.length ; i++) {
			objArr[i] = null;
		}
		index = 0;
	}
	public Object[] toArray() {
		
		return null;
	}
	public boolean isEmpty() {
		for(int i=0 ; i<objArr.length ; i++) {
			if(objArr[i]!=null)
				return false;
		}
		return true;
	}
	public int capacity() {
		
		return objArr.length;
	}
	public int size() {
		int i=0;
		int cnt=0;
		while(objArr[i] != null) {
			++cnt;
			++i;
			if(i>objArr.length-1)
				break;
		}
		return cnt;
	}
	public boolean contains(Object o) {
		
		return false;
	}
	public Iterator iterator() {
		
		return null;
	}
	public Object[] toArray(Object[] a) {
		
		return null;
	}
	public boolean containsAll(Collection c) {
		
		return false;
	}
	public boolean addAll(Collection c) {
		
		return false;
	}
	public boolean addAll(int index, Collection c) {
		
		return false;
	}
	public boolean removeAll(Collection c) {
		
		return false;
	}
	public boolean retainAll(Collection c) {
		
		return false;
	}
	public Object set(int index, Object element) {
		
		return null;
	}
	public void add(int index, Object element) {
		
	}
	public int indexOf(Object o) {
		
		return 0;
	}
	public int lastIndexOf(Object o) {
		
		return 0;
	}
	public ListIterator listIterator() {
		
		return null;
	}
	public ListIterator listIterator(int index) {
		
		return null;
	}
	public List subList(int fromIndex, int toIndex) {
		
		return null;
	}
	
	public void print(List list) {
		
		System.out.println(Arrays.toString(objArr));
	}
	
	
}
public class Ex03_ArrayList {

	public static void main(String[] args) {

		MyArrayList list = new MyArrayList(5);
		
		System.out.println(list.size());
		
		for(int i=0 ; i<10 ; i++) {
			list.add(i);
		}
		list.print(list);
		System.out.println("용량 : " + list.capacity());
		System.out.println("길이 : " + list.size());
		
		System.out.println(list.get(3));
		list.remove(3);
		list.remove(3);
		list.remove(0);
		list.print(list);
		
		list.remove(new Integer(2));
		list.print(list);
		System.out.println("길이 : " + list.size());
		
		list.clear();
		list.print(list);
		System.out.println(list.isEmpty());
		
		for(int i=0 ; i<10 ; i++) {
			list.add(i);
		}
		list.print(list);
		for(int i=0 ; i<list.size(); i++) {
			list.remove(i);
		}
		list.print(list);
	}

}
