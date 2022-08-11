import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class Ex32_PhonBook {
	
	public static HashMap phoneBook = new HashMap();
	
	public static void main(String[] args) {

		regisPhone("ģ��", "���ڹ�", "010-111-1111");
		regisPhone("ģ��", "���ڹ�", "010-222-2222");
		regisPhone("ģ��", "���ڹ�", "010-333-3333");
		regisPhone("ȸ��", "��븮", "010-444-4444");
		regisPhone("ȸ��", "��븮", "010-555-5555");
		regisPhone("ȸ��", "�ڴ븮", "010-666-6666");
		regisPhone("ȸ��", "�̰���", "010-777-7777");
		regisPhone("��Ź", "010-888-8888");
		
		printPhoneBook();
	}
	
	public static void regisPhone(String group, String name, String phone) {
		
		if(phoneBook.containsKey(group)) {
			HashMap subMap = (HashMap)phoneBook.get(group);
			subMap.put(phone, name);
		}else {
			phoneBook.put(group, new HashMap());
			HashMap subMap = (HashMap)phoneBook.get(group);
			subMap.put(phone, name);
		}
	}
	
	public static void regisPhone(String name, String phone) {
		
		regisPhone("��Ÿ", name, phone);
	}
	
	public static void printPhoneBook() {
		
		Set set = phoneBook.entrySet();
		Iterator phoneBookIt = set.iterator();
		while(phoneBookIt.hasNext()) {
			Map.Entry entry = (Map.Entry)phoneBookIt.next();
			
			Set subSet = ((HashMap) entry.getValue()).entrySet();
			Iterator subIt = subSet.iterator();
			
			int cnt = subSet.size();
			
			System.out.println("* " + entry.getKey() + "[" + cnt + "]");
			while(subIt.hasNext()) {
				Map.Entry subEntry = (Map.Entry)subIt.next();
				System.out.println(subEntry.getValue() + "  " + subEntry.getKey());
			}
			System.out.println();
		}
	}
	

}



















