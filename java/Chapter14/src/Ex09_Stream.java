import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/*
 	- 스트림
 		: 많은 수의 데이터를 다룰 때, 컬렉션이나 배열에 데이터를 담고 원하는 결과를 얻기 위해 for문과 Iterator를 이용한다.
 		  그러나 이러한 방식은 코드가 길고 알아보기 어렵고 재사용성이 떨어지고, 데이터 소스마다 다른 방식으로 다뤄야한다.
 		  Collection이나 Iterator와 같은 인터페이스를 이용해서 컬렉션을 다루는 방식을 표준화 하기는 했지만, 각 컬렉션 클래스에는 같은 기능의 메서드들이 중복해서 정의 되어있다.
 		  ex) Collections.sort(), Arrays.sort()
 		  이러한 문제점들을 해결하기 위해 만들어진 것이 '스트림(stream)'이다.
 		: 스트림은 데이터소스를 추상화하고, 데이터를 다루는데 자주 사용되는 메서드들을 정의해 놓았다.
 		  데이터 소스를 추상화하였다는 것은, 데이터 소스가 무엇이던 간에 같은 방식으로 다룰 수 있게 되었다는 것과 코드의 재사용성이 높아진다는 것을 의미한다.
 		  스트림을 이용하면 배열이나 컬렉션뿐만 아니라 파일에 저장된 데이터도 모두 같은 방식으로 다룰 수 있다.
*/
public class Ex09_Stream {

	public static void main(String[] args) {

		String[] 	 strArr = { "aaa", "ddd", "ccc" };
		List<String> strList = Arrays.asList(strArr);
		
		Stream<String> strStream1 = strList.stream();
		Stream<String> strStream2 = Arrays.stream(strArr);
		
		// * 스트림은 원본 데이터 소스를 읽기만할 뿐 변경하지 않는다. 
		// * 스트림은 작업을 내부 반복으로 처리한다. 내부 반복이라는 것은 반복문을 메서드의 내부에 숨길 수 있다는 것을 의미한다.
		//	 즉 forEach()는 메서드 안으로 for문을 넣은것이다. 수행할 작업은 매개변수로 받는다.
		// * 스트림이 제공하는 다양한 연산을 이용해서 복잡한 작업들을 간단히 처리할 수 있다. 마치 DB에 SELECT문으로 질의하는 것과 같은 느낌으로
		//	 스트림이 제공하는 연산은 중간 연산과 최종 연산으로 분류할 수 있는데, 중간 연산은 연산결과를 스트림으로 변환하기 대문에 중간 연산을 연속해서 연결할 수 있다.
		//	 반면에 최종 연산은 스트림의 요소를 소모하면서 연산을 수행하므로 단 한번만 연산이 가능하다.
		// * 스트림 연산에서 한 가지 중요한 점은 최종 연산이 수행되기 전까지는 중간 연산이 수행되지 않는다는 것이다. (지연된 연산)
		//	 중간 연산을 호출하는 것은 단지 어떤 작업이 수행되어야하는지를 지정해주는 것을 뿐이다. 최종 연산이 수행되어야 비로소 스트림의 요소들이 중간 연산을 거쳐 최종연산에서 소모된다.
		strStream1.sorted().forEach(System.out::print);
		strStream2.sorted().forEach((str) -> System.out.print("\n" + str + " "));
		
		// * 정렬된 결과를 컬렉션이나 배열에 담아서 반환할 수도 있다.
		// * 스트림은 Iterator처럼 일회용이다. Iterator로 컬렉션의 요소를 모두 읽고 나면 다시 사용할 수 없는 것처럼, 
		//   스트림도 한번 사용하면 닫혀서 다시 사용할 수 없다. 필요하다면 다시 생성해야한다.
		strStream2 = Arrays.stream(strArr);
		List<String> sortedList = strStream2.sorted().collect(Collectors.toList());
		
		
		
		
	}

}






