class MemberCall {
	int iv = 10;
	static int cv = 20;
	
	int iv2 = cv;
//	static int cv2 = iv; -> 에러
	static int cv2 = new MemberCall().iv;
	
	static void staticMethod1() {
		System.out.println(cv);
//		System.out.println(iv); -> 에러
		System.out.println(new MemberCall().iv);
	}
	void instanceMethod1() {
		System.out.println(cv);
		System.out.println(iv);
	}
	static void staticMethod2() {
		staticMethod1();
//		instanceMethod1(); -> 에러
		new MemberCall().instanceMethod1();
	}
	void instanceMethod2() {
		staticMethod1();
		instanceMethod1();
	}
}

