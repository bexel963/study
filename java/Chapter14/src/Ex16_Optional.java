/*
 	: Optional<T>�� ���׸� Ŭ������ TŸ���� ��ü�� ���δ� ���� Ŭ�����̴�. �׷��� OptionalŸ���� ��ü���� ��� Ÿ���� ���������� ���� �� �ִ�.
	 		public final class Optional<T> {
	 			private final T value;
	 			.....
	 		}
 	  ���� ������ ����� �׳� ��ȯ�ϴ°� �ƴ϶� Optional��ü�� ��Ƽ� ��ȯ�ϴ� ���̴�.
 	  ��ó�� ��ü�� ��Ƽ� ��ȯ�� �ϸ�, ��ȯ���� ����� null���� �Ź� if������ üũ�ϴ� ��� Optional�� ���ǵ� �޼��带 ���ؼ� ������ ó���� �� �ִ�.
 	  
 	  Optional��ü �����ϱ�
 	  	- of()		   : �Ű������� ���� null�̸� NullPointerException�߻�.
 	  	- ofNullable() : ���������� ���� null�� ���ɼ��� ������ �̰� ����Ѵ�.
 	  
 	  Optional<T>Ÿ���� ���������� �⺻������ �ʱ�ȭ
 	  	- empty()
 	  
 	  Optional��ü�� �� ��������
 	  	- get()				: ���� null�� ���� NoSuchElementException �߻�
 	  	- orElse()			: ���� �߻� ����ؼ� �̰� ���.
 	  	- orElseGet()		: null�� ��ü�� ���� ��ȯ�ϴ� ���ٽ��� ������ �� ����.
 	  	- orElseThrow()		: null�� �� ������ ���ܸ� �߻���ų �� ����
 	  
 	  �⺻���� �������ϴ� Optional
 	  	- OptionalInt			: int getAsInt()
 	  	- OptionalLong			: long getAsLong()
 	  	- OptionalDouble		: double getAsDouble()
 	

*/

import java.util.Optional;

public class Ex16_Optional {

	public static void main(String[] args) {

//		int[] arr = null;
		int[] arr = new int[0];			// �̷������� �ʱ�ȭ �Ͽ� NullPointerException�� �ִ��� ������.
		System.out.println("arr.length = " + arr.length);
		
		System.out.println("=================================");
		
//		Optional<String> opt = null;	// OK. ������ �ٶ������� ����.
		Optional<String> opt = Optional.empty();
		System.out.println("opt = " + opt);
		
		System.out.println("=================================");
		
//		System.out.println("opt = " + opt.get());	// �� ���ڿ����� get()�ϸ� NoSuchElementException �߻�
		String str = "";
		try {
			str = opt.get();
		} catch(Exception e) {
			str = "";	// �׷��� �䷱������ ���ܰ� �߻��ϸ� �ʱ�ȭ �ϴ� �ڵ带 �ۻ��ؾ���.
		}
		System.out.println("str = " + str);
		
		// �� �ڵ�� orElse() �޼��� �ϳ��� ��ü�� �� �ִ�.
		String str2 = opt.orElse("");	// Optional�� ����� ���� null�̸� ""��ȯ. �ƴϸ� ��ü�� ����ִ� �� ��ȯ.
		System.out.println("str2 = " + str2);
		
		System.out.println("=================================");
		
		Optional<String> opt2 = Optional.of("abc");
		String str3 = opt2.orElse("EMPTY");				// Optional�� ����� ���� null�̸� EMPTY ��ȯ. �ƴϸ� ��ü�� ����ִ� �� ��ȯ.
		System.out.println("str3 = " + str3);
		
		System.out.println("=================================");
		
		String str4 = opt2.orElseGet(() -> "EMPTY");	// orElse()���� ���ٽ� �޴� ��� �߰�
		str4 = opt2.orElseGet(() -> new String());		// �̷� �����ε� ���.
		str4 = opt2.orElseGet(String::new);				// �̷� �����ε� ���
		System.out.println("str3 = " + str3);
		
	}

}
