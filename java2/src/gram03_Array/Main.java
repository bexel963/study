package gram03_Array;

import java.util.Arrays;

/*
    - 배열
        : 배열의 길이의 최대값은 int타입의 최대값(약20억) 이다.
        : 자바에서는 JVM이 모든 배열의 길이를 별도로 관리한다.
        : 배열은 한 번 생성하면 길이를 변경할 수 없기 때문에, 이미 생성된 배열의 길이는 변하지 않는다.
        : 따라서 배열이름.length는 상수다. (값을 읽을 수만 있을 뿐 변경할 수 없다.)
        : 배열의 길이를 변경하려면, 더 큰 배열을 새로 생성한 후 기존 배열의 내용을 새로운 배열에 복사한다.
        : 배열은 참조변수를 통해서만 접근할 수 있고, 자신을 가리키는 참조변수가 없는 배열은 사용할 수 없다.
          이렇게 쓸모없게 된 배열은 JVM의 가비지 컬렉터에 의해서 자동적으로 메모리에서 제거된다.
*/
class Array {

    // 배열 생성, 초기화
    void func1() {
        int[] arr0 = new int[5];    // 길이가 5인 배열

        // 괄호 {} 안에 아무 것도 넣지 않으면, 길이가 0인 배열이 생성된다.
        // 참조변수의 기본 값은 null이지만, 배열을 가리키는 참조변수는 null대신 길이가 0인 배열로 초기화 하기도 한다.
        int[] arr1 = new int[0];    // 길이가 0인 배열
        int[] arr2 = new int[]{};   // 길이가 0인 배열
        int[] arr3 = {};            // 길이가 0인 배열

        int[] arr4 = new int[]{ 1, 2, 3, 4 };   // 생성과 초기화를 동시에
        int[] arr5 = { 1, 2, 3, 4 };            // new int[] 생략 가능

        int[] iArr = { 1, 2, 3, 4, 5 };
        char[] cArr = { 'a', 'b', 'c', 'd', 'e' };

        System.out.println(iArr);   // [I@5594a1b5  : I는 1차원 int배열이라는 의미이다.
        // 예외적으로 char 배열은 println()으로 출력하면 각 요소가 구분자 없이 그대로 출력되는데,
        // 이것은 println()이 char배열일 때만 이렇게 동작되도록 작성되었기 때문이다.
        System.out.println(cArr);   // abcde
    }

