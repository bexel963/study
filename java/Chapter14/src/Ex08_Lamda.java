import java.util.Arrays;
import java.util.function.Function;
import java.util.function.Supplier;
/*
 	- �޼��� ����
 		: ���ٽ��� �ϳ��� �޼��常 ȣ���ϴ� ��쿡�� '�޼��� ����'��� ������� ���ٽ��� ������ �� �� �ִ�.
 		
 		Function<String, Integer> f = (String s) -> Integer.parseInt(s);
 		Function<String, Integer> f = Integer::parseInt;
 		: �� �� �ڵ�� ����. �����Ϸ��� ������ �κ��� �캯�� parseInt�޼����� ����ηκ���, �Ǵ� �º��� Function�������̽��� ������
 		  ���׸� Ÿ�����κ��� ���� �˾Ƴ� �� �ִ�.
 	- �������� �޼��� ����
*/
class MyClass {
	
	private int lv;
	
	MyClass() {
		
	}
	MyClass(int lv){
		this.lv = lv;
	}
	public int getLv() {
		return lv;
	}
}
public class Ex08_Lamda {

	public static void main(String[] args) {
		
//		Supplier<MyClass> s = () -> new MyClass();
		Supplier<MyClass> s = MyClass::new;		// �� �ڵ�� ����.
		
		MyClass mc = s.get();
		System.out.println(mc);
		System.out.println(s.get());
		
		System.out.println("===================================");
		
//		Function<Integer, MyClass> f = (i) -> new MyClass(i);
		Function<Integer, MyClass> f = MyClass::new;	// �� �ڵ�� ����.
		
		MyClass mc2 = f.apply(100);
		System.out.println(mc2);
		System.out.println(mc2.getLv());
		System.out.println(f.apply(200).getLv());
		
		System.out.println("===================================");
		
//		Function<Integer, int[]> arrF = (i) -> new int[i];
		Function<Integer, int[]> arrF = int[]::new;		// �� �ڵ�� ����
		
		int[] arr = arrF.apply(10);
		Arrays.setAll(arr, (i)->(int)(Math.random()*10)+1);
		System.out.println(Arrays.toString(arr));
	}

}









