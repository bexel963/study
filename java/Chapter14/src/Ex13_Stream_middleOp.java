import java.io.File;
import java.util.stream.Stream;

// - 스트림의 중간연산3 (변환, 조회)

/*
	: 스트림의 요소에 저장된 값 중에서 원하는 필드만 뽑아내거나 특정 형태로 변환해야 할 때.
	
 	- Stream<R> map(Function<? super T, ? extends R> mapper)
	
 	- peek()는 연산과 연산 사이에 올바르게 처리되었는지 확인 하고자할 때 사용한다.
 	  forEach()와 달리 스트림의 요소를 소모하지 않으므로 연산 사이에 여러 번 끼워 넣어도 된다.
 	  filter()나 map()의 결과를 확인할 때 유용하게 사용될 수 있다.
*/
public class Ex13_Stream_middleOp {

	public static void main(String[] args) {

		File[] fileArr = { new File("Ex1.java"), new File("Ex1.bak"), new File("Ex2.java"),
						   new File("Ex1"), new File("Ex1.txt")
		};
		
		Stream<File> fileStream = Stream.of(fileArr);
		Stream<String> fileNameStream = fileStream.map(File::getName);
		fileNameStream.forEach(System.out::println);
		System.out.println();
		fileStream = Stream.of(fileArr);
		
		fileStream.map(File::getName).filter(s->s.indexOf('.')!=-1)	// 확장자 없는거 제외
				.peek(s->System.out.println("filename = " + s))
				.map(s->s.substring(s.indexOf('.')+1))				// 확장자만 추출
				.peek(s->System.out.println("extension = " + s))
				.map(String::toUpperCase)					
				.distinct()
				.forEach(System.out::println);
		System.out.println();
		
	}

}
