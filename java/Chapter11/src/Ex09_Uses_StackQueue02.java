import java.util.Stack;

// ��ȣ �� ����ϱ� - �Է°� : ((2+3)*1)+3
public class Ex09_Uses_StackQueue02 {

	public static void main(String[] args) {

		String input = "(2+3)*1)+3";

		if(check(input)) {
			System.out.println("��ȣ ¦ ����");
		}else {
			System.out.println("��ȣ ¦ �� ����");
		}
		
			
	}
	public static Boolean check(String input) {
		
		Stack s = new Stack();
		
		for(int i=0 ; i<input.length() ; i++) {
			if(input.charAt(i)=='(') {
				s.push('(');
			}else if(input.charAt(i)==')') {
				try {
					Object o = s.pop();					
				}catch(Exception e) {
					return false;
				}
			}
		}
		if(!s.empty()) {
			return false;		
		}
		return true;
	}

}
