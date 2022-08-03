// < 다른 클래스에서 다른 클래스의 내부 클래스에 접근 >

class Outer {
	class InstanceInner {
		int iv = 100;
	}
	static class StaticInner {
		int iv = 200;
		static int cv = 300;
	}
	void myMethod() {
		class LocalInner {
			int iv = 400;
		}
	}
}
public class Ex34 {

	public static void main(String[] args) {

		Outer oc = new Outer();
		Outer.InstanceInner ii = oc.new InstanceInner();
		
		System.out.println("ii.iv : " + ii.iv);
		System.out.println("Outer.StaticInner.cv : " + Outer.StaticInner.cv);
		
		Outer.StaticInner si = new Outer.StaticInner();
		System.out.println("si.iv : " + si.iv);
	}

}
