import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

// Ex33 을 TreeMap으로 구현
public class Ex34_TreeMap {

	public static void main(String[] args) {

		HashMap map = new HashMap();
		
		map.put("id", "asdf");
		map.put("id2", "zxcv");
		map.put("id3", "wqer");
		map.put("id4", "gfre");
		
		Iterator it = map.entrySet().iterator();
		
		while(it.hasNext()) {
			Map.Entry entry = (Map.Entry)it.next();
			String value = (String)entry.getValue();
			System.out.println(entry.getKey() + " : " + value);
		}
	}

}
