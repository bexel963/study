package gram11_UtilPackage;

/*
    - java.lang패키지
        : 가장 기본이 되는 클래스들을 포함하고 있다. 그렇기 때문에 java.lang패키지의 클래스들은 import문 없이도 사용할 수 있게 되어 있다.

    1) Object클래스 (11개)
        : Object클래스는 모든 클래스의 최고 조상이기 때문에 Object클래스의 멤버들은 모든 클래스에서 바로 사용이 가능하다.

        1. protected Object clone()
        2. public boolean equals(Object obj)           - 매개변수로 객체의 참조변수를 받아서 비교한 후 그 결과를 boolean값으로 알려준다.
        3. protected void finalize()                   - 객체가 소멸될 때 가비지 컬렉터에 의해 자동적으로 호출된다. 이 때 수행되어야하는 코드가 있을 때 오버라이딩한다.
        4. public Class getClass()
        5. public int hashCode()                       - 객체 자신의 해쉬코드를 반환
        6. public String toString()
        7. public void notify()                        - 객체 자신을 사용하려고 기다리는 쓰레드를 하나만 깨운다.
        8. public void notifyAll()                     - 객체 자신을 사용하려고 기다리는 모든 쓰레드를 깨운다.
        9. public void wait()                          - 다른 쓰레드가 notify()나 notifyAll()을 호출할 때까지 현재 쓰레드를 무한히 또는 지정된 시간동안
        10.public void wait(long timeout)                기다리게 한다.
        11.public void wait(long timeout, int nanos)
*/

/*
    - equals()
        : String클래스는 Object클래스의 equals메서드를 그대로 사용하는 것이 아니라 오버라이딩을 통해서 String인스턴스가 갖는 문자열 값을 비교하도록 되어있다.
          그렇기 때문에 같은 내용의 문자열을 갖는 두 String인스턴스에 equals메서드를 사용하면 항상 true값을 얻는 것이다.
        : Date, File, wrapper클래스의 equals메서드도 주소값이 아닌 내용을 비교하도록 오버라이딩 되어있다.
        : 그러나 StringBuffer클래스는 오버라이딩 되어있지 않다.
*/

import java.util.Arrays;
import java.util.StringJoiner;

class Equals {
    static class Person {
        long id;

        Person(long id) {
            this.id = id;
        }
        public boolean equals(Object obj) {
            if(obj instanceof Person) {
                Person p = (Person)obj;
                return this.id == p.id;
            } else {
                return false;
            }
        }
    }
    static void test() {
        Person p1 = new Person(80110811112222L);
        Person p2 = new Person(80110811112222L);

        if (p1 == p2)   // false;
            System.out.println("p1과 p2는 같은 사람.");
        else
            System.out.println("p1과 p2는 다른 사람.");
        if(p1.equals(p2))   // true
            System.out.println("p1과 p2는 같은 사람.");
        else
            System.out.println("p1과 p2는 다른 사람.");
    }
}
/*
    - hashCode()
        : 일반적으로 해시코드가 같은 두 객체가 존재하는 것이 가능하지만, Object클래스에 정의된 hashCode메서드는 객체의 주소값으로 해시코드를
          만들어 만들어 반환하기 때문에 32bit JVM에서는 서로 다른 두 객체는 결코 같은 해시코드를 가질 수 없었지만, 64 bit JVM에서는 8byte
          주소값으로 해시코드(4byte)를 만들기 때문에 해시코드가 중복될 수 있다.
        : 클래스의 인스턴스변수 값으로 객체의 같고 다름을 판단해야 하는 경우라면 equals메서드 뿐 만아니라 hashCode메서드도 적절히 오버라이딩 해야한다.
          같은 객체라면 hashCode메서드를 호출했을 때의 결과값인 해시코드도 같아야 하기 때문이다.
        : 해싱기법을 사용하는 HashMap이나 HashSet과 같은 클래스에 저장할 객체라면 반드시 hashCode메서드를 오버라이딩 해야한다.
*/
class HashCode {
    void test() {
        String str1 = new String("abc");
        String str2 = new String("abc");
        System.out.println(str1.equals(str2));
        /*
            - String클래스는 문자열의 내용이 같으면, 동일한 해시코드를 반환하도록 hashCode메서드가 오버라이딩되어 있기 때문에,
              문자열의 내용이 같은 str1과 str2에 대해 hashCode()를 호출하면 항상 동일한 해시코드값을 얻는다.
        */
        System.out.println("str1 hashCode = " + str1.hashCode());   // 95354
        System.out.println("str2 hashCode = " + str2.hashCode());   // 96354
        System.out.println();
        /*
            - System.identityHashCode(Object o)는 Object클래스의 hashCode메서드처럼 객체의 주소값으로 해시코드를 생성하기 때문에
              모든 객체에 대해 항상 다른 해시코드값을 반환할 것을 보장한다.
        */
        System.out.println("str1 identityHashCode = " + System.identityHashCode(str1)); // 586617651
        System.out.println("str2 identityHashCode = " + System.identityHashCode(str2)); // 328638398
    }
}

