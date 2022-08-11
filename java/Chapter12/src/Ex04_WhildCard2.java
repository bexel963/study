import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class AppleComp implements Comparator<Apple> {
	
	public int compare(Apple t1, Apple t2) {
		return t2.weight - t1.weight;
	}
}
class GrapeComp implements Comparator<Grape> {
	
	public int compare(Grape t1, Grape t2) {
		return t2.weight - t1.weight;
	}
}
class FruitComp implements Comparator<Fruit> {
	
	public int compare(Fruit t1, Fruit t2) {
		return t1.weight - t2.weight;
	}
}
public class Ex04_WhildCard2 {

	public static void main(String[] args) {

//		public static <T> void sort(List<T> list, Comparator<? super T> c) {
//	        list.sort(c);
//	    }
		
		FruitBox<Apple> appleBox = new FruitBox<Apple>();
		FruitBox<Grape> grapeBox = new FruitBox<Grape>();
		
		appleBox.add(new Apple("GreenApple", 300));
		appleBox.add(new Apple("GreenApple", 100));
		appleBox.add(new Apple("GreenApple", 200));
		grapeBox.add(new Grape("GreenGrape", 400));
		grapeBox.add(new Grape("GreenGrape", 300));
		grapeBox.add(new Grape("GreenGrape", 200));
		
		Collections.sort(appleBox.getList(), new AppleComp());
		Collections.sort(grapeBox.getList(), new GrapeComp());
		System.out.println(appleBox);
		System.out.println(grapeBox);
		System.out.println();
		Collections.sort(appleBox.getList(), new FruitComp());
		Collections.sort(grapeBox.getList(), new FruitComp());
		System.out.println(appleBox);
		System.out.println(grapeBox);
		System.out.println();
	}

}
