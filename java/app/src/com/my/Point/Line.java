package com.my.Point;

public class Line {

	private Point p1;
	private Point p2;
	
	Line(final Point p1, final Point p2){
		this.p1 = p1;
		this.p2 = p2;
	}
	
	public double getLenght() {
		
		int xDiff = this.p1.getX() - this.p2.getX();
		int yDiff = this.p1.getY() - this.p2.getY();
		
		return Math.sqrt(xDiff * xDiff + yDiff * yDiff);
	}
	
	public boolean equals(Object obj) {
		if(obj == this) {
			return true;
		}
		if(obj == null || !(obj instanceof Line) || this.hashCode() != obj.hashCode()) {
			return false;
		}
		Line other = (Line)obj;
		
		return this.p1.equals(other.p1) && this.p2.equals(other.p2); 
	}
	
	public int hashCode() {
		int hash = 17;
		hash = hash * 31 + this.p1.hashCode();
		hash = hash * 31 + this.p2.hashCode();
		
		return hash;
	}
}
