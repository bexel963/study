// < 내부 클래스의 외부 클래스에 대한 접근성 >

public class Ex33 {

	private int outerIv = 0;
	static int outerCv = 0;
	
	class InstanceInner {
		int iiv = outerIv;
		int iiv2 = outerCv;
	}
	static class StaticInner {
//		int siv = outerIv;	-> 외부 클래스의 인스턴스멤버에 접근 x
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
