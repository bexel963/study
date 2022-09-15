package com.my.garden;

public class SprayBottle {

	private int capacity;
	private int remainingWater;
	
	public SprayBottle() { }
	
	public SprayBottle(int capacity) {
		this.capacity = capacity;
	}

	public void fillUp() {
		remainingWater = capacity;
	}
	public int getCapacity() {
		return capacity;
	}
	public int getRemainingWater() {
		return remainingWater;
	}
	public void reduceWater(int milliliter) {
		this.remainingWater -= Math.min(milliliter, this.remainingWater);
	}
}
