/*
 * < java.lang패키지 >
 * 
 * 1. Object클래스
 * 
 * 		- protected Object clone()
 * 		- public boolean equals(Object o)
 * 				- String클래스, Date, File, wrapper클래스의 equals메소드는 주소값이 아닌 내용을 비교하도록 오버라이딩 되어있음.
 * 		- public Class getClass()
 * 		- public int hashCode()
 * 				- equals를 오버라이딩 할때는 hashCode도 적절히 오버라이딩 해야한다.
 * 					ex)String클래스는 문자열의 내용이 같으면, 동일한 해시코드를 반환하도록 hashCode메소드가 오버라이딩 되어있다.
 * 		- public String toString()
 * 				- 인스턴스에 대한 정보를 문자열로 제공할 목적으로 정의한 것.
 * 				- 대부분의 경우 인스턴스 변수에 저장된 값들을 문자열로 표현한다는 뜻이다.
 * 				- String클래스, Date클래스의 경우 toString()메소드가 오버라이딩 되어있다.
 * 
 * 2. String클래스
 * 
 * 		- String 클래스는 앞에 final이 붙어 있으므로 다른 클래스의 조상이 될 수 없다.
 * 		- 한번 생성된 String인스턴스가 갖고 있는 문자열은 읽어 올 수만 있고, 변경할 수는 없다.
 * 		- 예를 들어 + 연산자를 이용해서 문자열을 결합하는 경우 인스턴스 내의 문자열이 바뀌는게 아니라 새로운 문자열이 담긴 String인스턴스가
 * 		  생성되는 것이다. (메모리 부담)
 * 		- StringBuffer인스턴스에 저장된 문자열은 변경이 가능하다.
 * 		- 문자열 리터럴은 클래스가 메모리에 로드될 때 자동적으로 미리 생성된다.
 * 
 * 		- String(String a)					- String 인스턴스 생성
 * 		- String(char[] value)				- String 인스턴스 생성
 * 		- String(StringBuffer buf)			- String 인스턴스 생성
 * 
 * 		- char charAt(int index)			- 지정된 위치에 있는 문자를 알려준다.						s.charAt(1);
 * 		- int compareTo(String str)			- 문자열을 사전순서로 비교한다. 같으면0, 작으면-1, 크면1 반환	s.compareTo("aaa");
 * 		- String concat(String str)			- 문자열을 뒤에 덧붙인다.								s.concat(" World");
 * 		- boolean contains(CharSequence s) 	- 지정된 문자열이 포함되었는지 검사한다.						s.contains("bc");
 * 		- boolean endWith(String suffix)	- 지정된 문자열로 끝나는지 검사한다.						s.endsWith("txt");
 * 		- boolean equals(Object obj)		- 문자열을 비교한다.									s.equals("hello);
 * 		- boolean equalsIgnoreCase(String str)
 * 		- int indexOf(int ch)				- 주어진 문자가 문자열에서 존재유무 확인 후 위치 알려준다.		s.indexOf('k');
 * 		- int indexOf(int ch, int pos)		- pos위치 부터 확인									s.indexOf('k', 2);
 * 		- int indexOf(String str)			- 주어진 문자열이 있는지 확인 후 위치 알려준다.				s.indexOf("ab");
 * 		- String intern()					- 문자열을 상수풀에 등록한다. 
 * 											  이미 상수풀에 같은 내용의 문자열이 있을 경우 주소값 반환
 * 		- int lastIndexOf(int ch)
 * 		- int lastIndexOf(String str)
 * 		- int length()
 * 		- String replace(char old, char nw)
 * 		- String replace(CharSequence old, CharSequence nw)
 * 		- String replaceAll(String regex, String replacement)
 * 		- String replaceFirst(String regex, String replacement)
 * 
 * 		- String[] split(String regex)		- 문자열을 지정한 분리자로 나누어 문자열 배열에 담아 반환한다.
 * 		- String[] split(String regex, int limit)	- 단, 문자열 전체를 지정된 수로 자른다.
 * 		- String join(String regex, String[] arr)	- 여러 문자열 사이에 구분자를 넣어서 결합한다.
 * 
 * 		- boolean startsWith(String prefix)	- 주어진 문자열로 시작하는지 검사
 * 		- String trim()						- 문자열의 왼쪽 끝과 오른쪽 끝에 있는 공백을 없앤 결과를 반환.

 * 		- String substring(int begin)		- 주어진 시작위치 부터 끝 위치 범위에 포함된 문자열을 얻는다.
 * 		- String substring(int begin, int end)
 * 		- String toLowerCase()				- String 인스턴스에 저장되어있는 모든 문자열을 소문자로 변환.
 * 		- String toUpperCase()
 * 		- String toString()
 * 		
 * 		- static String valueOf(boolean b)			- 기본형 -> 문자열
 * 		- static String valueOf(char c)		  		  참조변수의 경우, toString()을 호출한 결과를 반환.
 * 		- static String valueOf(int i)
 * 		- static String valueOf(long l)
 * 		- static String valueOf(float f)
 * 		- static String valueOf(double d)
 * 		- static String valeeOf(Object o)
 * 
 * 		- boolean 	Boolean.parseBoolean(String s)	- 문자열 -> 기본형
 * 		- byte 		Byte.parseByte(String s)
 * 		- short 	Short.parseShort(String s)
 * 		- int 		Integer.parseInt(String s)
 * 		- long 		Long.parseLong(String s)
 * 		- float 	Float.parseFloat(String s)
 * 		- double 	Double.parseDoubel(String s)
 * 
 * 		- String Join(String regex, String[] arr)	- String.join("-", arr);
 * 		- String format()					- String str = String.format("%d 더하기 %d는 %d입니다.", 3, 5, 3+5);
 * 
 * 3. StringBuffer클래스와 StringBuilder클래스
 * 
 * 		- String클래스는 인스턴스를 생성할 때 지정된 문자열을 변경할 수 없지만 StringBuffer클래스는 변경이 가능하다.
 * 		- 내부적으로 문자열 편집을 위헌 버퍼를 가지고 있으며, StringBuffer인스턴스를 생성할 때 그 크기를 지정할 수 있다.
 * 		- equals메서드를 오버라이딩 하지 않음. toString은 오버라이딩 함.
 * 		- 문자열 비교하려 할땐 toString으로 String인스턴스를 얻은 후 equals메소드를 사용한다.
 * 
 * 		- StringBuffer()				- 16문자를 담을 수 있는 버퍼를 가진 StringBuffer인스턴스를 생성.
 * 		- StringBuffer(int length)
 * 		- StringBuffer(String str)
 * 
 * 		- StringBuffer append(boolean b)	- 매개변수로 입력된 값을 문자열로 변환하여 StringBuffer인스턴스가 저장하고 있는
 * 		- StringBuffer append(char c)		  문자열의 뒤에 덧붙인다.
 * 		- StringBuffer append(char[] arr)
 * 		- StringBuffer append(double d)
 * 		- StringBuffer append(float f)
 * 		- StringBuffer append(int i)
 * 		- StringBuffer append(long l)
 * 		- StringBuffer append(Object o)
 * 		- StringBuffer append(String s)
 * 
 * 		- int capacity()					- StringBuffer인스턴스의 버퍼크기를 알려준다. 
 * 		- int length()						- 버퍼에 담긴 문자열의 길이를 알려준다.
 * 		- char charAt(int index)
 * 		- StringBuffer delete(int start, int end)
 * 		- StringBuffer deleteCharAt(int index)
 * 
 * 		- StringBuffer insert(int pos, boolean b)	- 두 번째 매개변수로 받은 값을 문자열로 변환하여 지정된 위치에 추가한다.
 * 		- StringBuffer insert(int pos, char c)
 * 		- StringBuffer append(int pos, char[] arr)
 * 		- StringBuffer append(int pos, double d)
 * 		- StringBuffer append(int pos, float f)
 * 		- StringBuffer append(int pos, int i)
 * 		- StringBuffer append(int pos, long l)
 * 		- StringBuffer append(int pos, Object o)
 * 		- StringBuffer append(int pos, String s)
 * 
 * 		- StringBuffer replace(int start, int end, String str)
 * 		- StringBuffer reverse()
 * 		- void setChartAt(int index, char ch)
 * 		- void setLength(int newLength)
 * 
 * 		- String toString()
 * 		- String subString(int start)
 * 		- String subString(int start, int end)
 * 
 * 		- StringBuilder클래스는 StringBuffer에서 쓰레드의 동기화만 뺀 클래스이다.
 * 
 * 4. Math 클래스
 * 
 * 		- 생성자는 private
 * 		- 클래스 내에 인스턴스 변수가 하나도 없고, 메서드들은 모두 static이고, 상수 2개만 정의해 놓았다.
 * 		- public static final double E = 2.7182818284590452354;
 * 		- public static final double PI = 3.14159265358979323846;
 * 
 * 		- static double abs(double a)	-	주어진 값의 절대값을 반환
 * 		- static float abs(float f)
 * 		- static int abs(int f)
 * 		- static long abs(long f)
 * 
 * 		- static double ceil(double a)
 * 		- static double floor(double a)
 * 		- static long round(double a)
 * 		- static long round(float a)
 * 		- static double rint(double a)
 * 		- static double random()
 * 
 * 		- static double max(double a, double b)
 * 		- static float max(float a, float b)
 * 		- static int max(int a, int b)
 * 		- static long max(long a, long b)
 * 
 * 		- static double min(double a, double b)
 * 		- static float min(float a, float b)
 * 		- static int min(int a, int b)
 * 		- static long min(long a, long b)
 * 
 * 5. wrapper 클래스
 * 
 * 		- 기본형 값을 객체로 다룰 수 있게 하는 클래스
 * 		- 객체지향 개념에서는 모든 것을 객체로 다루어야 한다.
 * 		- 자바에서는 8개의 기본형을 객체로 다루지 않는다 (성능 고려)
 * 		- 때로는 기본형 변수도 어쩔 수 없이 객체로 다뤄야 하는 경우가 있다.
 * 			ex) 매개변수로 객체를 요구할 때, 기본형 값이 아닌 객체로 저장해야할 때, 객체간의 비교가 필요할 때 등등
 * 		- equals()와 toString()이 오버라이딩 되어있다.
 * 		- 비교 연산자를 사용할 수 없고 대신 compareTo()를 제공한다.
 * 
 * 		- Boolean b = new Boolean(true);
 * 		- Boolean b2 = new Boolean("true");
 * 		- Character c = new Character('a');
 * 		- Byte b = new Byte(10);
 * 		- Byte b2 = new Byte("10");
 * 		- Short s = new Short(10);
 * 		- Short s2 = new Short("10");
 * 		- Integer i = new Integer(10);
 * 		- Integer i2 = new Integer("10");
 * 		- Long l = new Long(10);
 * 		- Long l2 = new Long("10");
 * 		- Float f = new Float(1.0);
 * 		- Float f2 = new Float(1.0f);
 * 		- Float f3 = new Float("1.0f");
 * 		- Double d = new Double(1.0);
 * 		- Double d2 = new Double("1.0");
 * 
 * */
 
/*
 * < java.util 패키지 >
 * 
 * 1. StringJoiner클래스	-	문자열 결합
 * 
 * */
