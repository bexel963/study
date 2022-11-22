package gram11_UtilPackage;


import java.sql.SQLOutput;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Objects;
import java.util.Random;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/*
    - java.util.Objects클래스
        : Object클래스의 보조 클래스로 Math클래스처럼 모든 메서드가 static 이다. 객체의 비교나 널 체크에 유용하다.
          Object클래스의 메서드와 이름이 같은 것들과 충돌이 날 경우에는 클래스 이름으로 구별해준다.
                  1. isNull()          - 해당 객체가 널인지 확인해서 null이면 true를 반환하고, 아니면 false를 반환한다.
                  2. nonNull()         - isNull()과 정반대의 일을 한다. == !Objects.isNull(obj)
                  3. requireNonNull()  - 해당 객체가 널이 아니어야 하는경우에 사용한다. 객체가 null이면, NullPointerException을 발생시킴.
                                      두 번째 매개변수로 지정하는 문자열은 예외의 메시지가 된다.

        : Object클래스에는 두 객체의 등가비교를 위한 equals()만 있고, 대소비교를 위한 compare()가 없다.
          그래서 Objects에는 compare()가 추가되었다. compare()는 0, 양수, 음수의 값을 반환한다.
                  4. static int compare(Object a, Object b, Comparator c)
                  5. static boolean equals(Object a, Object b)
                  6. static boolean deepEquals(Object a, Object b)

        : Object클래스에 정의된 equals()가 Objects클래스에도 정의되어 있는데, Objects의 equals()의 장점은 null검사를 하지 않아도 된다는 것이다.
          equals()의 내부에서 a와 b의 널 검사를 하기 때문에 따로 널 검사를 위한 조건식을 따로 넣지 않아도 되는 것이다.
                  public static boolean equals(Object a, Object b) {
                        return (a==b) || (a!=null && a.equals(b));
                  }
          a와 b가 모두 널인 경우에는 참을 반환한다는 점을 빼고는 특별한 것이 없다.

        : deepEquals()는 객체를 재귀적으로 비교하기 때문에 다차원 배열의 비교도 가능하다.
          equals()로 다차원 배열을 비교하려면 반복문과 함께 사용해야 하는데, deepEquals()를 쓰면 간단히 끝난다.

        : toString()도 equlas()처럼, 내부적으로 널 검사를 한다는 것 빼고는 특별한 것이 없다.
          두 번째 메서드는 o가 널일 때, 대신 사용할 값을 지정할 수 있어서 유용하다.
                  7. static String toString(Object o)
                  8. static String toString(Object o, String nullDefault)

        : hashCode()는 내부적으로 널 검사를 한 후에 Object클래스의 hashCode()를 호출할 뿐이다. 단, 널일 때는 0을 반환한다.
                  9. static int hashCode(Object o)
                  10. static int hash(Object... values)
*/
class ObjectsClass {
    static String setName(String name) {
        if(name==null) {
            throw new NullPointerException("name must not be null.");
        }
        return name;
    }
    // 위에서 하는 매개변수의 유효성 검사를 아래처럼 할 수 있다.
    static String setName2(String name) {
        String str = Objects.requireNonNull(name, "name must not be null.");
        return str;
    }
    static void test1() {
        String a = "123";
        String b = "123";
        if(a!=null && a.equals(b)) {             // a가 null인지 반드시 확인해야 한다.!!!
            int num = Integer.parseInt((a+b));
        }
        if(Objects.equals(a, b)) {               // null검사를 하지 않아도 된다.!!!
            int num = Integer.parseInt((a+b));
        }
    }
    static void test2() {
        String[][] str2D_1 = new String[][] {{"aaa", "bbb"}, {"AAA", "BBB"}};
        String[][] str2D_2 = new String[][] {{"aaa", "bbb"}, {"AAA", "BBB"}};

        System.out.println(Objects.equals(str2D_1, str2D_2));       // false
        System.out.println(Objects.deepEquals(str2D_1, str2D_2));   // true
        System.out.println(Objects.isNull(null));               // true
        System.out.println(Objects.nonNull(null));              // false
        System.out.println(Objects.hashCode(null));              // 0
        System.out.println(Objects.toString(null));              // null
        System.out.println(Objects.toString(null, ""));              // ""

        // String클래스에 상수로 정의되어 있는 Comparator
        Comparator c = String.CASE_INSENSITIVE_ORDER;   // 대소문자 구분 안하는 비교기준
        System.out.println(Objects.compare("aa", "bb", c)); // -1
        System.out.println(Objects.compare("bb", "aa", c)); // 1
        System.out.println(Objects.compare("ab", "AB", c)); // 0

    }
}

