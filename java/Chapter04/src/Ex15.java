
public class Ex15 {

	public static void main(String[] args) {

		System.out.println("i \t 2*i \t 2*i-1 \t i*i \t 11-i \t i%3 \t i/3");
		System.out.println("-----------------------------------------------------");
		
		// 나머지 연산자 활용 - 나누는 수보다 작은값 나옴
		for(int i=1 ; i<=10 ; i++)
			System.out.printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t\n", i, 2*i, 2*i-1, i*i, 11-i, i%3, i/3);
	}

}
