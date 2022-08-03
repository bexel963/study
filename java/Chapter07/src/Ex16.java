
public class Ex16 {

	public static void main(String[] args) {

		Car car = new Car();
		Car car2 = null;
		FireEngine fe = null;
		
		car.drive();
		fe = (FireEngine)car;	// 실행에러
		fe.drive();
		car2 = fe;
		car2.drive();
	}

}
