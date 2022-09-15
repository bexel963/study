package com.my.clock;

public class Program {

	public static void main(String[] args) {

		Clock analog = new AnalogClock();		
		Clock digital = new DigitalClock();
		
		System.out.println(analog);
		System.out.println(digital);
		digital.tick();
		System.out.println(digital);
		
		DigitalClock digitalClock = null;
		if(digital instanceof DigitalClock) {			
			digitalClock = (DigitalClock)digital; 
		}
		digitalClock.setIsBeforeMidday(true);
		System.out.println(digitalClock);
		System.out.println();
		
		digitalClock.setTime((byte)5, (byte)-30, (byte)-30);
		System.out.println(digitalClock);
		digitalClock.setIsBeforeMidday(true);
		System.out.println(digitalClock);
		digitalClock.setIsBeforeMidday(false);
		System.out.println(digitalClock);
		digitalClock.setIsBeforeMidday(false);
		System.out.println(digitalClock);
		digitalClock.setIsBeforeMidday(true);
		System.out.println(digitalClock);
//		digitalClock.setIsBeforeMidday(true);
//		System.out.println(digitalClock);
	}

}
