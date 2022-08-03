
public class SprayHead {

	private int sprayAmount;
	
	public SprayHead() {}
	
	public SprayHead(int sprayAmount) {
		this.sprayAmount = sprayAmount;
	}
	public void sprayFrom(SprayBottle source) {
		source.reduceWater(sprayAmount);
	}
}
