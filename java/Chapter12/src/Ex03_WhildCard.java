
class Juice {
	String name;
	
	Juice(String name) {
		this.name = name + "<Juice>";		
	}
	public String toString() {
		return name;
	}
}
class Juicer {
	static Juice makeJuice(FruitBox<? extends Fruit> box) {
		String tmp = "";
		
		for(Fruit f : box.getList()) {
			tmp += f + " ";
		}
		return new Juice(tmp);
	}
}
public class Ex03_WhildCard {

	public static void main(String[] args) {

		FruitBox<Fruit> fruitBox = new FruitBox<Fruit>();
		FruitBox<Apple> appleBox = new FruitBox<Apple>();
		
		fruitBox.add(new Apple());
		fruitBox.add(new Grape());
		appleBox.add(new Apple());
		appleBox.add(new Apple());
		
		System.out.println(Juicer.makeJuice(fruitBox));
		System.out.println(Juicer.makeJuice(appleBox));
		
	}

}