/*
    - toString()
        public String toString() {
            return getClass().getName() + "@" + Integer.toHexString(hashCode());
        }
        : 클래스를 작성할 때 toString()을 오버라이딩 하지 않는다면, 위와 같은 내용이 그대로 사용될 것이다.
          ex) Card@19e0bfd
              Card@139a55
        : 클래스의 이름은 같아도 해시코드값이 다르다.
*/
class ToString {
    void test() {
        String str = new String("KOREA");
        java.util.Date today = new java.util.Date();
        /*
            - String클래스의 toString()은 String인스턴스가 갖고 있는 문자열을 반환하도록 오버라이딩되어 있고,
              Date클래스의 경우, Date인스턴스가 갖고 있는 날짜와 시간을 문자열로 반환하여 반환하도록 오버라이딩되어 있다.
        */
        System.out.println(str);                // KOREA
        System.out.println(str.toString());     // KOREA
        System.out.println(today);              // Tue Nov 15 19:50:28 KST 2022
        System.out.println(today.toString());   // Tue Nov 15 19:50:28 KST 2022
    }
}
/*
    - clone()
        : protected native Object clone() throws CloneNotSupportedException { ... }
        : 자신을 복제하여 새로운 인스턴스를 생성한다.
        : Object클래스에 정의된 clone()은 단순히 인스턴스변수의 값만 복사하기 때문에 참조타입의 인스턴스 변수가 있는 클래스는
          완전한 인스턴스 복제가 이루어지지 않는다.
          예를 들어 배열의 경우, 복제된 인스턴스도 같은 배열의 주소를 갖기 때문에 복제된 인스턴스의 작업이 원래의 인스턴스에 영향을 미치게 된다.
          이런 경우 clone메서드를 오버라이딩해서 새로운 배열을 생성하고 배열의 내용을 복사하도록 해야 한다.
        : Cloneable인터페이스를 구현한 클래스의 인스턴스만 clone()을 통한 복제가 가능한데, 그 이유는 인스턴스의 데이터를 보호하기 위해서이다.
          Cloneable인터페이스가 구현되어 있다는 것은 클래스 작성자가 복제를 허용한다는 의미이다.
*/
class Clone {
    static class Point implements Cloneable {   // clone()을 사용하려면, 먼저 복제할 클래스가 Cloneable인터페이스를 구현해야 한다.
        int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        @Override
        public String toString() {
            return "x=" + x + ", " + "y=" + y;
        }
        /*
            - clone()을 오버라이딩 하면서 접근 제어자를 protected에서 public으로 변경한다.
              그래야만 상속관계가 없는 다른 클래스에서 clone()을 호출 할 수 있다.
        */
//        @Override
//        public Object clone() {
//            Object obj = null;
//            try {
//                obj = super.clone();
//            } catch (CloneNotSupportedException e) { }  // Object클래스의 clone()은 Cloneable을 구현하지 않은 클래스 내에서 호출되면 예외를 발생시킨다.
//            return obj;
//        }
        /*
            - 공변 번환타입
                : JDK1.5부터 추가되었는데, 오버라이딩 할 때 조상 메서드의 반환타입을 자손 클래스의 타입으로 변경을 허용하는 것이다.
                  공변 반환타입을 사용하면, 조상의 타입이 아닌 실제로 반환되는 자손 객체의 타입으로 반환할 수 있어 번거로운 형변환이 줄어든다는 장점이 있다.
        */
        @Override
        public Point clone() {
            Object obj = null;
            try {
                obj = super.clone();    // 조상인 Object의 clone()을 호출한다.
            } catch (CloneNotSupportedException e) { }
            return (Point)obj;
        }

    }
    static void test() {
        Point original = new Point(3, 5);
        //Point copy = (Point)original.clone();
        Point copy = original.clone();  // 공변환타입 사용 -> 형변환 안 해도됨.
        System.out.println(original);
        System.out.println(copy);
    }
    /*
        - 배열도 객체이기 때문에 Object클래스를 상속받으며, 동시에 Cloneable인터페이스와 Serializable인터페이스가 구현되어 있다.
          그래서 Object클래스의 멤버들을 모두 상속받는다.
          Object클래스에는 protected로 정의되어있는 clone()을 배열에서는 public으로 오버라이딩하였기 때문에 어디서나 직접 호출이 가능하다.
          그리고 원본과 같은 타입을 반환하므로 형변환이 필요 없다.
        - 배열 뿐 아니라 java.util패키지의 Vector, ArrayList, LinkedList, HashSet, TreeSet, HashMap, TreeMap, Calendar, Date와
          같은 클래스들이 이와 같은 방식으로 복제가 가능하다.
        - clone()으로 복제가 가능한 클래스인지 확인하려면 Java API에서 Cloneable을 구현했는지 확인하면 된다.
    */
    static void test2() {
        int[] arr = {1,2,3,4,5};
        int[] arrClone = arr.clone();
        arrClone[0] = 6;
        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(arrClone));
    }
    static void test3() {
        int[] arr = {1,2,3,4,5};
        int[] arrClone = new int[arr.length];

        System.arraycopy(arr, 0, arrClone, 0, arr.length);
        arrClone[0] = 6;

        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(arrClone));
    }
}

/*
    - 얕은복사, 깊은복사
*/
class SwallowOrDeepCopy {
    static class Point {
        int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public String toString() { return "("+x+", "+y+")"; }
    }
    static class Circle implements Cloneable {
        Point p;
        double r;

        Circle(Point p, double r) {
            this.p = p;
            this.r =r;
        }
        public Circle shallowCopy() {
            Object obj = null;
            try {
                obj = super.clone();
            } catch (CloneNotSupportedException e) { }
            return (Circle)obj;
        }
        public Circle deepCopy() {
            Object obj = null;
            try {
                obj = super.clone();
            } catch (CloneNotSupportedException e) { }

            Circle circle = (Circle)obj;
            circle.p = new Point(this.p.x, this.p.y);

            return circle;
        }
        public String toString() {
            return "[p=" + this.p + ", " + "r=" + this.r + "]";
        }
    }
    static void test() {
        Circle c1 = new Circle(new Point(1, 1), 2.0);
        Circle c2 = c1.shallowCopy();
        Circle c3 = c1.deepCopy();
        System.out.println("c1 = " + c1);
        System.out.println("c2 = " + c2);
        System.out.println("c3 = " + c3);

        c1.p.x = 9;
        c1.p.y = 9;
        System.out.println("= c1 변경 후 =");
        System.out.println("c1 = " + c1);
        System.out.println("c2 = " + c2);
        System.out.println("c3 = " + c3);
    }
}

