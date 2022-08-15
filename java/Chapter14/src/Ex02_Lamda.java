
/*
 	- 람다식의 타입과 형변환
	    interface MyFunction {
	 		void method();
	 	}
	  	MyFunction f = (MyFunction)( () -> { } );
	  	Object ojb = (Object)( () -> { } );
	  	- 람다식은 MyFunction인터페이스를 직접 구현하지 않았지만, 이 인터페이스를 구현한 클래스의 객체와 완전히 동일하기 때문에 위와 같은 형변환을 허용한다.
	  	  그리고 이 형변환은 생략이 가능하다.
	  	- 람다식은 이름이 없을 뿐 객체인데도 Object타입으로는 형변환 할 수 없다.
	  	  람다식은 오직 함수형 인터페이스로만 형변환이 가능하다. 굳이 Object타입으로 형변환 하려면, 먼저 함수형 인터페이스로 형변환 해줘야한다.
	  	  	- Object obj = (Object)(MyFunction)( () -> { } );
	  	  	- String str = ((Object)(MyFunction)( () -> { } )).toString();	// Object클래스의 toString()을 사용하기위해 Object 타입으로 형변환.
 */
@FunctionalInterface
interface MyFunction2 {
	void myMethod();
}

public class Ex02_Lamda {

	public static void main(String[] args) {

		MyFunction2 f = () -> System.out.println("Hello World!!");
		Object obj = (MyFunction)(() -> System.out.println("Hello World!!"));
		String str = ((Object)(MyFunction)(() -> System.out.println("Hello World!!"))).toString();
		
		System.out.println(f);
		System.out.println(obj);
		System.out.println(str);
		
//		System.out.println(() -> System.out.println("Hello World!!"));	// 에러 - 람다식은 Object타입으로 형변환 안됨.
		System.out.println((MyFunction2)(() -> System.out.println("Hello World!!")));
//		System.out.println(((MyFunction2)(() -> System.out.println("Hello World!!"))).toString());	// 에러
		System.out.println(((Object)(MyFunction2)(() -> System.out.println("Hello World!!"))).toString());
		
		// 일반적인 익명 객체라면, 객체의 타입이 '외부클래스의이름$번호' 와 같은 형식으로 타입이 결정되었을 텐데,
		// 람다식의 타입은 '외부클래스이름$$Lambda$번호' 와 같은 형식으로 되어있다.
	}

}
