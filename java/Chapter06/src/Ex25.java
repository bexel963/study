class Car2 {
	String color;
	String gearType;
	int door;
	
	Car2() {
		this("White", "auto", 4);
	}
	
	Car2(String color) {
		this(color, "auto", 4);
	}
	
	Car2(String c, String g, int d) {
		this.color = c;
		this.gearType = g;
		this.door = d;
	}
}
public class Ex25 {

	public static void main(String[] args) {
		
		Car2 c1 = new Car2();
		
		Car2 c2 = new Car2("white", "auto", 4);
		
		System.out.println("c1ÀÇ color = " + c1.color + "gearType = " + c1.gearType + "door = " + c1.door);
		System.out.println("c2ÀÇ color = " + c2.color + "gearType = " + c2.gearType + "door = " + c2.door);
	}

}
