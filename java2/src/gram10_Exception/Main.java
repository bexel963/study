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

import java.io.*;
import java.util.Arrays;

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
        : try블럭에서 예외가 발생하면, 예외가 발생한 위치 이후에 있는 try블럭의 문장들은 수행되지 않으므로 try블럭에 포함시킬 코드의 범위를 잘 선택해야한다.
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

/*
    - 예외 발생과 catch블럭
        : 괄호()내에는 처리하고자 하는 예외와 같은 타입의 참조변수 하나를 선언해야한다.
          예외가 발생하면, 발생한 예외에 해당하는 클래스의 인스턴스가 만들어진다.
        : 첫 번째 catch블럭부터 차례로 내려가면서 catch블럭의 괄호()내에 선언된 참조변수의 종류와 생성된 예외클래스의 인스턴스에
          instanceof연산자를 이용해서 검사하게 되는데, 검사 결과가 true인 catch블럭을 만날 때까지 검사는 계속된다.
*/
/*
    - printStackTrace()와 getMessage()
        : 예외가 발생했을 때 생성되는 예외 클래스의 인스턴스에는 발생한 예외에 대한 정보가 담겨 있으며, getMessage()와 printStackTrace()를
          통해서 이 정보들을 얻을 수 있다.
          catch블럭의 괄호()에 선언된 참조변수를 통해 이 인스턴스에 접근할 수 있다. 이 참조변수는 선언된 catch블럭 내에서만 사용 가능하다.
          1) printStackTrace()
            : 예외 발생 당시의 호출스택에 있었던 메서드의 정보와 예외 메시지를 화면에 출력한다.
          2) getMessage()
            : 발생한 예외클래스의 인스턴스에 저장된 메시지를 얻을 수 있다.
*/
class ExceptionEx3 {
    void test() {
        System.out.println(1);
        System.out.println(2);
        try {
            System.out.println(3);
            System.out.println(0/0);
            System.out.println(4);
        } catch (ArithmeticException ae) {
            if(ae instanceof ArithmeticException) {
                System.out.println("true");
                System.out.println("ArithmeticException");
            }
        } catch (Exception e) {
            System.out.println("Exception");
        }
        System.out.println(6);
    }
    // test()의 결과는 예외가 발생해서 비정상적으로 종료되었을 때의 결과와 비슷하지만 예외는 try-catch문에 의해 처리되었으며
    // 프로그램은 정상적으로 종료되었다.
    void test2() {
        System.out.println(1);
        System.out.println(2);
        try {
            System.out.println(3);
            System.out.println(0/0);
            System.out.println(4);
        } catch (ArithmeticException ae) {
            // try-catch문으로 예외처리를 하여 예외가 발생해도 비정상적으로 종료하지 않도록 해주는 동시에,
            // printStackTrace() 또는 getMessage()와 같은 메서드를 통해서 예외의 발생원인을 알 수 있다.
            ae.printStackTrace();
            System.out.println("예외메시지: " + ae.getMessage());
        }
        System.out.println(6);
    }
}
/*
    - 멀티 catch블럭
        : JDK1.7부터 여러 catch블럭을 '|'기호를 이용해서, 하나의 catch블럭으로 합칠 수 있게 되었다.
          '|'기호로 연결할 수 있는 예외 클래스의 개수에는 제한이 없다.
        : 멀티 catch블럭의 '|'기호로 연결된 예외 클래스가 조상과 자손의 관계에 있다면 컴파일 에러가 발생한다.
          두 예외 클래스가 조상과 자손의 관계에 있다면, 그냥 조상 클래스만 써주는 것과 똑같기 때문이다.
          불필요한 코드는 제거하라는 의미에서 에러가 발생하는 것이다.
        : 멀티 catch는 하나의 catch블럭으로 여러 예외를 처리하는 것이기 때문에, 발생한 예외를 멀티 catch블럭으로
          처리하게 되었을 때, 멀티 catch블럭 내에서는 실제로 어떤 예외가 발생한 것인지 알 수 없다.
          그래서 참조변수 e로 멀티 catch블럭에 '|'기호로 연결된 예외 클래스들의 공통 분모인 조상 예외 클래스에 선언된 멤버만 사용할 수 있다.
            try {
                ...
            } catch (ExceptionA | ExceptionB e) {
                e.printStackTrace();
            }
*/
/*
    - 예외 발생시키기
        : 'throw'를 사용해서 프로그래머가 고의로 예외를 발생시킬 수 있다.
    - Exception클래스 vs RuntimeException클래스
        1) unchecked예외: 컴파일러가 예외처리를 확인하지 않는 RuntimeException클래스들    => 실행 시 에러남.
        2) checked예외: 예외처리를 확인하는 Exception클래스들                          => 컴파일 조차 안 됨.
*/
class ExceptionEx4 {
    void test() {
        try {
            Exception e = new Exception("고의로 발생시켰음.");
            throw e;
        } catch (Exception e) {
            System.out.println("에러메시지: " + e.getMessage());
            e.printStackTrace();
        }
        System.out.println("프로그램이 정상 종료되었음.");
    }
    // 1. Exception클래스들이 발생할 가능성이 있는 문장들에 대해 예외처리를 해주지 않으면 컴파일조차 되지 않는다.
    void test2() throws Exception{
        throw new Exception();
    }
    // 2. RuntimeException클래스와 그 자손에 해당하는 예외는 프로그래머에 의해 실수로 발생하는 것들이기 때문에 예외처리를 강제하지 않는다.
    //    만일 RuntimeException클래스들에 속하는 예외가 발생할 가능성이 있는 코드에도 예외처리를 필수로 해야한다면 참조변수와 배열이 사용되는
    //    모든 곳에 예외처리를 해주어야 할 것이다...
    void test3() {
        throw new RuntimeException();
    }
}

