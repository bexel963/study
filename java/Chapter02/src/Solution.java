
// a ~ z : 97 ~ 122
// A ~ Z : 65 ~ 90
public class Solution {
	
	public static void main(String[] args) {
	
		String new_id = "=.=";
	
		solution(new_id);
	}
	
	public static String solution(String new_id) {
        String answer = "";
        final int MIN = 3;
        final int MAX = 15;
        char ch = ' ';
        
        
        // 1. new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ��
        for(int i=0 ; i<new_id.length() ; i++) {
        	ch = new_id.charAt(i);
        	if('A'<=ch && ch<='Z') {
        		new_id = new_id.replace(ch, (char)(ch + 32));
        	}
        }
        System.out.println("1 " + new_id);
        
        // 2. new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
        for(int i=0 ; i<new_id.length() ; i++) {
        	ch = new_id.charAt(i);
	    	if(!(('a'<=ch&&ch<='z') || ('0'<=ch&&ch<='9') || ch=='-' || ch=='_' || ch=='.')) {
	    		new_id = new_id.replace(ch, ' ');
	    	}
        }
        new_id = new_id.replaceAll(" ", "");
        System.out.println("2 " + new_id);
        
        // 3. new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
        if(new_id.length() != 0) {
        	char[] arr = new_id.toCharArray();
        	for(int i=0 ; i<arr.length ; i++) {
            	if((arr[i]=='.') && (i != (arr.length-1))) {
            		if(arr[i+1]=='.') {
            			arr[i] = ' ';
            		}
            	}
            }
            
            new_id = String.valueOf(arr);
            new_id = new_id.replaceAll(" ", "");
        }
        System.out.println("3 " + new_id);
        
        
        // 4. new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�
        char[] arr = new_id.toCharArray();
        if(arr.length!=0) {
        	 if(arr[0]=='.') {
             	arr[0] = ' ';
             }
             if(arr[arr.length-1]=='.') {
             	arr[arr.length-1] = ' ';
             }
             	
             new_id = String.valueOf(arr);
             new_id = new_id.replaceAll(" ", "");
        }
        System.out.println("4 " + new_id + ", " + new_id.length());
 
        // 5. new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
        if(new_id.length() == 0) {
        	new_id = new_id.concat("a");
        }
        System.out.println("5 " + new_id);
        
        // 6. ���̰� 16�� �̻��̸� 16���� ����� ���� �� ���ڸ��� ��ħǥ�� ��ħǥ ����
        if(new_id.length() >= 16) {
        	new_id = new_id.substring(0, 15);
	        arr = new_id.toCharArray();
	        if(arr.length!=0 && arr[arr.length-1]=='.') {
	        	arr[arr.length-1] = ' ';
	        	new_id = String.valueOf(arr);
	        	new_id = new_id.replaceAll(" ", "");
	        }
        }
        System.out.println("6 " + new_id);
        
        // 7. new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
        String s = "";
        while((new_id.length() >= 1) && (new_id.length() <= 2)) {
        	s = new_id.substring((new_id.length()-1), (new_id.length()));
        	new_id = new_id.concat(s);
        }
        System.out.println("7 " + new_id);
        
        answer = new_id;
        
        return answer;
    }
}
