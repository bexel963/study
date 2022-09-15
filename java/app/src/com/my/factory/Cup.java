package com.my.factory;

public abstract class Cup {

	private int sizeMl;
	
	protected Cup(int sizeMl) {
		this.sizeMl = sizeMl;
	}
	
	public int getSize() {
		return this.sizeMl;
	}
	
	

	
	// < ���丮 �޼��� >
	// �����ڴ� ������ �Ұ����� ��� ���ܸ� ���� �� �ۿ� ������ ���� �޼��带 ����Ͽ� ��ü�� �����ϸ�,
	// ���� ��쿡 ��Ȳ�� �´� ��ȯ�� �� �� �ִ�.
	// 1. ���⼭ �� ���󸶴� ������ ǥ���� �ٸ��ٴ� ������ �߰�
	//		- �� �޼��忡 ���� �Ű������� �־ �ص� ������ �������� �̿��ϴ°� �� ����
	//		- �� ������ �޴� Ŭ������ ����� �� Ŭ�������� �������� ���� �����ϴ� �޼����� �ñ׳�ó�� ���� �θ� Ŭ������ �߻� Ŭ������ �����.
	// 2. ��ȯ�Ǵ� �ŵ� �������� �����Ͽ� ���� ������ ��ȯ�� �� ����.
	
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
