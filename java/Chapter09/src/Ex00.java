/*
 * < java.lang��Ű�� >
 * 
 * 1. ObjectŬ����
 * 
 * 		- protected Object clone()
 * 		- public boolean equals(Object o)
 * 				- StringŬ����, Date, File, wrapperŬ������ equals�޼ҵ�� �ּҰ��� �ƴ� ������ ���ϵ��� �������̵� �Ǿ�����.
 * 		- public Class getClass()
 * 		- public int hashCode()
 * 				- equals�� �������̵� �Ҷ��� hashCode�� ������ �������̵� �ؾ��Ѵ�.
 * 					ex)StringŬ������ ���ڿ��� ������ ������, ������ �ؽ��ڵ带 ��ȯ�ϵ��� hashCode�޼ҵ尡 �������̵� �Ǿ��ִ�.
 * 		- public String toString()
 * 				- �ν��Ͻ��� ���� ������ ���ڿ��� ������ �������� ������ ��.
 * 				- ��κ��� ��� �ν��Ͻ� ������ ����� ������ ���ڿ��� ǥ���Ѵٴ� ���̴�.
 * 				- StringŬ����, DateŬ������ ��� toString()�޼ҵ尡 �������̵� �Ǿ��ִ�.
 * 
 * 2. StringŬ����
 * 
 * 		- String Ŭ������ �տ� final�� �پ� �����Ƿ� �ٸ� Ŭ������ ������ �� �� ����.
 * 		- �ѹ� ������ String�ν��Ͻ��� ���� �ִ� ���ڿ��� �о� �� ���� �ְ�, ������ ���� ����.
 * 		- ���� ��� + �����ڸ� �̿��ؼ� ���ڿ��� �����ϴ� ��� �ν��Ͻ� ���� ���ڿ��� �ٲ�°� �ƴ϶� ���ο� ���ڿ��� ��� String�ν��Ͻ���
 * 		  �����Ǵ� ���̴�. (�޸� �δ�)
 * 		- StringBuffer�ν��Ͻ��� ����� ���ڿ��� ������ �����ϴ�.
 * 		- ���ڿ� ���ͷ��� Ŭ������ �޸𸮿� �ε�� �� �ڵ������� �̸� �����ȴ�.
 * 
 * 		- String(String a)					- String �ν��Ͻ� ����
 * 		- String(char[] value)				- String �ν��Ͻ� ����
 * 		- String(StringBuffer buf)			- String �ν��Ͻ� ����
 * 
 * 		- char charAt(int index)			- ������ ��ġ�� �ִ� ���ڸ� �˷��ش�.						s.charAt(1);
 * 		- int compareTo(String str)			- ���ڿ��� ���������� ���Ѵ�. ������0, ������-1, ũ��1 ��ȯ	s.compareTo("aaa");
 * 		- String concat(String str)			- ���ڿ��� �ڿ� �����δ�.								s.concat(" World");
 * 		- boolean contains(CharSequence s) 	- ������ ���ڿ��� ���ԵǾ����� �˻��Ѵ�.						s.contains("bc");
 * 		- boolean endWith(String suffix)	- ������ ���ڿ��� �������� �˻��Ѵ�.						s.endsWith("txt");
 * 		- boolean equals(Object obj)		- ���ڿ��� ���Ѵ�.									s.equals("hello);
 * 		- boolean equalsIgnoreCase(String str)
 * 		- int indexOf(int ch)				- �־��� ���ڰ� ���ڿ����� �������� Ȯ�� �� ��ġ �˷��ش�.		s.indexOf('k');
 * 		- int indexOf(int ch, int pos)		- pos��ġ ���� Ȯ��									s.indexOf('k', 2);
 * 		- int indexOf(String str)			- �־��� ���ڿ��� �ִ��� Ȯ�� �� ��ġ �˷��ش�.				s.indexOf("ab");
 * 		- String intern()					- ���ڿ��� ���Ǯ�� ����Ѵ�. 
 * 											  �̹� ���Ǯ�� ���� ������ ���ڿ��� ���� ��� �ּҰ� ��ȯ
 * 		- int lastIndexOf(int ch)
 * 		- int lastIndexOf(String str)
 * 		- int length()
 * 		- String replace(char old, char nw)
 * 		- String replace(CharSequence old, CharSequence nw)
 * 		- String replaceAll(String regex, String replacement)
 * 		- String replaceFirst(String regex, String replacement)
 * 
 * 		- String[] split(String regex)		- ���ڿ��� ������ �и��ڷ� ������ ���ڿ� �迭�� ��� ��ȯ�Ѵ�.
 * 		- String[] split(String regex, int limit)	- ��, ���ڿ� ��ü�� ������ ���� �ڸ���.
 * 		- String join(String regex, String[] arr)	- ���� ���ڿ� ���̿� �����ڸ� �־ �����Ѵ�.
 * 
 * 		- boolean startsWith(String prefix)	- �־��� ���ڿ��� �����ϴ��� �˻�
 * 		- String trim()						- ���ڿ��� ���� ���� ������ ���� �ִ� ������ ���� ����� ��ȯ.

 * 		- String substring(int begin)		- �־��� ������ġ ���� �� ��ġ ������ ���Ե� ���ڿ��� ��´�.
 * 		- String substring(int begin, int end)
 * 		- String toLowerCase()				- String �ν��Ͻ��� ����Ǿ��ִ� ��� ���ڿ��� �ҹ��ڷ� ��ȯ.
 * 		- String toUpperCase()
 * 		- String toString()
 * 		
 * 		- static String valueOf(boolean b)			- �⺻�� -> ���ڿ�
 * 		- static String valueOf(char c)		  		  ���������� ���, toString()�� ȣ���� ����� ��ȯ.
 * 		- static String valueOf(int i)
 * 		- static String valueOf(long l)
 * 		- static String valueOf(float f)
 * 		- static String valueOf(double d)
 * 		- static String valeeOf(Object o)
 * 
 * 		- boolean 	Boolean.parseBoolean(String s)	- ���ڿ� -> �⺻��
 * 		- byte 		Byte.parseByte(String s)
 * 		- short 	Short.parseShort(String s)
 * 		- int 		Integer.parseInt(String s)
 * 		- long 		Long.parseLong(String s)
 * 		- float 	Float.parseFloat(String s)
 * 		- double 	Double.parseDoubel(String s)
 * 
 * 		- String Join(String regex, String[] arr)	- String.join("-", arr);
 * 		- String format()					- String str = String.format("%d ���ϱ� %d�� %d�Դϴ�.", 3, 5, 3+5);
 * 
 * 3. StringBufferŬ������ StringBuilderŬ����
 * 
 * 		- StringŬ������ �ν��Ͻ��� ������ �� ������ ���ڿ��� ������ �� ������ StringBufferŬ������ ������ �����ϴ�.
 * 		- ���������� ���ڿ� ������ ���� ���۸� ������ ������, StringBuffer�ν��Ͻ��� ������ �� �� ũ�⸦ ������ �� �ִ�.
 * 		- equals�޼��带 �������̵� ���� ����. toString�� �������̵� ��.
 * 		- ���ڿ� ���Ϸ� �Ҷ� toString���� String�ν��Ͻ��� ���� �� equals�޼ҵ带 ����Ѵ�.
 * 
 * 		- StringBuffer()				- 16���ڸ� ���� �� �ִ� ���۸� ���� StringBuffer�ν��Ͻ��� ����.
 * 		- StringBuffer(int length)
 * 		- StringBuffer(String str)
 * 
 * 		- StringBuffer append(boolean b)	- �Ű������� �Էµ� ���� ���ڿ��� ��ȯ�Ͽ� StringBuffer�ν��Ͻ��� �����ϰ� �ִ�
 * 		- StringBuffer append(char c)		  ���ڿ��� �ڿ� �����δ�.
 * 		- StringBuffer append(char[] arr)
 * 		- StringBuffer append(double d)
 * 		- StringBuffer append(float f)
 * 		- StringBuffer append(int i)
 * 		- StringBuffer append(long l)
 * 		- StringBuffer append(Object o)
 * 		- StringBuffer append(String s)
 * 
 * 		- int capacity()					- StringBuffer�ν��Ͻ��� ����ũ�⸦ �˷��ش�. 
 * 		- int length()						- ���ۿ� ��� ���ڿ��� ���̸� �˷��ش�.
 * 		- char charAt(int index)
 * 		- StringBuffer delete(int start, int end)
 * 		- StringBuffer deleteCharAt(int index)
 * 
 * 		- StringBuffer insert(int pos, boolean b)	- �� ��° �Ű������� ���� ���� ���ڿ��� ��ȯ�Ͽ� ������ ��ġ�� �߰��Ѵ�.
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
 * 		- StringBuilderŬ������ StringBuffer���� �������� ����ȭ�� �� Ŭ�����̴�.
 * 
 * 4. Math Ŭ����
 * 
 * 		- �����ڴ� private
 * 		- Ŭ���� ���� �ν��Ͻ� ������ �ϳ��� ����, �޼������ ��� static�̰�, ��� 2���� ������ ���Ҵ�.
 * 		- public static final double E = 2.7182818284590452354;
 * 		- public static final double PI = 3.14159265358979323846;
 * 
 * 		- static double abs(double a)	-	�־��� ���� ���밪�� ��ȯ
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
 * 5. wrapper Ŭ����
 * 
 * 		- �⺻�� ���� ��ü�� �ٷ� �� �ְ� �ϴ� Ŭ����
 * 		- ��ü���� ���信���� ��� ���� ��ü�� �ٷ��� �Ѵ�.
 * 		- �ڹٿ����� 8���� �⺻���� ��ü�� �ٷ��� �ʴ´� (���� ���)
 * 		- ���δ� �⺻�� ������ ��¿ �� ���� ��ü�� �ٷ�� �ϴ� ��찡 �ִ�.
 * 			ex) �Ű������� ��ü�� �䱸�� ��, �⺻�� ���� �ƴ� ��ü�� �����ؾ��� ��, ��ü���� �񱳰� �ʿ��� �� ���
 * 		- equals()�� toString()�� �������̵� �Ǿ��ִ�.
 * 		- �� �����ڸ� ����� �� ���� ��� compareTo()�� �����Ѵ�.
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
 * < java.util ��Ű�� >
 * 
 * 1. StringJoinerŬ����	-	���ڿ� ����
 * 
 * */
