package com.my.magician;

import java.time.OffsetDateTime;

// �⺻ ���� �ڷ���
public class None extends Attunement {

	None(Magician magician){
		super(magician);
	}
	
	// �����簡 ���� ������ None���� �ٲٴ� ���� ������ �� ����.
	public void onEntry() {
		System.out.println("No attunement? Seriously? How am I even supposed to fight?");
	}
	public void attack() {
		System.out.println("Punch!!");
	}
	public void useEliteSkill(final OffsetDateTime lastEliteAttackUsedDateTime) {
		System.out.println("What elite attack? You expect me to punch monsters to death?");
	}
	public void onDeath() {
		System.out.println("I'll be back....");
	}
}
