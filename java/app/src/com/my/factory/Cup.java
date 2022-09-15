package com.my.factory;

public abstract class Cup {

	private int sizeMl;
	
	protected Cup(int sizeMl) {
		this.sizeMl = sizeMl;
	}
	
	public int getSize() {
		return this.sizeMl;
	}
	
	

	
	// < 팩토리 메서드 >
	// 생성자는 생성이 불가능한 경우 예외를 던질 수 밖에 없지만 정적 메서드를 사용하여 개체를 생성하면,
	// 같은 경우에 상황에 맞는 반환을 할 수 있다.
	// 1. 여기서 각 나라마다 사이즈 표준이 다르다는 내용을 추가
	//		- 이 메서드에 나라를 매개변수로 넣어서 해도 되지만 다형성을 이용하는게 더 좋음
	//		- 각 나라의 메뉴 클래스를 만들고 그 클래스들의 공통요소인 컵을 생성하는 메서드의 시그내처를 가진 부모 클래스를 추상 클래스로 만든다.
	// 2. 반환되는 컵도 다형성을 적용하여 여러 종류를 반환할 수 있음.
	
//	public static Cup createCupOrNull(CupSize size) {
//		switch (size) {
//			case SMALL:
//				return new Cup(355);
//			case MEDIUM:
//				return new Cup(473);
//			case LARGE:
//				return new Cup(651);
//			default:
//				assert(false) : "Unhandled CupSize: " + size;
//				return null;
//		}
//	}
}
