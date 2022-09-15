package com.my.cppCopy;

public class Point {

	private int x;
	private int y;
	
	Point(final int x, final int y) {
		this.x = x;
		this.y = y;
	}
	
	// ���� ������ : Object clon() ó�� ��ü�� ��� �����ϴ� ��� �� �ϳ�. (c++������ �� ����� ���)
	Point(final Point other) {
		this(other.x, other.y);
	}
	
	public int getX() {
		return this.x;
	}
	public int getY() {
		return this.y;
	}

	public void setX(int x) {
		this.x = x;
	}

	public void setY(int y) {
		this.y = y;
	}
}
