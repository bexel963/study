package com.my.magician;

public class Program {

	public static void main(String[] args) {

		Magician magician = new Magician("Wizard of Oz");
		
		magician.attack();
		magician.useEliteSkil();
		magician.onDeath();
		
		System.out.println("=======================================");
		magician.setAttunement(new Fire(magician));
		
		magician.attack();
		magician.useEliteSkil();
		magician.onDeath();
		
		magician.setAttunement(new Fire(magician));
		
		System.out.println("=======================================");
		magician.setAttunement(new Water(magician));
		
		magician.attack();
		magician.useEliteSkil();
		magician.onDeath();
		
		System.out.println("=======================================");
		magician.setAttunement(new Air(magician));
		
		magician.attack();
		magician.useEliteSkil();
		magician.onDeath();
		
		System.out.println("=======================================");
		magician.setAttunement(new Earth(magician));
		
		magician.attack();
		magician.useEliteSkil();
		magician.onDeath();
		
		System.out.println("=======================================");
		magician.setAttunement(new None(magician));
	}

}