/*
    - getClass()
        : 자신이 속한 클래스의 Class객체를 반환한다. Class객체는 이름이 'Class'인 클래스의 객체이다.
          Class객체는 클래스의 모든 정보를 담고 있으며, 클래스 당 1개만 존재한다. 그리고 클래스 파일이 '클래스 로더'에 의해서
          메모리에 올라갈 때, 자동으로 생성된다.
          클래스 로더는 실행 시에 필요한 클래스를 동적으로 메모리에 로드하는 역할을 한다. 먼저 기존에 생성된 클래스 객체가 메모리에 존재하는지 확인하고,
          있으면 객체의 참조를 반호나하고 없으면 클래스 패스에 지정된 경로를 따라서 클래스 파일을 찾는다.
          못 찾으면 ClassNotFoundException이 발생하고, 찾으면 해당 클래스 파일을 읽어서 Class객체로 반환한다.
          파일 형태로 저장되어 있는 클래스들을 읽어서 Class클래스에 정의된 형식으로 변환하는 것이다.
          즉, 클래스 파일을 읽어서 사용하기 편한 형태로 저장해 놓은 것이 클래스객체이다.
        : Class객체를 이용하면 클래스에 저으이된 멤버의 이름이나 ㅐ수 등, 클래스에 대한 모든 정보를 얻을 수 있기 때문에 Class객체를 통해서 객체를
          생성하고 메서드를 호출하는 등 보다 동적인 코드를 작성할 수 있다.
    - Class객체 얻는 방법
         : 생성된 객체로 부터 얻는 방법                 -> Class clazz = new Card().getClass();
         : 클래스 리터럴(*.class)로 부터 얻는 방법      -> Class clazz = Card.class;
         : 클래스 이름으로 부터 얻는 방법               -> Class clazz = Class.forName("Card");

         : 특히 forName()은 특정 클래스 파일, 예를 들어 데이터베이스 드라이버를 메모리에 올릴 때 주로 사용한다.
*/
class Reflection {
    static class Card {
        String kind;
        int num;
        Card() {
            this("SPADE", 1);
        }
        Card(String kind, int num) {
            this.kind = kind;
            this.num = num;
        }
        public String toString() {
            return kind + ":" + num;
        }
    }
    static void test() {
        Card c = new Card("HEART", 3);
        //Card c2 = Card.class.newInstance();
        Class clazz = c.getClass();

        System.out.println(c);
        System.out.println(clazz.getName());
        System.out.println(clazz.toGenericString());
        System.out.println(clazz.toString());
    }
    /*
        - 결과
            HEART:3
            gram11_UtilPackage.Reflection$Card
            static class gram11_UtilPackage.Reflection$Card
            class gram11_UtilPackage.Reflection$Card
    */
}

/*
    - String클래스
        : String클래스에는 문자열을 저장하기 위해서 문자형 배열 참조변수(char[]) value를 인스턴스 변수로 정의해 놓고있다.
          인스턴스 생성 시 생성자의 매개변수로 입력받은 문자열은 이 인스턴스변수에 문자형 배열로 저장되는 것이다.
          String클래스는 앞에 final이 붙어 있으므로 다른 클래스의 조상이 될 수 없다.

          public final class String implements java.io.Serializable, Comparable {
                private char[] value;
                ....
          }

        : 한 번 생성된 String인스턴스가 갖고 있는 문자열은 읽어 올 수만 있고, 변경할 수는 없다.
          예를 들어 '+'연산자를 이용해서 문자열을 결합하는 경우 인스턴스 내의 문자열이 바뀌는 것이 아니라 연산 결과인 새로운 문자열이 담긴
          String인스턴스가 생성되는 것이다.
          이처럼 덧셈연산자를 사용해서 문자열을 결합하는 것인 매 연산 시 마다 새로운 문자열을 가진 String인스턴스가 생성되어 메모리 공간을
          차지하게 되므로 가능한 한 결합 횟수를 줄이는 것이 좋다.
        : StringBuffer인스턴스에 저장된 문자열은 변경이 가능하므로 하나의 StringBuffer인스턴스만으로도 문자열을 다루는 것이 가능하다.
        : String클래스의 생성자를 이용한 경우에는 new연산자에 의해서 메모리할당이 이루어지기 때문에 항상 새로운 String인스턴스가 생성된다.
          그러나 문자열 리터럴은 이미 존재하는 것을 재사용하는 것이다.

    - 문자열 리터럴
        : 문자열 리터럴은 클래스가 메모리에 로드될 때 자동적으로 미리 생성된다.
        : 자바 소스파일에 포함된 모든 문자열 리터럴은 컴파일 시에 클래스 파일에 저장된다. 이 때 같은 내용의 문자열 리터럴은 한 번만 저장된다.
          문자열 리터럴도 String인스턴스이고, 한 번 생성하면 내용을 변경할 수 없으니 하나의 인스턴스를 공유하면 되기 때문이다.
          String리터럴들은 컴파일 시에 클래스파일에 저장된다.
                    String s1 = "AAA";
                    String s2 = "AAA";
                    String s3 = "AAA";
         "AAA"를 담고 있는 String인스턴스가 하나 생성된 후, 참조변수 s1, s2, s3는 모두 이 String인스턴스를 참조하게 된다.
         클래스 파일에는 소스파일에 포함된 모든 리터럴의 목록이 있다. 해당 클래스 파일이 클래스 로더에 의해 메모리에 올라갈 때, 이 리터럴의 목록에
         있는 리터럴들이 JVM내에 있는 '상수 저장소(constant pool)'에 저장된다. 이 때 이곳에 "AAA"와 같은 문자열 리터럴이 자동적으로 생성되어
         저장되는 것이다.

    - 빈 문자열
        : char형 배열도 길이가 0인 배열을 생성할 수 있고, 이 배열을 내부적으로 가지고 있는 문자열이 빈 문자열이다.
          C언어에서는 길이가 0인 배열을 선언할 수 없다.
*/

