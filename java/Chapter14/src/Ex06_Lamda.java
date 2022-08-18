import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.IntConsumer;
import java.util.function.IntPredicate;
import java.util.function.IntSupplier;
import java.util.function.IntUnaryOperator;
import java.util.function.Predicate;
import java.util.function.Supplier;

/*
 	- 기본형을 사용하는 함수형 인터페이스
 		: 기본형 타입의 값을 처리할 때도 래퍼 클래스를 사용하면 비효율적이다.
 	
 			public interface DoubleToIntFunction {
 				int applyAsInt(double d);
 			}
 			public interface ToIntFunction<T> {
 				int applyAsInt(T value);
 			}
 			public interface intFunction<R> {
 				R apply(T t, U u);
 			}
 			public interface ObjIntConsumer<T> {
 				void accept(T t, U u);
 			}
*/
public class Ex06_Lamda {

	public static void main(String[] args) {

		IntSupplier s = () -> (int)(Math.random()*100)+1;
		IntConsumer  c = i -> System.out.print(i + ", ");
		IntPredicate p = i -> i%2==0;
		IntUnaryOperator op = i -> i/10*10;
		
		int[] arr = new int[10];
		makeRandomList(s, arr);
		System.out.println(Arrays.toString(arr));
		printEvenNum(p, c, arr);
		int[] newArr = doSomething(op, arr);
		System.out.println(Arrays.toString(newArr));
	}
	
	static void makeRandomList(IntSupplier s, int[] arr) {
		for(int i=0 ; i<10 ; i++) {
			arr[i] = s.getAsInt();
		}
	}
	static int[] doSomething(IntUnaryOperator op, int[] arr){
		int[] newArr = new int[arr.length];
		
		for(int i=0 ; i<newArr.length ; i++) {
			newArr[i] = op.applyAsInt(arr[i]);
		}
		return newArr;
	}
	static <T> void printEvenNum(IntPredicate p, IntConsumer c, int[] arr) {
		System.out.print("[");
		for(int i : arr) {
			if(p.test(i)) {
				c.accept(i);
			}
		}
		System.out.print("]");
		System.out.println();
	}

}