/*
    - 메서드에 예외 선언하기
        : 메서드의 선언부에 예외를 선언함으로써 메서드를 사용하려는 사람이 메서드의 선언부를 보았을 때, 이 메서드를 사용하기 위해서는 어떠한 예외들이
          처리되어져야 하는지 쉽게 알 수 있다.
          자바에서는 메서드를 작성할 때 메서드 내에서 발생할 가능성이 있는 예외를 메서드의 선언부에 명시하여 이 메서드를 사용하는 쪽에서는 이에 대한
          처리를 하도록 강요한다. (RuntimeException클래스와 그의 자손은 예외처리 하지 않아도 된다.)
        : 예외가 발생한 메서드에서 예외를 처리할 수도 있고, 예외가 발생한 메서드를 호출한 'main'메서드에서 처리할 수도 있다.
*/
class ExceptionEx5 {
    void test() throws Exception{
        method1();
    }
    static void method1() throws Exception{
        method2();
    }
    static void method2() throws Exception{
        throw new Exception();
    }
    // 메인메서드 역할.
    void mainRole() throws Exception{
        test();
    }
}
/*
    - ExceptionEx5 결과
        : Exception in thread "main" java.lang.Exception
            at gram10_Exception.ExceptionEx5.method2(Main.java:197)
            at gram10_Exception.ExceptionEx5.method1(Main.java:194)
            at gram10_Exception.ExceptionEx5.test(Main.java:191)
            at gram10_Exception.Main.main(Main.java:203)
*/

class ExceptionEx6 {
    // File클래스의 createNewFile()은 예외가 선언된 메서드 이므로 finally블럭 내에 또다시 try-catch문으로 처리해야하므로 복잡해진다.
    // 그래서 예제의 기본 흐름을 간단히 하기위해 내부적으로 예외처리를 한 createNewFile(File f)메서드를 만들어서 사용한다.
    static void createNewFile(File f) {
        try {
            f.createNewFile();
        } catch (Exception e) { }
    }
    static File createFile(String fileName) {
        try {
            if (fileName == null || fileName.equals("")) {
                throw new Exception("파일이름이 유효하지 않습니다.");
            }
        } catch (Exception e) {
            fileName = "제목없음.txt";
            System.out.println(e.getMessage());
        } finally {
            File f = new File(fileName);
            createNewFile(f);
            return f;
        }
    }
    // 메인메서드 역할
    static void mainRole() {
        String fileName = "";
        File f = createFile(fileName);
        System.out.println(f.getName() + " 파일이 성공적으로 생성되었습니다.");
    }
}

