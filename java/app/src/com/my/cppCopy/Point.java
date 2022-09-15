package com.my.cppCopy;

public class Point {

	private int x;
	private int y;
	
	Point(final int x, final int y) {
		this.x = x;
		this.y = y;
	}
	
	// 복상 생성자 : Object clon() 처럼 개체를 깊게 복사하는 방법 중 하나. (c++에서는 이 방식을 사용)
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
