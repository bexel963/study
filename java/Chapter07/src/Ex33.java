// < ���� Ŭ������ �ܺ� Ŭ������ ���� ���ټ� >

public class Ex33 {

	private int outerIv = 0;
	static int outerCv = 0;
	
	class InstanceInner {
		int iiv = outerIv;	// �ܺ� Ŭ������ priavate����� ���� ����.
		int iiv2 = outerCv;
	}
	static class StaticInner {
//		int siv = outerIv;	-> �ܺ� Ŭ������ �ν��Ͻ������ ���� x
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