/*
    - 예외가 발생한 메서드 내에서 자체적으로 처리해도 되는 것은 메서드 내에서 try-catch문을 사용해서 처리하고,
      메서드 내에서 자체적으로 해결이 안 되는 경우에는 예외를 메서드에 선언해서, 호출한 메서드에서 처리하게 해야한다.
      (ex. 호출한 메서드로부터 호출 시 넘겨받아야 할 값을 다시 받아야 하는 경우..)
*/
class ExceptionEx7 {
    static File createFile(String fileName) throws Exception{
        if (fileName == null || fileName.equals("")) {
            throw new Exception("파일이름이 유효하지 않습니다.");
        }
        File f = new File(fileName);
        f.createNewFile();
        return f;
    }
    // 메인메서드 역할
    static void mainRole() {
        String fileName = "";
        try {
            File f = createFile(fileName);
            System.out.println(f.getName() + " 파일이 성공적으로 생성되었습니다.");
        } catch (Exception e) {
            System.out.println(e.getMessage() + "\n다시 입력해 주세요.");
        }
    }
}

/*
    - finally블럭
        : 예외의 발생여부에 상관없이 실행되어야할 코드를 포함시킬 목적으로 사용된다.
        : try블럭에서 return문이 실행되는 경우에도 finally블럭의 문장들이 먼저 실행된 후에, 현재 실행 중인 메서드를 종료한다.
        : catch블럭의 문장 수행 중에 return문을 만나도 finally블럭의 문장들은 수행된다.
*/
class ExceptionEx8 {
    static void startInstall() { }
    static void copyFiles() { }
    static void deleteTempFiles() { }
    // 메인메서드 역할
    static void mainRole() {
        try {
            startInstall();
            copyFiles();
        } catch (Exception e) {
            e.printStackTrace();
            //deleteTempFiles();
        } finally {
            deleteTempFiles();
        }
    }
}

