package com.my.bakery;

public class Program {

	public static void main(String[] args) {

		Bakery bakery = new Bakery();
        Bread bread = new Bread();
        
        bakery.addBread(bread);
        
        if (!bread.isFresh()) {
            System.out.println("bad bread");
        }
	}

}
