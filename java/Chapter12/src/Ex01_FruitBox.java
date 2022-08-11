import java.util.ArrayList;

interface Eatable { }

class Fruit implements Eatable{
	
	protected String name;
	protected int weight;
	
	Fruit() { }
	Fruit(String name, int weight){
		this.name = name;
		this.weight = weight;
	}
	public String toString() {
		return name + "(" + weight + ")";
	}
}
class Apple extends Fruit {
	Apple() { }
	Apple(String name, int weight){
		super(name, weight);
	}
}
class Grape extends Fruit {
	Grape() { }
	Grape(String name, int weight){
		super(name, weight);
	}
}
class Toy {
	public String toString() {
		return "Toy";
	}
}
class Box<T> {
	
	ArrayList<T> list = new ArrayList<T>();
	
	public void add(T item) {
		list.add(item);
	}
	public T get(int i) {
		return list.get(i);
	}
	ArrayList<T> getList() {
		return list;
	}
	public int size() {
		return list.size();
	}
	public String toString() {
		return list.toString();
	}
}
public class Ex01_FruitBox {

	public static void main(String[] args) {

		Box<Fruit> fruitBox = new Box<Fruit>();
		Box<Apple> appleBox = new Box<Apple>();
		Box<Grape> grapeBox = new Box();
		Box<Toy> toyBox = new Box();
		
		fruitBox.add(new Apple());
		fruitBox.add(new Grape());
		
		appleBox.add(new Apple());
		appleBox.add(new Apple());
//		appleBox.add(new Toy());
		
		toyBox.add(new Toy());
//		toyBox.add(new Apple());
		
		System.out.println(fruitBox);
		System.out.println(appleBox);
		System.out.println(toyBox);
		
	}

}










