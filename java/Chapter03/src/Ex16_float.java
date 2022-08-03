// 소수점 자르기

public class Ex16_float {

	public static void main(String[] args) {

		float pi = 3.141592f;
		float shortPi = (int)(pi * 1000) / 1000f;
		System.out.println(shortPi);
	}

}
