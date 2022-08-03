
public class Ex12 {

	public static void main(String[] args) {

		String s1 = "AAA";
		String s2 = "AAA";
		String s3 = "AAA";
		String s4 = "BBB";
	}

}

/*
 * String리터럴들은 컴파일 시에 클래스 파일에 저장된다.
 * "AAA" 를 담고있는 String인스턴스가 하나 생성된 후, 참조변수 s1,s2,s3은 모두 이 String인스턴스를 참조하게 된다.
 * 클래스 파일에는 소스파일에 포함된 모든 리터럴의 목록이 있다. 해당 클래스 파일이 클래스로더에 의해 메모리에 올라갈 때,
 * 이 리터럴의 목록에 있는 리터럴들이 JVM내에 있는 상수 저장소에 저장된다.
 * 이 때, "AAA"와 같은 문자열 리터럴이 자동적으로 생성되어 저장되는 것이다.
 * */
 