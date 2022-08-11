import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class Ex33_printBar {

	// 한정된 범위 내에 있는 순차적인 값들의 빈도수는 배열을 이용하지만, 이처럼 한정되지 않은 범위의 비순차적인 값들의 빈도수는 map을 이용해서 구할 수 있다.
	
	public static void main(String[] args) {

		String[] data = { "A", "K", "A", "K", "D", "K", "A", "K", "K", "K", "Z", "D" };
		
		HashMap map = new HashMap();
		
		for(int i=0 ; i<data.length ; i++) {
			if(map.containsKey(data[i])) {
				Integer cnt = (Integer)map.get(data[i]);
				int cntInt = cnt.intValue();
				map.put(data[i], ++cntInt);
			}else {
				map.put(data[i], new Integer(1));
			}
		}
		
		Set set = map.entrySet();
		Iterator it = set.iterator();
		while(it.hasNext()) {
			Map.Entry e = (Map.Entry)it.next();
			System.out.println(e.getKey() + " : " + print(e));
		}
		
	}
	
	public static String print(Map.Entry e) {
		
		char[] arr = null;

		arr = new char[(int)e.getValue()];
		for(int i=0 ; i<arr.length ; i++) {
			arr[i] = '#';
		}

		return (new String(arr)) + " " + arr.length;
	}
	
}