/*
    - String클래스의 생성자와 메서드
*/
class StringMethods {
    static void test() {

        String s1 = new String("Hello");

        char[] c1 = { 'H', 'e', 'l', 'l', 'o' };
        String s2 = new String(c1);

        StringBuffer sb = new StringBuffer("Hello");
        String s3 = new String(sb);

        String s4 = "Hello";
        String s5 = "0123456";
        char c2 = s4.charAt(1);
        char c3 = s5.charAt(1);

        int i1 = "aaa".compareTo("aaa");    // 0
        int i2 = "aaa".compareTo("bbb");    // -1
        int i3 = "bbb".compareTo("aaa");    // 1

        String s6 = "Hello";
        String s7 = s6.concat(" World");    // Hello World

        String s8 = "abcdefg";
        boolean b1 = s8.contains("bc");

        String s9 = "Hello";
        boolean b2 = s9.equals("Hello");    // true
        boolean b3 = s9.equals("hello");    // false
        boolean b4 = s9.equalsIgnoreCase("HELLO");  // true
        boolean b5 = s9.equalsIgnoreCase("heLLo");  // true

        String s10 = "Hello";
        int idx1 = s10.indexOf('o');    // 4
        int idx2 = s10.indexOf('k');    // -1
        int idx3 = s10.indexOf('e', 0);     // 1
        int idx4 = s10.indexOf('e', 2);     // -1

        String s11 = "ABCDEFG";
        int idx5 = s11.indexOf("CD");   // 2

        String s12 = new String("abc");
        String s13 = new String("abc");
        boolean b6 = (s12 == s13);                      // false
        boolean b7 = s12.equals(s13);                   // true
        // 문자열을 상수풀에 등록한다. 이미 상수풀에 같은 내용의 문자열이 있을 경우 그 문자열의 주소값을 반환한다.
        boolean b8 = s12.intern() == s13.intern();      // true

        String s14 = "java.lang.Object";
        int idx6 = s14.lastIndexOf('.');    // 9
        int idx7 = s14.indexOf('.');           // 4

        String s15 = "java.lang.java";
        int idx8 = s15.lastIndexOf("java"); // 10
        int idx9 = s15.indexOf("java");         // 0

        String s16 = "Hello";
        String s17 = s16.replace('H', 'C'); // "Cello"

        String s18 = "Hellollo";
        String s19 = s18.replace("ll", "LL");   // "HeLLoLLo"

        String s20 = "AABBAABB";
        String s21 = s20.replaceAll("BB", "bb");    // AAbbAAbb
        String s22 = s20.replaceFirst("BB", "bb");   // AAbbAABB

        String animals = "dog,cat,bear";
        String[] arr1 = animals.split(",");             // arr1[0] = "dog", arr1[1] = "cat", arr1[2] = "bear"
        String[] arr2 = animals.split(",", 2);     // arr2[0] = "dog", arr2[1] = "cat,bear"

        String[] animalArr = new String[] { "dog", "cat", "bear" };
        String str = String.join("-", animalArr);      // "dog-cat-bear"

        String s23 = "java.lang.Object";
        boolean b9 = s23.startsWith("java");    // true
        boolean b10 = s23.startsWith("lang");   // false

        String s24 = "java.lang.Object";
        String s25 = s24.substring(10); // "Object"
        String s26 = s24.substring(5, 9);        // "lang"

        String s27 = "Hello";
        String s28 = s27.toLowerCase();     // "hello"
        String s29 = s28.toUpperCase();     // "HELLO"

        String s30 = "        Hello World       ";
        String s31 = s30.trim();    // "Hello World"

        // 저장된 값을 문자열로 변환하여 반환한다.
        // 참조변수의 경우, toString()을 호출한 결과를 반환한다.
        String b = String.valueOf(true);
        String c = String.valueOf('a');
        String i = String.valueOf(100);
        String l = String.valueOf(100L);
        String f = String.valueOf(10f);
        String d = String.valueOf(10.0);

        java.util.Date dd = new java.util.Date();
        String date = String.valueOf(dd);
    }
    // join()과 StringJoiner는 JDK1.8부터 추가되었다.
    static void test2() {
        String animals = "dog,cat,bear";
        String[] arr = animals.split(",");

        System.out.println(String.join("-", arr));      // dog-cat-bear

        StringJoiner sj = new StringJoiner("/", "[", "]");
        for(String s : arr) {
            sj.add(s);
        }
        System.out.println(sj);     // [dog/cat/bear]
    }
}
/*
    - 유니코드의 보충문자
        : 유니코드는 원래 2byte, 즉 16비트 문자체계인데, 이걸로도 모자라서 20비트로 확장하게 되었다. 그래서 하나의 문자를 char타입으로 다루지 못하고,
          int타입으로 다룰 수 밖에 없다. 확장에 의해 새로 추가된 문자들을 보충 문자라고 한다.
    - 문자 인코딩 변환
        : getBytes(String charsetName)을 사용하면, 문자열의 문자 인코딩을 다른 인코딩으로 변경할 수 있다.
          자바가 UTF-16을 사용하지만, 문자열 리터럴에 포함되는 문자들은 OS의 인코딩을 사용한다. 한글 윈도우즈의 경우 문자 인코딩으로 CP494를 사용하며,
          이를 UTF-8로 변경할 수 있다. (문자 인코딩은 CP949는 MS949라고도 한다.)
        : 서로 다른 문자 인코딩을 사용하는 컴퓨터 간에 데이터를 주고받을 때는 적절한 문자 인코딩이 필요하다. 그렇지 않으면 알아볼 수 없는 내용의 문서를 보게 될 것이다.
*/
class Incoding {
    static void test() throws Exception {
        String str = "가";

        byte[] arr1 = str.getBytes("UTF-8");
        byte[] arr2 = str.getBytes("CP949");

        System.out.println("UTF-8: " + joinByteArr(arr1));  // UTF-8: [EA:B0:80]
        System.out.println("CP949: " + joinByteArr(arr2));  // CP949: [B0:A1]

        System.out.println("UTF-8: " + new String(arr1, "UTF-8"));  // 가
        System.out.println("UTF-8: " + new String(arr2, "CP949"));  // 가
    }
    static String joinByteArr(byte[] arr) {
        StringJoiner sj = new StringJoiner(":", "[", "]");
        for(byte b : arr) {
            sj.add(String.format("%02X", b));
        }
        return sj.toString();
    }
    // String.format()은 형식화된 문자열을 만들어내는 간단한 방법이다.
    static void test2() {
        String str = String.format("%d 더하기 %d는 %d입니다.", 3, 5, 3+5);
        System.out.println(str);
    }
}
/*
    - 기본형 -> String
        : 빈 문자열을 더하는 것 보다 valueOf()가 더 성능이 좋다.
        : 참조변수에 String을 더하면, 참조변수가 가리키는 인스턴스의 toString()을 호출하여 String을 얻은 다음 결합한다.
                -> String String.valueOf(boolean b)
                -> String String.valueOf(char c)
                -> String String.valueOf(int i)
                -> String String.valueOf(long l)
                -> String String.valueOf(float f)
                -> String String.valueOf(double d)

    - String -> 기본형
        : valueOf()나 parseInt()를 사용한다.
        : 예전에는 parseInt()와 같은 메서드를 많이 썻는데, 메서드의 이름을 통일하기 위해 valueOf()가 나중에 추가되었다.
          valueOf(String s)는 메서드 내부에 그저 parseInt(String s)를 호출할 뿐이므로, 두 메서드는 반환 타입만 다르지
          같은 메서드이다.
                -> boolean Boolean.parseBoolean(String s)
                -> byte    Byte.parseByte(String s)
                -> short   Short.parseShort(String s)
                -> int     Integer.parseInt(String s)
                -> long    Long.parseLong(String s)
                -> float   Float.parseFloat(String s)
                -> double  Double.parseDouble(String s)

    - byte, short -> String
        : String.valueOf(int i)

    - 문자열("A") -> 문자형('A')
        : char ch = "A".charAt(0);
*/
class Convert {

