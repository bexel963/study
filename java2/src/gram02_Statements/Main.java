package gram02_Statements;

import java.util.Scanner;

class Statement {

    Scanner sc = new Scanner(System.in);

    void func1() {
        char grade = ' ';
        char prefix = ' ';

        System.out.print("점수 입력.> ");
        int score = Integer.parseInt(sc.nextLine());
        if(score>=90) {
            grade = 'A';
            if(score>95) {
                prefix = '+';
            } else {
                prefix = '-';
            }
        } else if(score>=80) {
            grade = 'B';
            if(score>85) {
                prefix = '+';
            } else {
                prefix = '-';
            }
        } else if(score>=70) {
            grade = 'C';
            if(score>75) {
                prefix = '+';
            } else {
                prefix = '-';
            }
        } else {
            grade = 'F';
        }

        System.out.println("학점: " + grade + prefix);
    }
    /*
        - switch문
            : switch문의 조건식 '결과'는 정수 or 문자열이어야 한다.
            : case문의 값은 정수 상수만 가능하며, 중복되지 않아야 한다.
            case 999:       // OK
            case '1':       // OK
            case ONE:       // OK
            case "YES":     // OK
            case num;       // ERROR
            case 1.0;       // ERROR
    */
    void func2() {
        System.out.print("현재 월 입력.> ");
        int month = Integer.parseInt(sc.nextLine());
        String season = "";

        switch(month) {
            case 3: case 4: case 5:
                season = "봄";
                break;
            case 6: case 7: case 8:
                season = "여름";
                break;
            case 9: case 10: case 11:
                season = "가을";
                break;
            default:
                season = "겨울";
        }
        System.out.println("현재는 " + season + "입니다.");
    }

    void func3() {
        int com = (int)(Math.random()*3) + 1;
        System.out.print("가위(1), 바위(2), 보(3) 중 하나를 입력하세요.> ");
        int me = Integer.parseInt(sc.nextLine());

        System.out.println("컴퓨터: " + com);
        switch(com - me) {
            case 0:
                System.out.println("비김");
                break;
            case -1: case 2:
                System.out.println("이김");
                break;
            case 1: case -2:
                System.out.println("짐");
                break;
        }
    }

    void func4() {
        System.out.print("주민번호('-'없이 숫자만 입력).> ");
        String regis = sc.nextLine();
        char mark = regis.charAt(6);
        switch(mark) {
            case '1': case '3':
                System.out.println("남자");
                break;
            case '2': case '4':
                System.out.println("여자");
                break;
        }
    }

    /*
        - for문
            : 조건식이 생략된 경우, true로 간주되어 무한 반복문이 된다.
            : 나머지 연산자'%'를 사용하면 특정 범위의 값들이 순환하면서 반복되는 결과를 얻을 수 있다.
            : 나누기 연산자'/'를 사용하면 같은 값이 연속적으로 반복되게 할 수 있다.
            : 블럭 내에 문장이 하나뿐일 대 괄호{}를 생략할 수 있으므로
                for(int i=0 ; i<2_000_000_000 ; i++);
              이렇게도 쓸 수 있다.
    */
    void func5() {
        for(int i=0 ; i<10 ; i++) {
            System.out.println(i%3);
        }
        System.out.println();
        for(int i=0 ; i<10 ; i++) {
            System.out.println(i/3);
        }
    }
    /*
        1 1 1
        1 1 2
        1 1 3
        1 1 4
        1 2 1
        1 2 2
        .....
        4 4 4
    */
    void func6() {
        for(int i=1 ; i<=4 ; i++) {
            for(int j=1 ; j<=4 ; j++) {
                for(int k=1 ; k<=4 ; k++) {
                    System.out.println(i + " " + j + " " + k);
                }
            }
        }
    }

    static int[] selected = new int[4];

    static void rec_func(int k) {
        if(k == 4) {
            for(int i=1 ; i<=3 ; i++) {
                System.out.print(selected[i] + " ");
            }
            System.out.println();
        } else {
            for(int cand=1 ; cand<=4 ; cand++) {
                selected[k] = cand;
                rec_func(k+1);
                selected[k] = 0;
            }
        }
    }
    void func7() {
        rec_func(1);
    }

    void func8() {
        for(int i=1 ; i<=5 ; i++) {
            for(int j=1 ; j<=5 ; j++) {
                if(i==j) {
                    for(int k=1 ; k<i ; k++) {
                        System.out.print("      ");
                    }
                    System.out.print("[" + i + "," + j + "] ");
                }
            }
            System.out.println();
        }
    }

    // 12345 각 자리 수의 합 구하기
    void func9() {
        int num = 12345;
        int sum = 0;

        while(num>0) {
            sum = sum + (num % 10);
            num /= 10;
        }
        System.out.println("합: " + sum);
    }

    void func10() {
        int sum = 0;
        int num = 0;

        System.out.print("합계를 구할 숫자 입력.> (끝내려면 0을 입력)");
        while(true) {
            num = Integer.parseInt(sc.nextLine());
            if(num==0) {
                break;
            }
            sum += num;
        }
        System.out.println("입력한 수의 합: " + sum);
    }
}
public class Main {
    public static void main(String[] args) {

        Statement st = new Statement();

        st.func10();
    }
}
