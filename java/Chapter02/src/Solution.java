
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
        
        
        // 1. new_id의 모든 대문자를 대응되는 소문자로 치환함
        for(int i=0 ; i<new_id.length() ; i++) {
        	ch = new_id.charAt(i);
        	if('A'<=ch && ch<='Z') {
        		new_id = new_id.replace(ch, (char)(ch + 32));
        	}
        }
        System.out.println("1 " + new_id);
        
        // 2. new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
        for(int i=0 ; i<new_id.length() ; i++) {
        	ch = new_id.charAt(i);
	    	if(!(('a'<=ch&&ch<='z') || ('0'<=ch&&ch<='9') || ch=='-' || ch=='_' || ch=='.')) {
	    		new_id = new_id.replace(ch, ' ');
	    	}
        }
        new_id = new_id.replaceAll(" ", "");
        System.out.println("2 " + new_id);
        
        // 3. new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
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
        
        
        // 4. new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다
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
 
        // 5. new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
        if(new_id.length() == 0) {
        	new_id = new_id.concat("a");
        }
        System.out.println("5 " + new_id);
        
        // 6. 길이가 16자 이상이면 16부터 지우고 제거 후 끝자리가 마침표면 마침표 제거
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
        
        // 7. new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
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