    static void test1() {
        /*
            - parseInt()나 parseFloat()같은 메서드는 문자열에 공백 또는 문자가 포함되어 있는 경우 반환 시 예외가 발생할 수 있으므로 주의해야한다.
              그래서 문자열 양 끝의 공백을 제거해주는 trim()을 습관적으로 같이 사용하기도 한다.
        */
        int val = Integer.parseInt("  123  ".trim());
        /*
            - 그러나 부호 '+'나 소수점 '.'와 float형 값을 뜻하는 f와 같은 자료형 접미사는 허용된다.
              단, 자료형에 알맞은 변환을 하는 경우에만 허용된다.
              '+'가 포함된 문자열이 parseInt()로 변환 가능하게 된 것은 JDK1.7부터이다.
        */
        int i = Integer.parseInt("1.0f");   // 예외 발생.
        float f = Float.parseFloat("1.0f"); // OK.
        int i2 = Integer.parseInt("+" + 123);
        /*
            - 이처럼 문자열을 숫자로 변환하는 과정에서는 예외가 발생하기 쉽기 때문에 주의를 기울여야 하고, 예외가 발생했을 때는 예외처리를 적절히 해주어야한다.
        */
    }
    static void test2() {
        int i = 100;
        String str = String.valueOf(i);
        double d = 200.0;
        String str2 = d + "";

        double sum = Integer.parseInt("+" + str) + Double.parseDouble(str2);   // 300.0
        double sum2 = Integer.valueOf(str) + Double.valueOf(str2);  // 300.0

        System.out.println("sum = " + sum);
        System.out.println("sum2 = " + sum2);
        System.out.println(String.join("", str, " + ", str2, " = ") + sum);
        System.out.println(str + " + " + str2 + " = " + sum2);
    }
}

class Subtract {
    static void test() {
        String fullName = "Hello.java";
        int idx = fullName.indexOf('.');    // 5
        String fileName = fullName.substring(0, idx);
        String ext = fullName.substring(idx+1);

        System.out.println(fullName + "의 확장자를 제외한 이름은 " + fileName);
        System.out.println(fullName + "의 확장자는 " + ext);
    }
}

/*
    - StringBuffer클래스
        : String클래스는 인스턴스를 생성할 때 지정된 문자열을 변경할 수 없지만 StringBuffer클래스는 변경이 가능하다.
          내부적으로 문자열 편집을 위한 버퍼를 가지고 있으며, StringBuffer인스턴스를 생성할 때 그 크기를 지정할 수 있다.
          크기를 지정하지 않으면 16개의 문자를 저장할 수 있는 크기의 버퍼를 생성한다.
          이 때, 편집할 문자열의 길이를 고려하여 버퍼의 길이를 충분히 잡아주는 것이 좋다. 편집 중인 문자열이 버퍼의 길이를 넘어서게 되면
          버퍼의 길이를 늘려주는 작업이 추가로 수행되어야하기 때문에 작업효율이 떨어진다.
          (버퍼의 크기가 작업하려는 문자열의 길이보다 작을 때는 내부적으로 버퍼의 크기를 증가시키는 작업이 수행된다.)
          StringBuffer클래스는 String클래스와 같이 문자열을 저장하기 위한 char형 배열의 참조변수를 인스턴스 변수로 선언해 놓고 있다.
          StringBuffer인스턴스가 생성될 때, char형 배열이 생성되며 이 때 생성된 char형 배열을 인스턴스변수 value가 참조하게 된다.

            public fianl class StringBuffer implements java.io.Serializable {
                   private char[] value;
                    ..
                   public StringBuffer(int length) {
                        value = new char[length];
                        shared = false;
                   }
                   public StringBuffer() {
                        this(16);
                   }
                   public StringBuffer(String str) {
                        this(str.length() + 16);
                   }
                   char[] newValue = new char[newCapacity];
                   System.arraycopy(value, 0, newValue, count);
                   value = newValue;
            }

    - StringBuffer의 변경
              StringBuffer sb = new String("abc");
              StringBuffer sb2 = sb.append("ZZ");
              sb => abcZZ, sb2 => abcZZ
              ---------------------------------------------
              StringBuffer sb = new StringBuffer("abc");
              sb.append("123").append("ZZ");
              sb => 123ZZ
        : append()는 반환타입이 StringBuffer인데 자신의 주소를 반환한다.
          sb에 새로운 문자열이 추가되고 sb자신의 주소를 반환하여 sb2에는 sb의 주소가 저장된다.
          그래서 sb, sb2 모두 같은 StringBuffer인스턴스를 가리키고 있으므로 같은 내용이 출력된다.
          그래서 하나의 StringBuffer인스턴스에 대해 연속적으로 append()를 호출하는 것이 가능하다.
          (만일 append()의 반환타입이 void였다면 연속적으로 호출 못 했을 것이다.)

    - StringBuffer의 비교
        : StringBuffer클래스는 String클래스처럼 equals메서드를 오버라이딩하지 않았다.
        : 반면에 toString()은 오버라이딩되어 있다. (toString()을 호출하면 담고있는 문자열을 String으로 반환한다.)
          그래서 StringBuffer인스턴스에 담긴 문자열을 비교하기 위해서는 StringBuffer인스턴스에 toString()을 호출해서
          String인스턴스를 얻은 다음, 여기에 equals메서드를 사용해서 비교한다.
*/

