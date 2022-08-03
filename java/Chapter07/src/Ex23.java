import java.util.Vector;

class Buyer2 {
	int money = 1000;
	int bonusPoint = 0;
	
	Vector item = new Vector();
	
	void buy(Product p) {
		if(money < p.price) {
			System.out.println("잔액이 부족하여 물건을 살 수 없습니다.");
			return;
		}
		item.add(p);
		money -= p.price;
		bonusPoint += p.bonusPoint;
		System.out.println(p + "을/를 구입하셨습니다.");
	}
	public String toString() {
		return "[money:" + money + "], [bonusPoint:" + bonusPoint + "]";
	}
	
	void refund(Product p) {
		if(item.remove(p)) {
			money += p.price;
			bonusPoint -= p.bonusPoint;
			System.out.println(p + "를/을 반품하셨습니다.");
		}else {
			System.out.println("구입하신 제품 중 해당 제품이 없습니다.");
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
		System.out.println("구입하신 물품의 총 금액은 " + sum + "만원 입니다.");
		System.out.println("구입하신 제품은 " + itemList + "입니다.");
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
