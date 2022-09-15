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
		// obj와 같다고 무조건 false는 아니다. 다른거도 비교 해봐야 한다.
		// hashCode()를 작성하면 equals 구현할 때 편하다.
		// String 같은 복잡한 데이터들을 일일히 비교 하지 않아도 되고, hashCode()만 비교하면 되기 때문이다.
		if(obj == null || !(obj instanceof Point) || this.hashCode() != obj.hashCode()) {
			return false;
		}
		Point other = (Point) obj;
		
		return this.x == other.x && this.y == other.y;
	}
	
	// Point 개체의 해시값.
	// 해시값이 반드시 고유할 필요는 없음. 목적에 적합할 정도로 분포만 잘 되어 있으면 됨
	// 중요한 것은 똑같은 데이터가 들어오면 거기서 나오는 해시값은 같아야한다는 것임.
	public int hashCode() {
		return this.x *31 + this.y;
	}
}
