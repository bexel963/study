/*
	  - 배열도 객체이기 때문에 Object클래스를 상속받으며, 동시에 Cloneable 인터페이스와 Serializable인터페이스가 구현 되어있다.
	  	그래서 Object클래스의 멤버들을 모두 상속 받는다.
	  	Object클래스에는 protected로 정의되어있는 clone()을 배열에서는 public으로 오버라이딩 하였기 때문에 예제처럼 직접 호출이 가능하다.
	  	그리고 원본과 같은 타입을 반환하므로 (공변 반환타입) 형변환이 필요없다.
	  
	  	*공변 반환타입 - 오버라이딩할 때 조상 메서드의 반환 타입을 자손 클래스의 타입으로 변경을 허용하는 것.	
*/

import java.util.ArrayList;
import java.util.Arrays;

public class Ex08_arrCopy {

	public static void main(String[] args) {

		int[] arr = {1,2,3,4,5};
		int[] arrClone = arr.clone();			// 배열복사 방법1
		arrClone[0] = 6;
		
		System.out.println(Arrays.toString(arr));
		System.out.println(Arrays.toString(arrClone));
		
		System.out.println();
		
		int[] arr2Clone = new int[arr.length];
		System.arraycopy(arr, 0, arr2Clone, 0, arr.length);	// 배열복사 방법2
		
		System.out.println(Arrays.toString(arr));
		System.out.println(Arrays.toString(arr2Clone));
		
		ArrayList list = new ArrayList();
		ArrayList list2 = (ArrayList)list.clone();	// ArrayList는 배열처럼 공변 반환타입이 아니라서 형변환 해줘야한다.
	}

}


