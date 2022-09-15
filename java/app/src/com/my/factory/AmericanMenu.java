package com.my.factory;

public class AmericanMenu extends Menu {

	public Cup createCupOrNull(CupSize size) {
		
		Lid lid = new Lid();
		
		switch (size) {
			case SMALL:
				return new PaperCup(473, lid);
			case MEDIUM:
				return new PaperCup(621, lid);
			case LARGE:
				return new PaperCup(887, lid);
			default:
				assert(false) : "Unhandled CupSize: " + size;
				return null;
		}
	}

	
}
