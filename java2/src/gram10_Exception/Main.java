package gram10_Exception;

/*
    - 프로그램 오류
        : 컴파일 에러, 런타임 에러, 논리적 에러
    - 런타임 에러
        : 런타임 에러를 방지하기 위해서는 프로그램의 실행도중 발생할 수 있는 모든 경우의 수를 고려하여 이에 대한 대비를 하는 것이 필요하다.
          자바에서는 실행 시 발생할 수 있는 프로그램 오류를 에러와 예외, 두 가지로 구분한다.
          1) 에러: 일단 발생하면 복구할 수 없는 심각한 오류
                ex) OutOfMemoryError, StackOverflowError
          2) 예외: 발생하더라도 프로그래머가 이에 대한 적절한 코드를 미리 작성해 놓음으로써 프로그램의 비정상적인 종료를 막을 수 있다.

    - 예외 클래스의 계층 구조
        Object  - Throwable - Exception     -   IOException
                                            -   ClassNotFoundException
                                            -   FileNotFoundException
                                            -   DataFormatException
                                            -   .....
                                            -   RuntimeException    -   ArithmeticException
                                                                    -   ClassCastException
                                                                    -   NullPointException
                                                                    -   .....
                                                                    -   IndexOutOfboundsException

                            - Error         -   OutOfMemoryError
                                            -   StackOverflowError

        ==> Exception클래스들: 사용자의 실수와 같은 외적인 요인에 의해 발생하는 예외
        ==> RuntimeException클래스들: 프로그래머의 실수로 발생하는 예외
*/

/*
    - 예외 처리하기
        : 프로그램의 실행도중에 발생하는 에러는 어쩔 수 없지만, 예외는 프로그래머가 이에 대한 처리를 미리 해주어야 한다.
        : 프로그램 실행 시 발생할 수 있는 예기치 못한 예외의 발생에 대비한 코드를 작성하는 것이며, 예외처리의 목적은 예외의 발생으로 인한
          실행 중인 프로그램의 갑작스런 비정상 종료를 막고, 정상적인 실행 상태를 유지할 수 있도록 하는 것이다.
        : 발생한 예외를 처리하지 못하면, 프로그램은 비정상적으로 종료되며, 처리되지 못한 예외는 JVM의 "예외처리기"가 받아서 예외의 원인을 화면에 출력한다.
    - try-catch문
        : 하나 이상의 catch블럭이 올 수 있으며, 이 중 발생한 예외의 종류와 일치하는 단 한 개의 catch블럭만 수행된다.
          발생한 예외의 종류와 일치하는 catch블럭이 없으면 예외는 처리되지 않는다.
        : if문과 달리 try블럭이나 catch블럭 내에 포함된 문장이 하나뿐이어도 괄호 {} 를 생략할 수 없다.
        : 하나의 메서드 내에 여러 개의 try-catch문이 사용될 수 있으며, try블럭 또는 catch블럭에 또 다른 try-catch문이 포함될 수 있다.
          catch블럭 내의 코드에서도 예외가 발생할 수 있기 때문이다.
        : catch블럭의 괄호 내에 선언된 변수는 catch블럭 내에서만 유효하기 때문에, 모든 catch블럭에 참조변수 'e'하나 만을 사용해도 된다.
          그러나 catch블럭 내에 또 하나의 try-catch문이 포함된 경우, 같은 이름의 참조변수를 사용해서는 안 된다.
          각 catch블럭에 선언된 두 참조변수의 영역이 서로 겹치므로 다른 이름을 사용해야만 서로 구별되기 때문이다.
*/
class ExceptionEx1 {
    void test() {
        try {
            try {

            } catch (Exception e) {

            }
        } catch (Exception e) {
            try {

            } catch (Exception a) {     // 위의 변수 e와 중복되면 안 된다.

            }
        }
    }
}
class ExceptionEx2 {
    void test() {
        int number = 100;
        int result = 0;
        for(int i=0 ; i<10 ; i++) {
            try {
                result = number / (int)(Math.random()*10);
                System.out.println(result);
            } catch (ArithmeticException e) {
                System.out.println("0");
            }
        }
    }
}
public class Main {
    public static void main(String[] args) {
        ExceptionEx2 ex2 = new ExceptionEx2();
        ex2.test();
    }
}
