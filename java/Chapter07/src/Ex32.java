// < ���� Ŭ������ ������ >

public class Ex32 {

	class InstanceInner {}
	static class StaticInner {}
	
	InstanceInner iv = new InstanceInner();
	StaticInner cv = new StaticInner();

	static void staticMethod() {
//		InstanceInner obj1 = new InstanceInner();	-> static����� �ν��Ͻ������ ���� ���� x
		StaticInner obj2 = new StaticInner();
		
		Ex32 outer = new Ex32();
		InstanceInner obj1 = outer.new InstanceInner();
	}
	void instanceMethod() {
		InstanceInner obj1 = new InstanceInner();
		StaticInner obj2 = new StaticInner();
//		LocalInner lv = new LocalInner();	-> �ν��Ͻ� �޼ҵ忡���� �ν��Ͻ����, ����ƽ��� ��� ���� ���� / ��������� x
	}
	void myMethod() {
		class LocalInner {}
		LocalInner lv = new LocalInner();
	}
}