class StrBuffer {
    static void test1() {
        StringBuffer stringBuffer1 = new StringBuffer("abc");
        StringBuffer stringBuffer2 = new StringBuffer("abc");
        System.out.println(stringBuffer1 == stringBuffer2);         // false
        System.out.println(stringBuffer1.equals(stringBuffer2));    // false

        String string1 = stringBuffer1.toString();
        String string2 = stringBuffer1.toString();
        System.out.println(string1 == string2);       // false
        System.out.println(string1.equals(string2));  // true
    }

    /*
        - StringBuffer클래스의 생성자와 메서드
    */
    static void test2() {
        StringBuffer sb1 = new StringBuffer();              // 16문자를 담을 수 있는 버퍼를 가진 StringBuffer인스턴스 생성.
        StringBuffer sb2 = new StringBuffer(10);
        StringBuffer sb3 = new StringBuffer("Hi");

        StringBuffer sb4 = new StringBuffer("abc");         // sb4 => "abc"
        StringBuffer sb5 = sb4.append(true);                // sb4 => "abctrue", sb5 => "abctrue"
        sb4.append('d').append(10.0f);                      // sb4 => "abctrued.10.0", sb5 => "abctrued.10.0"
        StringBuffer sb6 = sb4.append("ABC").append(123);   // sb4 => "abctrued.10.0ABC123", sb5 => "abctrued.10.0ABC123", sb6 => "abctrued.10.0ABC123"

        StringBuffer sb7 = new StringBuffer(100);
        sb7.append("abcd");
        int bufferSize = sb7.capacity();                    // 100
        int stringSize = sb7.length();                      // 4

        StringBuffer sb8 = new StringBuffer("abc");
        char c = sb8.charAt(2);                             // c

        StringBuffer sb9 = new StringBuffer("0123456");
        StringBuffer sb10 = sb9.delete(3, 6);               // sb9 => "0126", sb10 => "0126"

        StringBuffer sb11 = new StringBuffer("0123456");
        sb11.deleteCharAt(3);                         // sb11 => "012456"

        StringBuffer sb12 = new StringBuffer("0123456");
        sb12.insert(4, '.');    // sb12 => "0123.456"

        StringBuffer sb13 = new StringBuffer("0123456");
        int length = sb13.length();     // 7

        StringBuffer sb14 = new StringBuffer("0123456");
        sb14.replace(3, 6, "AB");   // sb14 => "012AB6"

        StringBuffer sb15 = new StringBuffer("0123456");
        sb15.reverse();     // sb15 => "6543210"

        StringBuffer sb16 = new StringBuffer("0123456");
        sb16.setCharAt(5, 'o');     // sb16 => 01234o6

        StringBuffer sb17 = new StringBuffer("0123456");
        sb17.setLength(5);                      // sb17 => "01234"
        StringBuffer sb18 = new StringBuffer("0123456");
        sb18.setLength(10);                     // sb18 => "0123456    "
        String str1 = sb18.toString().trim();   // str1 => "0123456"

        StringBuffer sb19 = new StringBuffer("0123456");
        String str2 = sb19.toString();          // str2 => "0123456"

        StringBuffer sb20 = new StringBuffer("0123456");
        String str3 = sb20.substring(3);    // str3 => "3456"
        String str4 = sb20.substring(3, 5);      // str4 => "34"
    }
    static void test3() {
        StringBuffer sb = new StringBuffer("01");
        StringBuffer sb2 = sb.append(23);
        sb.append('4').append(56);

        StringBuffer sb3 = sb.append(78);
        sb3.append(9.0);

        System.out.println("sb = " + sb);       // 0123456789.0
        System.out.println("sb2 = " + sb2);     // 0123456789.0
        System.out.println("sb3 = " + sb3);     // 0123456789.0

        System.out.println(sb.deleteCharAt(10));                    // 01234567890
        System.out.println(sb.delete(3,6));                              // 01267890
        System.out.println(sb.insert(3, "abc"));                // 012abc67890
        System.out.println(sb.replace(6, sb.length(), "END"));   // 012abcEND
        System.out.println(sb.capacity());                                // 18
        System.out.println(sb.length());                                  // 9
    }
}
/*
    - StringBuilder클래스
        : StringBuffer는 멀티스레드에 안전하도록 동기화되어 있는데, 동기화는 StringBuffer의 성능을 떨어뜨린다.
          멀티쓰레드로 작성된 프로그램이 아닌 경우, StringBuffer의 동기화는 불필요하게 성능만 떨어뜨리게 된다.
          그래서 StringBuffer에서 쓰레드의 동기화만 뺀 StringBuilder가 새로 추가되었다.
        : StringBuilder는 StringBuffer와 완전히 똑같은 기능으로 작성되어 있어서 소스코드에서 StringBuffer대신 StringBuilder를 사용하도록 바꾸기만 하면 된다.
*/

