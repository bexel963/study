import java.util.Vector;

class Buyer2 {
	int money = 1000;
	int bonusPoint = 0;
	
	Vector item = new Vector();
	
	void buy(Product p) {
		if(money < p.price) {
			System.out.println("�ܾ��� �����Ͽ� ������ �� �� �����ϴ�.");
			return;
		}
		item.add(p);
		money -= p.price;
		bonusPoint += p.bonusPoint;
		System.out.println(p + "��/�� �����ϼ̽��ϴ�.");
	}
	public String toString() {
		return "[money:" + money + "], [bonusPoint:" + bonusPoint + "]";
	}
	
	void refund(Product p) {
		if(item.remove(p)) {
			money += p.price;
			bonusPoint -= p.bonusPoint;
			System.out.println(p + "��/�� ��ǰ�ϼ̽��ϴ�.");
		}else {
			System.out.println("�����Ͻ� ��ǰ �� �ش� ��ǰ�� �����ϴ�.");
		}
	}
	void summary() {
		int sum = 0;
		String itemList = "";
		
		for(int i=0 ; i<item.size() ; i++) {
			Product p = (Product)item.get(i);
			sum += p.price;
			itemList += (i==0) ? "" + p : ", " + p;
		}
		System.out.println("�����Ͻ� ��ǰ�� �� �ݾ��� " + sum + "���� �Դϴ�.");
		System.out.println("�����Ͻ� ��ǰ�� " + itemList + "�Դϴ�.");
	}
}
public class Ex23 {

	public static void main(String[] args) {
		
		Buyer2 b = new Buyer2();
		
		Product tv = new Tv0();
		Product computer = new Computer();
		Product audio = new Audio();
		
		b.buy(tv);
		b.buy(computer);
		b.buy(audio);
		b.summary();
		System.out.println();
		
		b.refund(computer);
		b.summary();
	}

}
