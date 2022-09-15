package com.my.magician;

import java.time.OffsetDateTime;

// 기본 조율 자료형
public class None extends Attunement {

	None(Magician magician){
		super(magician);
	}
	
	// 마법사가 원소 조율을 None으로 바꾸는 순간 불평을 할 거임.
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