/*
    - Math클래스
        : Math클래스의 생성자는 접근 제어자가 private이기 때문에 다른 클래스에서 Math인스턴스를 생성할 수 없도록 되어있다.
          그 이유는 클래스 내에 인스턴스변수가 하나도 없어서 인스턴스를 생성할 필요가 없기 때문이다.
          Math클래스의 메서드는 모두 static이며 단 2개의 상수만 정의해 놓았다.
                public static final double E = 2.7182818284590452354;
                public static final double PI = 3.14159265358979323846;
*/
/*
    - Math클래스의 메서드
        : static double abs(double a)
          static float abs(float f)
          static int abs(int f)
          static long abs(long f)

          static double max(double a, double b)         static double min(double a, double b)
          static float max(float a, float b)            static float min(float a, float b)
          static int max(int a, int b)                  static int min(int a, int b)
          static long max(long a, long b)               static long min(long a, long b)

          static double random() -> 0.0 ~ 1.0범위의 임의의 double값을 반환한다. (1.0은 범위에 포함하지 않는다.)
*/
/*
    - 올림, 버림, 반올림
        : static double ceil(double a)
          static double floor(double a)
          static double rint(double a)
            : 주어진 double값과 가장 가까운 정수값을 double형으로 반환한다.
              단, 두 정수의 정가운데 있는 값(1.5, 2.5, 3.5 등)은 짝수를 반환한다.
                      rint(1,2) = 1.0
                      rint(2.6) = 3.0
                      rint(3.5) = 4.0
                      rint(4.5) = 4.0
          static long round(double a)
          static long round(float a)
*/
class Round {
    static void test() {
        double val = 90.7552;
        System.out.println(Math.round(val));            // 91
        val *= 100;
        System.out.println(Math.round(val));            // 9076
        System.out.println(Math.round(val) / 100);      // 90
        System.out.println(Math.round(val) / 100.0);    // 90.76
        System.out.println();
        System.out.println(Math.ceil(1.1));             // 2.0
        System.out.println(Math.floor(1.5));            // 1.0
        System.out.println(Math.round(1.1));            // 1
        System.out.println(Math.round(1.5));            // 2
        // rint()는 반환값이 double이고, 두 정수의 정 가운데 있는 값은 가장 가까운 짝수 정수를 반환한다.
        System.out.println(Math.rint(2.5));             // 2.0
        System.out.println(Math.rint(1.5));             // 2.0
        System.out.println(Math.round(-1.5));           // -1
        System.out.println(Math.rint(-1.5));            // -2.0
        System.out.println(Math.ceil(-1.5));            // -1.0
        System.out.println(Math.floor(-1.5));           // -2.0
    }
}

/*
    - 예외를 발생시키는 메서드
        : 메서드 이름에 'Exact'가 포함된 메서드들이 JDK1.8부터 새로 추가되었다.
          연산자는 단지 결과를 반환할 뿐, 오버플로우의 발생 여부에 대해 열려주지 않는데 이들은 정수형 간의 연산에서 발생할 수 있는 오버플로우를 감지한다.
          오버플로우가 발생하면 예외를 발생 시킨다.
                int addExact(int x, int y)
                int subtractExact(int x, int y)
                int multiplyExact(int x, int y)
                int imcrementExact(int x, int y)    // a++
                int decrementExact(int x, int y)    // a--
                int negateExact(int x, int y)       // -a
                int toIntExact(int x, int y)        // (int)value

    - StricMath클래스
        : Math클래스는 최대한의 성능을 얻기 위해 JVM이 설치된 OS의 메서드를 호출해서 사용한다.
         즉, OS에 의존적인 계산을 하고 있는 것이다. 예를 들어 부동소수점 계산의 경우, 반올림의 처리방법 설정이 OS마다 다를 수 있기 때문에
         자바로 작성된 프로그램임에도 불구하고 컴퓨터마다 결과가 다를 수 있다.
         이러한 차이를 없애기 위해 성능은 다소 포기하는 대신, 어떤 OS에서 실행되어도 항상 같은 결과를 얻도록 Math클래스를 새로 작성한 것이
         StrincMath클래스이다.
*/
class Etc {
    static void test() {
        int i = Integer.MIN_VALUE;

        System.out.println("i = " + i);
        System.out.println("-i = " + (-i));

        try {
            System.out.printf("negateExact(%d) = %d\n", 10, Math.negateExact(10));
            System.out.printf("negateExact(%d) = %d\n", -10, Math.negateExact(-10));
            System.out.printf("negateExact(%d) = %d\n", i, Math.negateExact(i));    // 예외 발생
        } catch(ArithmeticException e) {
            System.out.println("예외발생!!!");
            System.out.printf("negateExact(%d) = %d\n", (long)i, Math.negateExact((long)i));
        }
    }
    static void test2() {
        int x1=1, y1=1;
        int x2=2, y2=2;

        double c = Math.sqrt(Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2));  // 1.414214 - 두 점 간의 거리
        double a = c * Math.sin(Math.PI/4); // 1.000000
        double b = c * Math.cos(Math.PI/4); // 1.000000

        System.out.println(24 * Math.log10(2)); // 7.224720
        System.out.println(53 * Math.log10(2)); // 15.95459
    }
}

/*
    - 래퍼(wrapper)클래스
        : 때로는 기본형 변수도 어쩔 수 없이 객체로 다뤄야 하는 경우가 있다.
          예를 들면, 매개변수로 객체를 요구할 때, 기본형 값이 아닌 객체로 저장해야할 때, 객체간의 비교가 필요할 때 등등...
          이 때 사용되는 것이 래퍼클래스이다. 8개의 기본형을 대표하는 8개의 래퍼클래스가 있는데, 이 클래스들을 이용하면 기본형 값을
          객체로 다룰 수 있다.
          래퍼 클래스의 생성자는 매개변수로 문자열이나 각 자료형의 값들을 인자로 받는데, 이 때 주의해야할 것은 생성자의 매개변수로
          문자열을 제공할 때, 각 자료형에 알맞은 문자열을 사용해야한다는 것이다.
                    new Integer("1.0"); -> NumberFormatException 발생

        : 래퍼 클래스들은 객체생성 시에 생성자의 인자로 주어진 각 자료형에 알맞은 값을 내부적으로 저장하고 있으며, 이에 관련된 여려 메서드가 정의되어있다.

                    public final class Integer extends Number implements Comparable {
                            .....
                            private int value;
                            .....
                    }
*/

