package com.my.factory;

public class Program {

	public static void main(String[] args) {

		Menu menu = new KoreanMenu();
		Cup cup = menu.createCupOrNull(CupSize.LARGE);
		
		System.out.println(cup.getClass().getName());
		System.out.println(cup.getSize());
		
		System.out.println();
		menu = new AmericanMenu();
		cup = menu.createCupOrNull(CupSize.LARGE);
		
		System.out.println(cup.getClass().getName());
		System.out.println(cup.getSize());
	}

}
