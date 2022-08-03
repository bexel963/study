// 화분은 일정량의 물을 매일 뿌려만 주면 평생 살 수 있음
// 하루라도 필요한 물을 못 받으면 죽음
// 그 뒤 아무리 물을 뿌려도 안 살아남
public class FlowerPot {

	private Boolean alive;
	private int minDailyWaterInMl;
	private int dailyWaterReceived;
	
	public FlowerPot() {
		this(5);
	}
	public FlowerPot(int amount) { 
		
		alive = true;
		minDailyWaterInMl = amount;
		dailyWaterReceived = 0;
	}
	public Boolean isAlive() {
		
		return alive;
	}
	public int getMinDailyWaterInMl() {
		return minDailyWaterInMl;
	}
//	public void addWater(WaterSpray spray) {
//		SprayHead head = spray.getHead();
//		SprayBottle body = spray.getBody();
//		
//		int water = body.getRemainingWater();
//		head.sprayFrom(body);
//		water -= body.getRemainingWater();
//		
//		dailyWaterReceived += water;
//	}
	public void addWater(WaterSpray spray) {
		int water = spray.getRemainingWater();
		spray.spray();
		water -= spray.getRemainingWater();
		
		dailyWaterReceived += water;
	}
	public void liveAnotherDay() {
		if(dailyWaterReceived < minDailyWaterInMl) {
			alive = false;
		}
		dailyWaterReceived = 0;
	}
	@Override
	public String toString() {
		return "FlowerPot [alive=" + alive + ", minDailyWaterInMl=" + minDailyWaterInMl + "]";
	}
	
	
}
