package com.my.magician;

import java.time.Duration;
import java.time.OffsetDateTime;
import java.time.ZoneOffset;

public class Water extends Attunement {

	private final int ELITE_SKILL_COOLDOWN_SECS = 9;
	
	Water(final Magician magician){
		super(magician);
	}
	public void onEntry() {
		System.out.println("Water!! The giver of life");
	}
	public void attack() {
		System.out.println("Water gun!!");
	}
	public void useEliteSkill(OffsetDateTime lastEliteAttackUsedDateTime) {
		
		final OffsetDateTime now = OffsetDateTime.now(ZoneOffset.UTC);
		final Duration cooldown = Duration.ofSeconds(ELITE_SKILL_COOLDOWN_SECS);
		final OffsetDateTime cooldownExpiryDateTime = lastEliteAttackUsedDateTime.plus(cooldown);
		// �� �ٿ��� ������ �ð� ��� �ϱ�
		// 0 ���� ũ�ٴ� ���� ���� �ð��� cooldownExpiryDateTime ���� �Ķ�� ��
		if(now.compareTo(cooldownExpiryDateTime) > 0) {
			System.out.println("Alright, let's surf");
			System.out.println("Poseidon's fury! Tsunami~~~!!");
		}else {
			System.out.println("I can't use this yet!!");
		}
	}
	public void onDeath() {
		System.out.println("Help! I can't swim!");
	}
}
