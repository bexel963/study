class Product {
	int price;
	int bonusPoint;
	
	Product(int price){
		this.price = price;
		bonusPoint = (int)(price/10.0);
	}
}
class Tv0 extends Product {
	Tv0() {
		super(100);
	}

	@Override
	public String toString() {
		return "Tv";
	}
}
class Computer extends Product {
	Computer() {
		super(200);
	}

	@Override
	public String toString() {
		return "Computer";
	}
}
class Audio extends Product {
	Audio() {
		super(50);
	}
	public String toString() {
		return "Audio";
	}
}
class Buyer {
	int money = 1000;
	int bonusPoint = 0;
	Product[] item = new Product[10];
	int i = 0;
	
	void buy(Product p) {
		if(money < p.price) {
			System.out.println("�ܾ��� �����Ͽ� ������ �� �� �����ϴ�.");
			return;
		}
		item[i++] = p;
		money -= p.price;
		bonusPoint += p.bonusPoint;
		System.out.println(p + "��/�� �����ϼ̽��ϴ�.");
	}
	public String toString() {
		return "[money:" + money + "], [bonusPoint:" + bonusPoint + "]";
	}
	
	void summary() {
		int sum = 0;
		String itemList = "";
		
		for(int i=0 ; i<item.length ; i++) {
			if(item[i]==null)
				break;
			sum += item[i].price;
			itemList += item[i] + ", ";
		}
		System.out.println("�����Ͻ� ��ǰ�� �� �ݾ��� " + sum + "���� �Դϴ�.");
		System.out.println("�����Ͻ� ��ǰ�� " + itemList + "�Դϴ�.");
	}
}
public class Ex21 {

	public static void main(String[] args) {

		Buyer b = new Buyer();
		System.out.println(b);
		System.out.println();
		
		b.buy(new Tv0());
		System.out.println(b);
		
		System.out.println();
		b.buy(new Computer());
		System.out.println(b);
	}

}
