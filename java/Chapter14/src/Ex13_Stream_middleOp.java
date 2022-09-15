import java.io.File;
import java.util.stream.Stream;

// - ��Ʈ���� �߰�����3 (��ȯ, ��ȸ)

/*
	: ��Ʈ���� ��ҿ� ����� �� �߿��� ���ϴ� �ʵ常 �̾Ƴ��ų� Ư�� ���·� ��ȯ�ؾ� �� ��.
	
 	- Stream<R> map(Function<? super T, ? extends R> mapper)
	
 	- peek()�� ����� ���� ���̿� �ùٸ��� ó���Ǿ����� Ȯ�� �ϰ����� �� ����Ѵ�.
 	  forEach()�� �޸� ��Ʈ���� ��Ҹ� �Ҹ����� �����Ƿ� ���� ���̿� ���� �� ���� �־ �ȴ�.
 	  filter()�� map()�� ����� Ȯ���� �� �����ϰ� ���� �� �ִ�.
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
		
		fileStream.map(File::getName).filter(s->s.indexOf('.')!=-1)	// Ȯ���� ���°� ����
				.peek(s->System.out.println("filename = " + s))
				.map(s->s.substring(s.indexOf('.')+1))				// Ȯ���ڸ� ����
				.peek(s->System.out.println("extension = " + s))
				.map(String::toUpperCase)					
				.distinct()
				.forEach(System.out::println);
		System.out.println();
		
	}

}
