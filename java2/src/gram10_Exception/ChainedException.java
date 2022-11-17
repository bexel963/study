package gram10_Exception;

/*
    - 연결된 예외
        : 한 예외가 다른 예외를 발생시킬 수도 있다. 예외 A가 예외 B를 발생시켰다면, A를 B의 '원인 예외'라고 한다.
    - initCause()
        : Exception클래스의 조상인 Throwable클래스에 정의되어 있기 때문에 모든 예외에서 사용이 가능하다.
            Throwable initCause(Throwable cause) - 지정한 예외를 원인 예외로 등록
            Throwable getCause()                 - 원인 예외를 반환
        : 발생한 예외를 원인 예외로 등록해서 다시 예외를 발생시키는 이유는 여러가지 예외를 하나의 큰 분류의 예외로 묶어서
          다루기 위해서이다.
          예를들어 InstallException을 SpaceException과 MemoryException의 조상으로 해서 catch블럭으로 작성하면,
          실제로 발생한 예외가 어떤 것인지 알 수 없다는 문제가 생기고, 상속관계를 변경해야 한다는 것도 부담이다.
                try {
                    startInstall();
                    copyFiles();
                } catch (InstallException e) {
                    e.printStackTrace();
                }
          그래서 생각한 것이 예외가 원인 예외를 포함할 수 있게 한 것이다. 이렇게 하면 두 예외는 상속관계가 아니어도 상관없다.
          또 다른 이유는 checked예외를 unchecked예외로 바꿀 수 있도록 하기 위해서다.
*/
class _SpaceException extends Exception {
    _SpaceException(String msg) {
        super(msg);
    }
}
class _MemoryException extends Exception {
    _MemoryException(String msg) {
        super(msg);
    }
}
class InstallException extends Exception {
    InstallException(String msg) {
        super(msg);
    }
}
public class ChainedException {

    static void startInstall() throws _SpaceException, _MemoryException {
        if(!enoughSpace()) {
            throw new _SpaceException("설치할 공간이 부족합니다.");
        }
        if(!enoughMemory()) {
            throw new _MemoryException("메모리가 부족합니다.");
            // throw new RuntimeException(new _MemoryException("메모리가 부족합니다."));
            // - checked예외를 unchecked예외로 바꿀 수 있다.
            //   initCause()대신 RuntimeException의 생성자로도 원인예외를 등록할 수 있다.
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

    public static void main(String[] args) {
        try {
            install();
        } catch (InstallException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    static void install() throws InstallException {
        try {
            startInstall();
            copyFiles();
        } catch (_SpaceException se) {
            InstallException ie = new InstallException("설치 중 예외 발생");
            ie.initCause(se);
            throw ie;
        } catch (_MemoryException me) {
            InstallException ie = new InstallException("설치 중 예외 발생");
            ie.initCause(me);
            throw ie;
        } finally {
            deleteTempFiles();
        }
    }
}
/*
    - 결과
      : gram10_Exception.InstallException: 설치 중 예외 발생
            at gram10_Exception.ChainedException.install(ChainedException.java:71)
            at gram10_Exception.ChainedException.main(ChainedException.java:59)
        Caused by: gram10_Exception._SpaceException: 설치할 공간이 부족합니다.
            at gram10_Exception.ChainedException.startInstall(ChainedException.java:42)
            at gram10_Exception.ChainedException.install(ChainedException.java:68)
            ... 1 more
*/
