// < 내부 클래스의 제어자 >

public class Ex32 {

	class InstanceInner {}
	static class StaticInner {}
	
	InstanceInner iv = new InstanceInner();
	StaticInner cv = new StaticInner();

	static void staticMethod() {
//		InstanceInner obj1 = new InstanceInner();	-> static멤버는 인스턴스멤버에 직접 접근 x
		StaticInner obj2 = new StaticInner();
		
		Ex32 outer = new Ex32();
		InstanceInner obj1 = outer.new InstanceInner();
	}
	void instanceMethod() {
		InstanceInner obj1 = new InstanceInner();
		StaticInner obj2 = new StaticInner();
//		LocalInner lv = new LocalInner();	-> 인스턴스 메소드에서는 인스턴스멤버, 스태틱멤버 모두 접근 가능 / 지역멤버는 x
	}
	void myMethod() {
		class LocalInner {}
		LocalInner lv = new LocalInner();
	}
}