/*
    - 자동 자원 반환 (try-with-resource) JDK1.7~
        : 주로 입출력에 사용되는 클래스 중에서는 사용한 후에 꼭 닫아 줘야 하는 것들이 있다.
          그래야 사용했던 자원이 반환되기 때문이다.
*/
class ExceptionEx9 {
    void test1() {
        DataInputStream dis = null;
        try {
            FileInputStream fis = new FileInputStream("score.dat");
            dis = new DataInputStream(fis);
        } catch (IOException ie) {
            ie.printStackTrace();
        } finally {
            //dis.close();    // 작업 중에 예외가 발생하더라도, dis가 닫히도록 finally블럭에 넣었지만 close()가 예외를 발생시킬 수 있다.
                              // 그래서 finally블럭 안에 try-catch문을 추가해서 close()를 처리했는데 별로 보기에 좋지 않다.
                              // 더 나쁜 것은 try블럭과 finally블럭에서 모두 예외가 발생하면 try블럭의 예외는 무시된다는 것이다.
                              // 이런 점을 개선하기 위해 try-with-resources문이 추가된 것이다.
            try {
                if(dis!=null) {
                    dis.close();
                }
            } catch (IOException ie) {
                ie.printStackTrace();
            }
        }
    }
    /*
        - test2()
            : test1()를 try-with-resources문으로 바꿈.
            : try-with-resources문의 괄호()안에 객체를 생성하는 문장을 넣으면, 이 객체는 따로 close()를 호출하지 않아도
              try블럭을 벗어나는 순간 자동적으로 close()가 호출된다. 그 다음에 catch블럭 또는 finally블럭이 수행된다.
              try블럭의 괄호()안에 변수를 선언하는 것도 가능하며, 선언된 변수는 try블럭 내에서만 사용할 수 있다.
            : 이처럼 try-with-resources문에 의해 자동으로 객체의 close()가 호출될 수 있으려면, 그 클래스가 AutoCloseable이라는
              인터페이스를 구현한 것이어야만 한다.

                public interface AutoCloseable {
                    void close() throws Exception;
                }
    */
    void test2() {
        int score = 0;
        int sum = 0;
        // 괄호() 안에 두 문장 이상 넣을 경우 ';'로 구분한다.
        try (FileInputStream fis = new FileInputStream("score.dat") ;
             DataInputStream dis = new DataInputStream(fis)) {
            while(true) {
                score = dis.readInt();
                System.out.println(score);
                sum += score;
            }
        } catch (EOFException e) {
            System.out.println("점수의 총 합은 " + sum + "입니다.");
        } catch (IOException ie) {
            ie.printStackTrace();
        }
    }
    /*
        - 자동 호출된 close()에서 예외가 발생하면?
    */
    void test3() {
        try (CloseableResource cr = new CloseableResource()) {
            cr.exceptionWork(false);    // 예외 발생 X
        } catch (WorkException e) {
            e.printStackTrace();
        } catch (CloseException e) {
            e.printStackTrace();
        }

        System.out.println();

        try (CloseableResource cr = new CloseableResource()) {
            cr.exceptionWork(true);     // 예외 발생
        } catch (WorkException e) {
            e.printStackTrace();
        } catch (CloseException e) {
            e.printStackTrace();
        }
    }
    class CloseableResource implements AutoCloseable {
        public void exceptionWork(boolean exception) throws WorkException {
            System.out.println("exceptionWork(" + exception + ")가 호출됨.");
            if(exception)
                throw new WorkException("WorkException발생!!");
        }
        public void close() throws CloseException {
            System.out.println("close()가 호출됨.");
            throw new CloseException("CloseException발생!!!");
        }
    }
    class WorkException extends Exception {
        WorkException(String msg) { super(msg); }
    }
    class CloseException extends Exception {
        CloseException(String msg) { super(msg); }
    }
    /*
        - 실행 결과
            gram10_Exception.ExceptionEx9$CloseException: CloseException발생!!!
                at gram10_Exception.ExceptionEx9$CloseableResource.close(Main.java:382)
                at gram10_Exception.ExceptionEx9.test3(Main.java:358)
                at gram10_Exception.Main.main(Main.java:395)
            gram10_Exception.ExceptionEx9$WorkException: WorkException발생!!
                at gram10_Exception.ExceptionEx9$CloseableResource.exceptionWork(Main.java:378)
                at gram10_Exception.ExceptionEx9.test3(Main.java:367)
                at gram10_Exception.Main.main(Main.java:395)
                Suppressed: gram10_Exception.ExceptionEx9$CloseException: CloseException발생!!!
                    at gram10_Exception.ExceptionEx9$CloseableResource.close(Main.java:382)
                    at gram10_Exception.ExceptionEx9.test3(Main.java:366)
                    ... 1 more

        - 먼저 exceptionWork()에서 발생한 예외에 대한 내용이 출력되고, close()에서 발생한 예외는 '억제된(suppressed)'이라는 의미의
          머리말과 함께 출력된다.
          두 예외가 동시에 발생할 수는 없기 때문에, 실제 발생한 예외를 WorkException으로 하고, CloseException은 억제된 예외로 다룬다.
          억제된 예외에 대한 정보는 실제로 발생한 예외인 WorkException에 저장된다.
        - Throwable에는 억제된 예외와 관련된 메서드가 정의되어있다.
             1) void addSuppressed(Throwable exception)
             2) Throwable[] getSuppressed()
        - 만일 기존의 try-catch문을 사용했다면, 먼저 발생한 WorkException은 무시되고, 마지막으로 발생한 CloseException에 대한 내용만
          출력되었을 것이다.
    */

}
public class Main {
    public static void main(String[] args) throws Exception {
        ExceptionEx9 ex2 = new ExceptionEx9();
        ex2.test3();
    }
}
