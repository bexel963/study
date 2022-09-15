/*
	  - �迭�� ��ü�̱� ������ ObjectŬ������ ��ӹ�����, ���ÿ� Cloneable �������̽��� Serializable�������̽��� ���� �Ǿ��ִ�.
	  	�׷��� ObjectŬ������ ������� ��� ��� �޴´�.
	  	ObjectŬ�������� protected�� ���ǵǾ��ִ� clone()�� �迭������ public���� �������̵� �Ͽ��� ������ ����ó�� ���� ȣ���� �����ϴ�.
	  	�׸��� ������ ���� Ÿ���� ��ȯ�ϹǷ� (���� ��ȯŸ��) ����ȯ�� �ʿ����.
	  
	  	*���� ��ȯŸ�� - �������̵��� �� ���� �޼����� ��ȯ Ÿ���� �ڼ� Ŭ������ Ÿ������ ������ ����ϴ� ��.	
*/

import java.util.ArrayList;
import java.util.Arrays;

public class Ex08_arrCopy {

	public static void main(String[] args) {

		int[] arr = {1,2,3,4,5};
		int[] arrClone = arr.clone();			// �迭���� ���1
		arrClone[0] = 6;
		
		System.out.println(Arrays.toString(arr));
		System.out.println(Arrays.toString(arrClone));
		
		System.out.println();
		
		int[] arr2Clone = new int[arr.length];
		System.arraycopy(arr, 0, arr2Clone, 0, arr.length);	// �迭���� ���2
		
		System.out.println(Arrays.toString(arr));
		System.out.println(Arrays.toString(arr2Clone));
		
		ArrayList list = new ArrayList();
		ArrayList list2 = (ArrayList)list.clone();	// ArrayList�� �迭ó�� ���� ��ȯŸ���� �ƴ϶� ����ȯ ������Ѵ�.
	}

}


