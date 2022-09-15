package com.my.Point;

public class Point {

	private int x;
	private int y;
	
	Point(final int x, final int y){
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}
	
	public boolean equals(Object obj) {
		if(obj == this) {
			return true;
		}
		// obj�� ���ٰ� ������ false�� �ƴϴ�. �ٸ��ŵ� �� �غ��� �Ѵ�.
		// hashCode()�� �ۼ��ϸ� equals ������ �� ���ϴ�.
		// String ���� ������ �����͵��� ������ �� ���� �ʾƵ� �ǰ�, hashCode()�� ���ϸ� �Ǳ� �����̴�.
		if(obj == null || !(obj instanceof Point) || this.hashCode() != obj.hashCode()) {
			return false;
		}
		Point other = (Point) obj;
		
		return this.x == other.x && this.y == other.y;
	}
	
	// Point ��ü�� �ؽð�.
	// �ؽð��� �ݵ�� ������ �ʿ�� ����. ������ ������ ������ ������ �� �Ǿ� ������ ��
	// �߿��� ���� �Ȱ��� �����Ͱ� ������ �ű⼭ ������ �ؽð��� ���ƾ��Ѵٴ� ����.
	public int hashCode() {
		return this.x *31 + this.y;
	}
}
