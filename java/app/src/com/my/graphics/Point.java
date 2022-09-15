package com.my.graphics;

public class Point extends Graphic{

	private int x;
	private int y;
	
	Point(String label, int x, int y) {
		super(label);
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}
	
	public void draw() {
		System.out.printf("Draw point '%s'%s", this.label, System.lineSeparator());
	}
}