    // 배열 복사
    void func2() {
        // 1) 단순 복사
        int[] arr = { 1, 2, 3, 4, 5 };
        int[] newArr = new int[arr.length*2];
        int idx = 0;
        for(int i : arr) {
            newArr[idx] = i;
            idx++;
        }
        System.out.println("arr -> " + Arrays.toString(arr));
        System.out.println("newArr -> " + Arrays.toString(newArr));

        // 2) System.arraycopy()를 이용한 복사
        //      : arraycopy()는 지정된 범위의 값들을 한 번에 통째로 복사한다.
        //      : 각 요소들이 연속적으로 저장되어 있다는 배열의 특성 때문에 이렇게 처리하는 것이 가능한 것이다.
        // System.arraycopy(arr, 0, newArr, 0, arr.length);
        //      : 배열 arr의 0번째 부터 arr.length개 만큼을 newArr의 0번째 부터 복사한다.
        char[] abc = { 'A', 'B', 'C', 'D', 'E' };
        char[] num = { '1', '2', '3', '4', '5' };
        char[] result = new char[abc.length + num.length];

        System.arraycopy(abc, 0, result, 0, abc.length);
        System.arraycopy(num, 0, result, abc.length, num.length);
        System.out.println(result);
    }
    // 총점, 평균 구하기
    void ex01() {
        int[] scoreArr = { 100, 88, 100, 48, 93 };
        int sum = 0;
        float avg = 0.0f;

        for(int score : scoreArr) {
            sum += score;
        }
        avg = (float)sum / scoreArr.length;
        System.out.println("총점: " + sum + "\n" + "평균: " + avg);
    }
    // 최대값, 최소값 구하기
    void ex02() {
        int[] numArr = { 79, 88, 91, 33, 100, 55, 95 };
        int min = numArr[0], max = numArr[0];
        for(int i=1 ; i<numArr.length ; i++) {
            if(min > numArr[i]) {
                min = numArr[i];
            }
            if(max < numArr[i]) {
                max = numArr[i];
            }
        }
        System.out.println("최소값: " + min);
        System.out.println("최대값: " + max);
    }
    // 배열 요소 섞기
    void ex03() {
        int[] arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int idx = 0, tmp = 0;
        for(int i=0 ; i<100 ; i++) {
            idx = (int)(Math.random()*9) + 1;
            tmp = arr[0];
            arr[0] = arr[idx];
            arr[idx] = tmp;
        }
        System.out.println(Arrays.toString(arr));
    }
    // 로또 번호 생성
    void ex04() {
        int[] lotto = new int[45];
        int[] winning = new int[6];
        int num = 1;
        int idx = 0;

        for(int i=0 ; i<lotto.length ; i++) {
            lotto[i] = num++;
        }
        for(int i=0 ; i<winning.length ; i++) {
            idx = (int)(Math.random()*45) + 1;
            winning[i] = lotto[idx];
        }

        System.out.println(Arrays.toString(lotto));
        System.out.println(Arrays.toString(winning));
    }
    // 버블 정렬
    void ex05() {
        int[] arr = new int[10];
        for(int i=0 ; i<10 ; i++) {
            arr[i] = (int)(Math.random() * 100) + 1;
        }
        System.out.println(Arrays.toString(arr));
        for(int i=0 ; i<arr.length ; i++) {
            for(int j=0 ; j<arr.length-i-1 ; j++) {
                if(arr[j] > arr[j+1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
        System.out.println(Arrays.toString(arr));
    }
    // 배열에 있는 숫자가 몇개인지 세기
    void ex06() {
        int[] numArr = new int[10];
        int[] count = new int[10];

        for(int i=0 ; i<numArr.length ; i++) {
            numArr[i] = (int)(Math.random()*10);
        }
        for(int num : numArr) {
            count[num]++;
        }
        System.out.println(Arrays.toString(numArr));
        for(int i=0 ; i<10 ; i++) {
            System.out.println(i + "의 개수: " + count[i]);
        }
    }
}
/*
    - String배열
        : 참조형 변수를 간단히 참조변수라고도 하며, 모든 참조형 변수에는 객체가 메모리에 저장된 주소인 4byte의 정수값(0x0 ~ 0xffffffff) 또는 null이 저장된다.
    - char배열과 String클래스
        : 문자열은 '문자를 연이어 늘어놓은 것'을 의미하므로 문자배열인 char배열과 같은 뜻이다.
          C언어에서는 문자열을 char배열로 다루지만, 객체지향언어인 자바에서는 char배열과 그에 관련된 기능들을 함께 묶어서 클래스 String에 정의한다.
          char배열과 String클래스의 중요한 차이점 중 하나는 String객체(문자열)는 읽을 수만 있을 뿐 내용을 변경 할 수 없다는 것이다.
          (변경 가능한 문자열을 다루려면 StringBuffer클래스를 사용하면 된다.)
                Strint str = "Java";
                str = str + "8";        // "Java8" 이라는 새로운 문자열이 str에 저장된다.
*/
class StringArr {
    // 초기화, 생성
    void func1() {
        String[] str1 = new String[3];
        String[] str2 = new String[] { "Kim", "Park", "Yi" };
        String[] str3 = { "Kim", "Park", "Yi" };

        String[] name = new String[4];
        name[0] = new String("Kim");
        name[1] = new String("Lim");
        name[2] = "Park";   // 특별히 String클래스의 인스턴스만 new String()을 생략할 수 있다.
        name[3] = "Son";
    }
    // char배열 <-> String클래스
    void func2() {
        String str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i=0 ; i<str.length() ; i++) {
            char ch = str.charAt(i);
            System.out.println("str.charAt(" + i + "): " + ch);
        }
        // String -> char배열
        char[] chArr = str.toCharArray();
        System.out.println(Arrays.toString(chArr));

        // char배열 -> String
        String newStr = new String(chArr);
        System.out.println(newStr);

        char ch = 65;
        System.out.println(ch);
        System.out.println();
    }
    // 16진수 -> 2진수
    void func3() {

        char[] hexArr = { 'C', 'A', 'F', 'E' };
        String[] binaryArr = {
                "0000", "0001", "0010", "0011",
                "0100", "0101", "0110", "0111",
                "1000", "1001", "1010", "1011",
                "1100", "1101", "1110", "1111"
        };
        String result = "";
        for(char hex : hexArr) {
            if('0' <= hex && hex <= '9') {
                result += binaryArr[hex];
            } else {
                result += binaryArr[hex-'A'+10];
                                // 'C'-'A'+10 = 2 ==> int형 보다 작은 자료형은 연산 전에 int형으로 변환된 후 연산된다.
            }
        }
        System.out.println(result);

        char[] ch = { 65, 66, 'C' };    // A, B, C
        int[] iArr = { 65, 66, 'C' };   // 65, 66, 67
        System.out.println(ch);
        System.out.println(Arrays.toString(iArr));
        System.out.println(('8' > 9));  // true : int형 보다 작은 자료형은 연산 전에 int형으로 변환된 후 연산된다.
        System.out.println((int)'8');   // 56
    }
}
class MultiArr {
    // 초기화, 생성
    void func1() {
        int[][] arr0 = new int[2][2];
        int[][] arr1 = new int[][] { {1,2,3}, {4,5,6}};
        int[][] arr2 = { {1,2,3}, {4,5,6}};
    }
    /*
        - 가변 배열
            : 2차원 이상의 배열을 '배열의 배열'의 형태로 처리한다는 사실을 이용하면 보다 자유로운 형태의 배열을 구성할 수 있다.
              2차원 이상의 다차원 배열을 생성할 때 전체 배열 차수 중 마지막 차수의 길이를 지정하지 않고, 추후에 각기 다른 길이의 배열을
              생성하므로써 고정된 형태가 아닌 보다 유동적인 가변 배열을 구성할 수 있다.
    */
    void func2() {
        int[][] score1 = new int[5][3];  // 고정 배열(5X3)
        int[][] score2 = new int[5][];   // 가변 배열
        score2[0] = new int[5];
        score2[1] = new int[4];
        score2[2] = new int[3];
        score2[3] = new int[2];
        score2[4] = new int[1];
    }

    void ex01() {

    }
    void ex02() {

    }
    void ex03() {

    }
    void ex04() {

    }
}
public class Main {
    public static void main(String[] args) {
        StringArr str = new StringArr();
        str.func3();
    }
}






