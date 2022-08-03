// 컴파일러가 예외처리를 확인하지 않는 RuntimeException클래스들은 'uncheked예외' 라고 부른다.

public class Ex11_uncheked {

	public static void main(String[] args) {

		throw new RuntimeException();
	}

}
