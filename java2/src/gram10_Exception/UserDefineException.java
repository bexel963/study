package gram10_Exception;

/*
    - 사용자정의 예외
        : 보통 Exception클래스 또는 RuntimeException클래스로부터 상속받아 클래스를 만들지만, 필요에 따라서 알맞은 예외 클래스를 선택할 수 있다.
*/
class MyException extends Exception {

    private final int ERR_CODE;

    MyException(String msg) {
        this(msg, 100);
    }
    MyException(String msg, int errCode) {
        super(msg);
        ERR_CODE = errCode;
    }
    public int getERRCode() {
        return ERR_CODE;
    }
}
/*
    - 기존의 예외 클래스는 주로 Exception을 상속 받아서 'checked예외'로 작성하는 경우가 많았지만, 요즘은 예외처리를 선택적으로 할 수 있도록
      RuntimeException을 상속받아서 작성하는 쪽으로 바뀌어가고 있다.
      'checked예외'는 반드시 예외처리를 해주어야 하기 때문에 예외처리가 불필요한 경우에도 try-catch문을 넣어서 코드가 복잡해지기 때문이다.
*/
class SpaceException extends Exception {
    SpaceException(String msg) {
        super(msg);
    }
}
class MemoryException extends Exception {
    MemoryException(String msg) {
        super(msg);
    }
}
public class UserDefineException {
    public static void main(String[] args) {
        try {
            startInstall();
            copyFiles();
        } catch(SpaceException e) {
            System.out.println("에러 메시지: " + e.getMessage());
            e.printStackTrace();
            System.out.println("공간을 확보한 후에 다시 설치하시기 바랍니다.");
        } catch(MemoryException e) {
            System.out.println("에러 메시지: " + e.getMessage());
            e.printStackTrace();
            System.gc();    // Garbage Collection을 수행하여 메모리를 늘려준다.
            System.out.println("다시 설치를 시도하세요.");
        } finally {
            deleteTempFiles();
        }
    }
    static void startInstall() throws SpaceException, MemoryException {
        if(!enoughSpace()) {
            throw new SpaceException("설치할 공간이 부족합니다.");
        }
        if(!enoughMemory()) {
            throw new MemoryException("메모리가 부족합니다.");
        }
    }
    static boolean enoughSpace() {
        return false;
    }
    static boolean enoughMemory() {
        return true;
    }
    static void copyFiles() { }
    static void deleteTempFiles() { }
}
