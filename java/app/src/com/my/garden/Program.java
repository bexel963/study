package com.my.garden;

public class Program {

	public static void main(String[] args) {
/* 
	1단계
		WaterSpray waterSpray = new WaterSpray();
		waterSpray.fillUp();
		
		FlowerPot pot = new FlowerPot(10);
		
		for(int i=0 ; i<2 ; i++) {		
			pot.addWater(waterSpray);
		}
		pot.liveAnotherDay();
		System.out.println("화분은 살아있나? " + pot.isAlive());
*/

/*
	2단계
		SprayHead head = new SprayHead(5);
		SprayBottle body = new SprayBottle(200);
		body.fillUp();
		
		WaterSpray waterSpray = new WaterSpray(head, body);
		FlowerPot pot = new FlowerPot(10);
		for(int i=0 ; i<2 ; i++) {		
			pot.addWater(waterSpray);
		}
		pot.liveAnotherDay();
		System.out.println("화분은 살아있나? " + pot.isAlive());
*/
// 3단계
		WaterSpray spray = new WaterSpray(SprayHeadSpeed.MEDIUM, BottleSize.MEDIUM);
		spray.getBody().fillUp();
		
		FlowerPot pot = new FlowerPot(10);
		for(int i=0 ; i<2 ; i++) {		
			pot.addWater(spray);
		}
		pot.liveAnotherDay();
		System.out.println("화분은 살아있나? " + pot.isAlive());
		
	}

}