class Wrapper {
    // 래퍼클래스의 생성자
    static void test() {
        Boolean b = new Boolean(true);
        Boolean b2 = new Boolean("true");
        Character c = new Character('a');
        Byte bt = new Byte((byte) 10);
        Byte bt2 = new Byte("10");
        Short s = new Short((short)10);
        Short s2 = new Short("10");
        Integer i = new Integer(100);
        Integer i2 = new Integer("100");
        Long l = new Long(100);
        Long l2 = new Long("100");
        Float f = new Float(1.0);
        Float f2 = new Float(1.0f);
        Float f3 = new Float("1.0f");
        Double d = new Double(1.0);
        Double d2 = new Double("1.0");
    }
    /*
        - 래퍼 클래스들은 모두 equals()가 오버라이딩되어 있어서 주소값이 아닌 객체가 가지고 있는 값을 비교한다.
          오토박싱이 된다고 해도 Integer객체에 비교연산자를 사용할 수 없다.
          대신 compareTo()를 제공한다.
          그리고 toString()도 오버라이딩되어 있어서 객체가 가지고 있는 값을 문자열로 변환하여 반환한다.
    */
    static void test2() {
        Integer i = new Integer(100);
        Integer i2 = new Integer(100);

        System.out.println(i==i2);              // false
        System.out.println(i.equals(i2));       // true
        System.out.println(i.compareTo(i2));    // 0
        System.out.println(i.toString());       // 100
        System.out.println();
        System.out.println(Integer.MAX_VALUE);  // 2147483647
        System.out.println(Integer.MIN_VALUE);  // -2147483648
        System.out.println(Integer.SIZE);       // 32
        System.out.println(Integer.BYTES);      // 4
        System.out.println(Integer.TYPE);       // int
    }
}

/*
    - Number클래스
        : 추상클래스로 내부적으로 숫자를 멤버변수로 갖는, 기본형 중에서 숫자와 관련된 래퍼 클래스들의 조상이다.

                public abstract class Number implements java.io.Serializable {

                        public abstract int intValue();
                        public abstract long longValue();
                        public abstract float floatValue();
                        public abstract double doubleValue();

                        public byte byteValue() {
                            return (byte)intValue();
                        }
                        public short shortValue() {
                            reutnr (short)intValue();
                        }
                }
*/

class Convert_ {
    // 문자열을 숫자로 변환하기
    static void convert0() {
        int i = new Integer("100").intValue();
        int i2 = Integer.parseInt("100");
        Integer i3 = Integer.valueOf("100");
    }
    /*
        - JDK1.5부터 도입된 '오토박싱' 기능 때문에 반환값이 기본형일 때와 래퍼클래스일 때의 차이가 없어졌다.
          그래서 그냥 구별없이 valueOf()를 쓰는 것도 된다. 성능은 valueOf()가 조금 더 느리다.
    */
    // 문자열 -> 기본형 : 기본형을 반환
    static void convert1() {
        byte b = Byte.parseByte("10");
        short s = Short.parseShort("100");
        int i = Integer.parseInt("100");
        long l = Long.parseLong("100");
        Float f = Float.parseFloat("3.14");
        Double d = Double.parseDouble("3.14");
    }
    // 문자열 -> 래퍼클래스 : 래퍼 클래스 타입을 반환
    static void convert2() {
        byte b = Byte.valueOf("10");
        short s = Short.valueOf("100");
        int i = Integer.valueOf("100");
        long l = Long.valueOf("100");
        Float f = Float.valueOf("3.14");
        Double d = Double.valueOf("3.14");
    }

    /*
        - 문자열이 10진수가 아닌 다른 진법(radix)의 숫자일 때도 변환이 가능하다.
          16진법에서는 'A~F'의 문자도 허용하므로 'Integer.parseInt("FF", 16)'과 같은 코드가 가능하지만, 진법을 생략하면
          10진수로 간주하기 때문에 'Integer.parseInt("FF", 16)'에서는 NumberFormatException이 발생한다.
    */
    static void convert3() {
        int i1 = Integer.parseInt("100", 2);    // 4
        int i2 = Integer.parseInt("100", 8);    // 64
        int i3 = Integer.parseInt("100", 16);   // 256
        int i4 = Integer.parseInt("FF", 16);    // 256
        int i5 = Integer.parseInt("FF");    // NumberFormatException!!

        int w1 = Integer.valueOf("100", 2);
        int w2 = Integer.valueOf("100", 8);
        int w3 = Integer.valueOf("100", 16);
        int w4 = Integer.valueOf("FF", 16);
        int w5 = Integer.valueOf("FF");     // NumberFormatException!!
    }
}

/*
    - 오토박싱 & 언박싱
        : JDK1.5이전에는 기본형과 참조형 간의 연산이 불가능했기 때문에, 래퍼 클래스로 기본형을 객체로 만들어서 연산해야 했다.
                    int i = 5;
                    Integer iObj = new Integer(7);
                    int sum = i + iObj; // ERROR;
          그러나 이제는 기본형과 참조형 간의 덧셈이 가능하다. 자바 언어의 규칙이 바뀐 것은 아니고, 컴파일러가 자동으로 변환하는 코드를
          넣어주기 때문이다.
          심지어는 참조형 간의 연산도 가능하다.
          위의 경우에서 컴파일러가 Integer객체를 int타입 값으로 변환해주는 intValue()를 추가해준다.
                    int i = 5;
                    Integer iObj = new Integer(7);
                    int sum = i + iObj.intValue();
          이 외에도 내부적으로 객체 배열을 가지고 있는 Vector클래스나 ArrayList클래스에 기본형 값을 저장해야할 때나 형변환이 필요한 때도
          컴파일러가 자동적으로 코드를 추가해 준다.
          기본형 값을 래퍼 클래스의 객체로 자동 변환해주는 것을 '오토박싱'이라고 하고, 반대로 변환하는 것을 '언박싱'이라고 한다.
                    ArrayList<Integer> list = new ArrayList<Integer>;
                    list.add(3);                // 오토박싱.
                    int value = list.get(0);    // 언박싱
*/
class Boxing {
    static void test() {
        int i = 10;

        // 기본형을 참조형으로 형변환(형변환 생략가능)
        Integer intg = (Integer)i;  // == Integer.valueOf(i);
        Object obj = (Object)i;     // == (Object)Integer.valueOf(i);

        Long lng = 100L;    // == new Long(100L);

        int i2 = intg + 10;     // 참조형과 기본형간의 연산 가능
        long l = intg + lng;    // 참조형 간의 덧셈도 가능

        Integer intg2 = new Integer(2);
        int i3 = (int)intg2;    // 참조형을 기본형으로도 형변환 가능(형변환 생략가능)

        Integer intg3 = intg2 + i3;
    }
}
public class Lang {
    public static void main(String[] args) {

        Wrapper.test2();
    }
}













