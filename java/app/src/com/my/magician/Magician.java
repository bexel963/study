package com.my.magician;

import java.time.OffsetDateTime;
import java.time.ZoneOffset;

public final class Magician {
	
	private String name;
	// 마법사는 4대 원소(공기, 물, 불, 흙)(조율)을 다룰 수 있다.
	private Attunement attunement;
	// 엘리트 공격을 사용했던 기억. (쿨타임)
	private OffsetDateTime lastEliteAttackUsedDateTime;
	
	Magician(String name){
		this.name = name;
		this.attunement = new None(this);
		// 쿨타임을 서기 1년 1월 1일로 초기화
		this.lastEliteAttackUsedDateTime = OffsetDateTime.of(1, 1, 1, 0, 0, 0, 0, ZoneOffset.UTC);
	}
	// 마법사가 사용하는 원소를 바꿀 때마다 하는 행동 메서드
	public void setAttunement(final Attunement attunement) {
		// 조율이 새로운거 들어올 때만 바꿔준다.
		if(this.attunement.getClass() != attunement.getClass()) {
			this.attunement = attunement;
			// 새로 생겼다는거 알려주는 메서드 - 뭐가 생겼는지 알려줌.
			this.attunement.onEntry();
		}
	}
	// 각 조율마다 공격이 달라지니 현재 조율 개체의 attack() 메서드에 이 동작을 맡김
	public void attack() {
		this.attunement.attack();
	}
	
	public void useEliteSkil() {
		this.attunement.useEliteSkill(this.lastEliteAttackUsedDateTime);
		this.lastEliteAttackUsedDateTime = OffsetDateTime.now(ZoneOffset.UTC);
	}
	
	public void onDeath() {
		// 마법사가 죽을 때 현재 원소 조율에 따라 다른 행동을 함.
		this.attunement.onDeath();
		// 죽으면 쿨타임 초기화
		this.lastEliteAttackUsedDateTime = OffsetDateTime.of(1, 1, 1, 0, 0, 0, 0, ZoneOffset.UTC);
	}
}





















