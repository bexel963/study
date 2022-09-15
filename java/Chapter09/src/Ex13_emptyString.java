/*
 	- 빈 문자열
 	: String s = ""; 과 같은 문장이 있을 때, 참조변수 s가 참조하고 있는 String인스턴스는 내부에 new char[0]과 같이 길이가 0인 char형 배열을 저장하고 있는 것 이다.
 	: 그러나 char c = ''; 과 같은 표현이 가능한 것은 아니고, char형 변수에는 반드시 하나의 문자를 지정해야 한다. -> char c = ' ';
*/
public class Ex13_emptyString {

	public static void main(String[] args) {

		char[] cArr = new char[0];
		String s = new String(cArr);
		
		System.out.println("cArr.length = " + cArr.length);
		System.out.println("@@@" + s + "@@@");
	}

}
