package gram10_Exception;

/*
    - 예외 되던지기
        : 한 메서드에서 발생할 수 있는 예외가 여럿인 경우, 몇 개는 try-catch문을 통해서 메서드 내에서 자체적으로 처리하고,
          그 나머지는 선언부에 지정하여 호출한 메서드에서 처리하도록 함으로써 양쪽에서 나눠서 처리되도록 할 수 있다.
        : 심지어는 단 하나의 예외에 대해서도 예외가 발생한 메서드와 호출한 메서드, 양쪽에서 처리하도록 할 수 있다.
        : 이 방법은 하나의 예외에 대해서 예외가 발생한 메서드와 이를 호출한 메서드 양쪽 모두에서 처리해줘야 할 작업이 있을 때 사용한다.
*/
public class Exception_rethrowing {
    public static void main(String[] args) {
        try {
            method1();
        } catch (Exception e) {
            System.out.println("main메서드에서 예외가 처리되었습니다.");
        }
    }
    static void method1() throws Exception {
        try {
            throw new Exception();
        } catch (Exception e) {
            System.out.println("method1메서드에서 예외가 처리되었습니다.");
            throw e;
        }
    }

    /*
        - catch블럭에서 예외 되던지기를 해서 호출한 메서드로 예외를 전달하면, return문이 없어도 된다.
          그래서 검증에서도 assert문 대신 AssertError를 생성해서 던진다.
        - finally블럭 내에도 return문을 사용할 수 있으며, try블럭이나 catch블럭의 return문 다음에 수행된다.
          최종적으로 fianlly블럭 내의 return문의 값이 반환된다.
    */
    static int method2_1() {
        try {
            System.out.println("method2()이 호출되었습니다.");
            return 0;
        } catch (Exception e) {
            e.printStackTrace();
            return 1;       // catch블럭 내에도 return문이 필요하다.
        } finally {
            System.out.println("method2()의 finally블럭이 실행되었습니다.");
        }
    }
    static int method2_2() throws Exception{
        try {
            System.out.println("method2()이 호출되었습니다.");
            return 0;
        } catch (Exception e) {
            e.printStackTrace();
            //return 1;
            throw new Exception();  // return문 대신 예외를 호출한 메서드로 전달.
        } finally {
            System.out.println("method2()의 finally블럭이 실행되었습니다.");
        }
    }
}
