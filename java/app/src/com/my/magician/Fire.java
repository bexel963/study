package com.my.magician;

import java.time.Duration;
import java.time.OffsetDateTime;
import java.time.ZoneOffset;

public final class Fire extends Attunement {
	
	private final int ELITE_SKILL_COOLDOWN_SECS = 90;
	
	Fire(final Magician magician){
		super(magician);
	}
	
	public void onEntry() {
		System.out.println("I am fire!! Burn everything to the ground!!");
	}
	public void attack() {
		System.out.println("Fire~~~ Balll~~~~~!!!");
	}
	public void useEliteSkill(OffsetDateTime lastEliteAttackUsedDateTime) {
		
		final OffsetDateTime now = OffsetDateTime.now(ZoneOffset.UTC);
		final Duration cooldown = Duration.ofSeconds(ELITE_SKILL_COOLDOWN_SECS);
		final OffsetDateTime cooldownExpiryDateTime = lastEliteAttackUsedDateTime.plus(cooldown);
		// 쿨 다운이 끝나는 시간 계산 하기
		// 0 보다 크다는 것은 현재 시간이 cooldownExpiryDateTime 보다 후라는 뜻
		if(now.compareTo(cooldownExpiryDateTime) > 0) {
			System.out.println("Burn everything to cinders!!");
			System.out.println("Fire~~~ Storm~~~!!!");
		}else {
			System.out.println("I can't use this yet!!");
		}
	}
	public void onDeath() {
		System.out.println("I will rise again like a phoenix...");
	}
}
