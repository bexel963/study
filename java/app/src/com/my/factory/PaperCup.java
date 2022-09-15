package com.my.factory;

public final class PaperCup extends Cup{

	private Lid lid;
	
	PaperCup(int sizeMl, Lid lid) {
		super(sizeMl);
		this.lid = lid;
	}
}
