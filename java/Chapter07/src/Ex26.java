// < 인터페이스 활용 >

interface Repairable {}

class Unit {
	int hitPoint;
	final int MAX_HP;
	Unit(int hp) {
		MAX_HP = hp;
	}
}

class GroundUnit extends Unit {

	GroundUnit(int hp) {
		super(hp);
	}
}
class AirUnit extends Unit {
	
	AirUnit(int hp){
		super(hp);
	}
}

class Tank extends GroundUnit implements Repairable {
	Tank() {
		super(150);
		hitPoint = MAX_HP;
	}
	public String toString() {
		return "Tank";
	}
}
class Dropship extends AirUnit implements Repairable {
	Dropship(){
		super(125);
		hitPoint = MAX_HP;
	}
	public String toString() {
		return "Dropship";
	}
}
class Marine extends GroundUnit {
	Marine(){
		super(40);
		hitPoint = MAX_HP;
	}
	public String toString() {
		return "Marine";
	}
}
class SCV extends GroundUnit implements Repairable {
	SCV() {
		super(60);
		hitPoint = MAX_HP;
	}
	public String toString() {
		return "SCV";
	}
	
	void repair(Repairable r) {
		Unit u = (Unit)r;
		while(u.hitPoint != u.MAX_HP) {
			u.hitPoint++;
		}
		System.out.println(u + "의 수리가 끝났습니다.");
	}
}
public class Ex26 {

	public static void main(String[] args) {

		Tank t = new Tank();
		Dropship s = new Dropship();
		Marine m = new Marine();
		
		SCV scv = new SCV();
		
		scv.repair(t);
		scv.repair(s);
//		scv.repair(m);	-> 에러
	}

}
