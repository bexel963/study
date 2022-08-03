class Unit0 {
	int currentHP;
	int x, y;
}

interface Movable {
	public abstract void move(int x, int y);
}

interface Attackable {
	public abstract void attack(Unit0 u);
}

interface Fightable extends Movable, Attackable {
	
}

class Fighter extends Unit0 implements Fightable {
	public void move(int x, int y) {
		
	}
	public void attack(Unit0 u) {
		
	}
}

public class Ex24_interface {

	public static void main(String[] args) {
		
		Fighter f = new Fighter();
		
		if(f instanceof Unit0) 
			System.out.println("f�� UnitŬ������ �ڼ� �Դϴ�.");
		if(f instanceof Fightable)
			System.out.println("f�� Fightable�������̽��� �����߽��ϴ�.");
		if(f instanceof Movable)
			System.out.println("f�� Movalbe�������̽��� �����߽��ϴ�.");
		if(f instanceof Attackable)
			System.out.println("f�� Attackable�������̽��� �����߽��ϴ�.");
	}

}
