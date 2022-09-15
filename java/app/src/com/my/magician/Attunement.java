package com.my.magician;

import java.time.OffsetDateTime;

public class Attunement {

	protected Magician magician;

	Attunement(final Magician magician){
		this.magician = magician;
	}
	
	// 나머지 메서드들은 그냥 속이 비어 있음. 형 변환 없이 조율 개체에서 이 메서드들을 직접 호출할 거라서 이렇게 해야함.
	public void onEntry() {
		
	}
	public void attack() {
		
	}
	public void useEliteSkill(OffsetDateTime lastEliteAttackUsedDateTime) {
		
	}
	public void onDeath() {
		
	}
	// 이렇게 빈 메서드들을 두는 것은 좋은 습관이 아님. 이 클래스는 추상 클래스가 돼야 맞는대,,,
}
