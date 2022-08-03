class Car3 {
	String color;
	String gearType;
	int door;
	
	Car3() {
		this("White", "auto", 4);
	}
	
	Car3(String c, String g, int d) {
		this.color = c;
		this.gearType = g;
		this.door = d;
	}
	
	Car3(Car3 c) {
		this.color = c.color;
		this.gearType = c.gearType;
		this.door = c.door;
	}
}
public class Ex26 {

	public static void main(String[] args) {
		
		Car3 c1 = new Car3();
		Car3 c2 = new Car3(c1);
		
		System.out.println("c1의 color = " + c1.color + "gearType = " + c1.gearType + "door = " + c1.door);
		System.out.println("c2의 color = " + c2.color + "gearType = " + c2.gearType + "door = " + c2.door);
		System.out.println();
		
		c1.door = 100;
		
		System.out.println("c1의 color = " + c1.color + "gearType = " + c1.gearType + "door = " + c1.door);
		System.out.println("c2의 color = " + c2.color + "gearType = " + c2.gearType + "door = " + c2.door);
	}

}
