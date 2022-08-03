class Car {
	String color;
	int door;
	
	void drive() {
		System.out.println("drive, brrr~~~");
	}
	void stop() {
		System.out.println("stop!!!");
	}
}
class FireEngine extends Car {
	void water() {
		System.out.println("water");
	}
}
public class Ex15_polymorphism {

	public static void main(String[] args) {

		Car car = null;
		FireEngine fe = new FireEngine();
		FireEngine fe2 = null;
		
		car = fe;
		car.drive();
		car.stop();
		
		fe2 = (FireEngine)car;
		fe2.water();
		
	}

}