/*
    - java.util.Random클래스
        : 사실 Math.random()은 내부적으로 Random클래스의 인스턴스를 생성해서 사용하는 것이므로 둘 중에서 편한 것을 사용하면 된다.
                double rand = Math.random();
                double rand = new Random().nextDouble();    // 위와 동일한 문장
        : 예를 들어 1~6사이의 정수를 난수로 얻고자 할 때는
                int num = (int)(Math.random()*6) + 1
                int num = new Random().nextInt(6) + 1;      // nextInt(6)은 0~6사이의 정수를 반환한다.
        : Math.random()과 Random의 가장 큰 차이점은 종자값(seed)을 설정할 수 있다는 것이다. 종자값이 같은 Random인스턴스들은 항상
          같은 난수를 같은 순서대로 반환한다.
          종자값은 난수를 만드는 공식에 사용되는 값으로 같은 공식에 같은 값을 넣으면 같은 결과를 얻는 것처럼 같은 종자값을 넣으면 같은 난수를 얻게 된다.
          같은 종자값을 갖는 Random인스턴스는 시스템이나 실행시간 등에 관계 없이 항상 같은 순서로 반환할 것을 보장한다.

    - Random클래스의 생성자와 메서드
        : 생성자 Random()은 종자값을 System.currentTimeMillis()로 하기 때문에 생성할 때마다 얻는 난수가 달라진다.
          (System.currentTimeMillis()는 현재시간을 천분의 1초단위로 변환해서 반환한다.
                public Random() {
                    this(System.currentTimeMillis());
                }
        : 목록
                Random()                        - Stystem.현재시간을 종자값으로 이용하는 Random인스턴스 생성
                Random(long seed)               - 매개변수 seed를 종자값으로 하는 Random인스턴스 생성
                boolean nextBoolean()           - boolean타입의 난수를 반환
                void nextBytes(byte[] bytes)    - bytes배열에 byte타입의 난수를 채워 반환
                double nextDouble()             - double타입의 난수를 반환 (0.0 <= x < 1.0)
                float nextFloat()               - float타입의 난수를 반환
                double nextGaussian()           - 평균은 0.0이고 표준편차는 1.0인 가우시안분포에 따른 double형의 난수를 반환
                int nextInt()                   - int타입의 난수를 반환(int범위)
                int nextInt(int n)              - 0 ~ n의 범위에 있는 int값을 반환 (n은 범위에 포함되지 않음)
                long nextLong()                 - long타입의 난수 반환
                void setSeed(long seed)         - 종자값을 주어진 값으로 변경
*/
class RandomClass {
    static void test1() {
        Random rand1 = new Random(1);
        Random rand2 = new Random(1);

        for(int i=0 ; i<5 ; i++) {
            System.out.println(i + ": " + rand1.nextInt());
        }
        System.out.println();
        for(int i=0 ; i<5 ; i++) {
            System.out.println(i + ": " + rand2.nextInt());
        }
    }
    static void test2() {
        int[] count = new int[10];
        System.out.println(Arrays.toString(count));
        int rand = 0;
        for(int i=0 ; i<100 ; i++) {
            rand = new Random().nextInt(10);
            ++count[rand];
        }
        System.out.println(Arrays.toString(count));
        System.out.println("-----");
        int i = 0;
        for(int cnt : count) {
            System.out.print(i++ + "의 개수: ");
            for(int j=0 ; j<cnt ; j++) {
                System.out.print("#");
            }
            System.out.println();
        }
    }
    // 배열 arr을 from과 to범위의 값들로 채워서 반환
    static int[] fillRand(int[] arr, int from, int to) {
        for(int i=0 ; i<arr.length ; i++) {
            arr[i] = getRand(from, to);
        }
        return arr;
    }
    // 배열 arr을 배열 data에 있는 값들로 채워서 반환
    static int[] fillRand(int[] arr, int[] data) {
        for(int i=0 ; i<arr.length ; i++) {
            arr[i] = data[getRand(0, data.length)];
        }
        return arr;
    }
    // from과 to범위의 정수값을 반환. (from과 to 모두 범위에 포함된다.)
    static int getRand(int from, int to) {
        return (int) (Math.random() * (Math.abs(to - from)) + Math.min(from, to));
    }
}
/*
    - 보통 연속적인 범위 내에서 값을 얻어오지만, 때로는 불연속적인 범위에 있는 값을 임의로 얻어 와야 하는 경우도 있다.
      이런 경우 불연속적인 값을 배열에 저장한 후, 배열의 index를 임의로 어어서 배열에 저장된 값을 읽어오도록 하면 된다.
*/
class MakeTestData {
    final static int RECORD_NUM = 10;
    final static String TABLE_NAME = "TEST_TABLE";
    final static String[] CODE1 = {"010", "011", "017", "018", "019"};
    final static String[] CODE2 = {"남자", "여자"};
    final static String[] CODE3 = {"10대", "20대", "30대", "40대", "50대"};
    static String print = "";

