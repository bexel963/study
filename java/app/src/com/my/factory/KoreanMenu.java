package com.my.factory;

public class KoreanMenu extends Menu {

	public Cup createCupOrNull(CupSize size) {
		switch (size) {
			case SMALL:
				return new GlassCup(355);
			case MEDIUM:
				return new GlassCup(473);
			case LARGE:
				return new GlassCup(651);
			default:
				assert(false) : "Unhandled CupSize: " + size;
				return null;
		}
	}

	
}
