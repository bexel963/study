import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

class MyVector implements List {
	
	Object[] data = null;
	int capacity = 0;	
	int size = 0;
	
	public MyVector(int capacity) {
		if(capacity < 0) {
			throw new IllegalArgumentException("유효하지 않은 값입니다. : " + capacity);
		}
		this.capacity = capacity;
		data = new Object[capacity];
	}
	public MyVector() {
		this(10);
	}
	// 최소한의 저장공간을 확보하는 메서드
	public void ensureCapacity(int minCapacity) {
		if(minCapacity - data.length > 0)
			setCapacity(minCapacity);
	}
	// 용량 세팅
	private void setCapacity(int capacity) {
		if(this.capacity==capacity) return;	// 크기가 같으면 변경하지 않는다.
		
		Object[] tmp = new Object[capacity];
		System.arraycopy(data, 0, tmp, 0, size);
		data = tmp;
		this.capacity = capacity;
	}
	public boolean add(Object obj) {
		ensureCapacity(size+1);
		data[size++] = obj;
		return true;
	}
	public Object get(int index) {
		if(index < 0 || index >= size)
			throw new IndexOutOfBoundsException("범위를 벗어났습니다.");
		return data[index];
	}
	public Object remove(int index) {
		Object oldObj = null;
		if(index < 0 || index >= size)
			throw new IndexOutOfBoundsException("범위를 벗어났습니다.");
		oldObj = data[index];
		
		// 삭제하고자 하는 객체가 마지막 객체가 아니라면, 배열복사를 통해 빈자리를 채워줘야한다.
		if(index != size-1) {
			System.arraycopy(data, index+1, data, index, size-index-1);
		}
		// 마지막 데이터를 null로 한다. 배열은 0부터 시작하므로 마지막 요소는 index가 size-1 이다.
		data[size-1] = null;
		size--;
		return oldObj;
		
	}
	public boolean remove(Object obj) {
		for(int i=0 ; i<size ; i++) {
			if(obj.equals(data[i])) {
				remove(i);
				return true;
			}
		}
		return false;
	}
	public void trimToSize() {
		setCapacity(size);
	}
	public void clear() {
		for(int i=0 ; i<size ; i++) {
			data[i] = null;
		}
		size = 0;
	}
	public Object[] toArray() {
		Object[] result = new Object[size];
		System.arraycopy(data, 0, result, 0, size);
		
		return result;
	}
	public boolean isEmpty() {
		return size==0;
	}
	public int capacity() {
		return capacity;
	}
	public int size() {
		return size;
	}
	@Override
	public boolean contains(Object o) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public Iterator iterator() {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public Object[] toArray(Object[] a) {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public boolean containsAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public boolean addAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public boolean addAll(int index, Collection c) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public boolean removeAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public boolean retainAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public Object set(int index, Object element) {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public void add(int index, Object element) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public int indexOf(Object o) {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	public int lastIndexOf(Object o) {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	public ListIterator listIterator() {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public ListIterator listIterator(int index) {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public List subList(int fromIndex, int toIndex) {
		// TODO Auto-generated method stub
		return null;
	}
	
	
}
class IteratorImp extends MyVector implements Iterator{

	int cursor = 0;		// 앞으로 읽어 올 요소의 위치를 저장하는데 사용
	int lastRet = -1;	// 마지막으로 읽어 온 요소의 위치를 저장하는데 사용
	
	IteratorImp(int capacity){
		super(capacity);
	}
	IteratorImp(){
		this(10);
	}
	public String toString() {
		String tmp = "";
		Iterator it = iterator();
		
		for(int i=0 ; it.hasNext() ; i++) {
			if(i!=0) tmp += ", ";
			tmp += it.next();
		}
		return "[" + tmp + "]";
	}
	public Iterator iterator() {
		cursor = 0;
		lastRet = -1;
		return this;
	}
	public boolean hasNext() {
		return cursor != size();
	}
	public Object next() {
		Object next = get(cursor);
		lastRet = cursor++;
		return next;
	}
	public void remove() {
		// 더이상 삭제할 것이 없으면 예외 발생
		if(lastRet == -1) {
			throw new IllegalStateException();
		}else {
			remove(lastRet);
			cursor--;			// 삭제 후 cursor 위치 감소
			lastRet = -1;		// lastRet의 값을 초기화
		}
	}
}
public class Ex16_17_IteratorImpTest {
	public static void main(String[] args) {
		
		IteratorImp imp = new IteratorImp();
		imp.add("0");
		imp.add("1");
		imp.add("2");
		imp.add("3");
		imp.add("4");
		
		System.out.println("삭제 전 : " + imp);
		Iterator it = imp.iterator();
		it.next();
		it.remove();
		it.next();
		it.remove();
		System.out.println("삭제 후 : " + imp);
	}
}