    static void makeSample() {
        for(int i=0 ; i<RECORD_NUM ; i++) {
            String preNum = CODE1[(int)(Math.random()*CODE1.length)];
            String sex = CODE2[(int)(Math.random()*CODE2.length)];
            String age = CODE3[(int)(Math.random()*CODE3.length)];
            int num = (int)(Math.random() * 100) + 100;
            print = String.format("INSERT INTO %s VALUES ('%s', '%s', '%s',   %d)", TABLE_NAME, preNum, sex, age, num);
            System.out.println(print);
        }
    }
}

/*
    - java.util.regex패키지 (정규식)
        : 테스트 데이터 중에서 원하는 조건(패턴, pattern)과 일치하는 문자열을 찾아내기 위해 사용하는 것으로 미리 정의된 기호와 문자를
          이용해서 작성한 문자열을 말한다. 원래 Unix에서 사용하던 것이고 Perl의 강력한 기능이었는데 요즘은 Java를 비롯해 다양한 언어에서
          지원하고 있다.
          정규식을 이용하면 많은 양의 텍스트 파일 중에서 원하는 데이터를 손쉽게 뽑아낼 수도 있고 입력된 데이터가 형식에 맞는지 체크할 수도 있다.
        : Pattern은 정규식을 정의하는데 사용되고, Matcher는 정규식을 데이터와 비교하는 역할을 한다.
*/
class RegularExpression {
    static void test1() {
        String[] data = {
                "bat", "baby", "bonus", "cA", "ca", "co", "c.", "c0", "car", "combat", "count", "date", "disc"
        };

        // 1. 정규식을 매개변수로 Pattern클래스의 static메서드인 'Pattern compile(String regex)'을 호출하여 Pattern인스턴스를 얻는다.
        Pattern p = Pattern.compile("c[a-z]*"); // c로 시작하는 소문자 영단어

        for(int i=0 ; i<data.length ; i++) {
        // 2. 정규식으로 비교할 대상을 매개변수로 Pattern클래스의 'Matcher matcher(CharSequence input)'를 호출해서 Matcher인스턴스를 얻는다.
            Matcher m = p.matcher(data[i]);
        // 3. Matcher인스턴스에 boolean matches()를 호출해서 정규식에 부합하는지 확인한다.
            if(m.matches()) {
                System.out.print(data[i] + ", ");
            }
        }
    }
    /*
        - 자주 사용되는 패턴
            c[a-z]*             -> c로 시작하는 영단어              c, ca, co, car, combat, count
            c[a-z]              -> c로 시작하는 두 자리 영단어       ca, co
            c[a-zA-z]           -> c로 시작하는 두 자리 영단어       cA, ca, co
                                   (대소문자 구분 안함)
            c[a-zA-Z0-9]c\w     -> c로 시작하고 숫자와 영어로        cA, ca, co, c0
                                   조합된 두 글자
            .*                  -> 모든 문자열
            c.                  -> c로 시작하는 모든 문자열(기호포함)
            c\.                 -> c.와 일치하는 문자열 '.'은 패턴작성에 사용되는 문자이므로   c.
                                   escape문자인 '\'를 사용해아한다.
            c\d                 -> c와 숫자로 구성된 두 자리 문자열       c0
            c[0-9]              -> c와 숫자로 구성된 두 자리 문자열       c0
            c.*t                -> c로 시작하고 t로 끝나는 모든 문자열    combat, count
            [b|c].*             -> b 또는 c로 시작하는 문자열
            [bc].*              -> b 또는 c로 시작하는 문자열
            [b-c].*             -> b 또는 c로 시작하는 문자열
            [^b|c].*            -> b 또는 c로 시작하지 않는 문자열
            [^bc].*             -> b 또는 c로 시작하지 않는 문자열
            [^b-c].*            -> b 또는 c로 시작하지 않는 문자열
            .*a.*               -> a를 포함하는 모든 문자열 (*: 0 또는 그 이상의 문자)
            .*a.+               -> a를 포함하는 모든 문자열
                                   (+: 1또는 그 이상의 문자. '+'는 '*'과는 달리 반드시 하나 이상의 문자가 있어야 하므로 a로 끝나는 단어는 포함되지 않는다.)
            [b|c].{2}           -> b 또는 c로 시작하는 세 자리 문자열.
    */
    static void test2() {
        String[] data = {
                "bat", "baby", "bonus", "c", "cA", "ca", "co", "c.",
                "c0", "c#", "car", "combat", "count", "date", "disc"
        };
        String[] pattern = {
                ".*", "c[a-z]", "c[a-z]", "c[a-zA-Z]", "c[a-zA-Z0-9]", "c.", "c.*", "c\\.",
                "c\\w", "c\\d", "c.*t", "[b|c].*", ".*a", ".*a.+", "[b|c].{2}"
        };

        for(int x=0 ; x<pattern.length ; x++) {
            Pattern p = Pattern.compile(pattern[x]);
            System.out.print("Pattern : " + pattern[x] + " 결과: ");
            for(int i=0 ; i<data.length ; i++) {
                Matcher m = p.matcher(data[i]);
                if(m.matches()) {
                    System.out.print(data[i] + ", ");
                }
            }
            System.out.println();
        }
    }
    /*
        - 정규식의 일부를 괄호로 나누어 묶어서 그룹화할 수 있다. 그룹화된 부분은 하나의 단위로 묶이는 셈이 되어서 한 번 또는 그 이상의 반복을 의미하는
          '+'나 '*'가 뒤에 오면 그룹화된 부분이 적용대상이 된다. 그리고 그룹화된 부분은 group(int i)를 이용해서 나누어 얻을 수 있다.

    */
    static void test3() {
        String source = "HP:011-1111-1111, HOME:02-999-9999 ";
        String pattern = "(0\\d{1,2})-(\\d{3,4})-(\\d{4})";     // 괄호를 이용해서 정규식을 세 부분으로 나눔.

        Pattern p = Pattern.compile(pattern);
        Matcher m = p.matcher(source);

        int i = 0;
        /*
            - find()는 주어진 소스 내에서 패턴과 일치하는 부분을 찾아내면 true를 반환하고 찾지 못하면 false를 반환한다.
              find()를 호출해서 패턴과 일치하는 부분을 찾아낸 다음, 다시 find()를 호출하면 이전에 발견한 패턴과 일치하는
              부분의 다음부터 다시 패턴매칭을 시작한다.
        */
        while(m.find()) {
            // group() 또는 group(0)은 그룹으로 매칭된 문자열 전체를 나누어지지 않은 채로 반환한다.
            System.out.println(++i + " : " + m.group() + " -> " + m.group(1) + ", " + m.group(2) + ", " + m.group(3));
        }
        /*
            0\\d{1,2}   -> 0으로 시작하는 최소 2자리 최대 3자리 숫자(0포함)
            \\d{3,4}    -> 최소 3자리 최대 4자리의 숫자
            \\d{4}      -> 4자리의 숫자
        */
        /*
            - 결과
                1 : 011-1111-1111 -> 011, 1111, 1111
                2 : 02-999-9999 -> 02, 999, 9999
        */
    }
}
public class Util {
    public static void main(String[] args) {

        RegularExpression.test3();

    }
}
