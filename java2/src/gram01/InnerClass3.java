package gram01;

class OuterClass3 {
    private int outerIv = 0;
    static int outerCv = 0;

    class InstanceInner {
        // 외부 클래스의 private멤버에도 접근 가능
        int iiv = outerIv;
        int iiv2 = outerCv;
    }
    static class StaticInner {
//        int siv = outerIv;      // 스태틱 클래스는 외부 클래스의 인스턴스멤버에 접근 x
        static int scv = outerCv;
    }
    void myMethod() {
        int lv = 0;
        final int LV = 0;

        class LocalInner {
            int liv = outerIv;
            int liv2 = outerCv;
            int liv3 = lv;
            int liv4 = LV;
        }
    }
}
public class InnerClass3 {
    public static void main(String[] args) {

    }
}
