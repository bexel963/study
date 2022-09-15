package com.my.magician;

import java.time.OffsetDateTime;
import java.time.ZoneOffset;

public final class Magician {
	
	private String name;
	// ������� 4�� ����(����, ��, ��, ��)(����)�� �ٷ� �� �ִ�.
	private Attunement attunement;
	// ����Ʈ ������ ����ߴ� ���. (��Ÿ��)
	private OffsetDateTime lastEliteAttackUsedDateTime;
	
	Magician(String name){
		this.name = name;
		this.attunement = new None(this);
		// ��Ÿ���� ���� 1�� 1�� 1�Ϸ� �ʱ�ȭ
		this.lastEliteAttackUsedDateTime = OffsetDateTime.of(1, 1, 1, 0, 0, 0, 0, ZoneOffset.UTC);
	}
	// �����簡 ����ϴ� ���Ҹ� �ٲ� ������ �ϴ� �ൿ �޼���
	public void setAttunement(final Attunement attunement) {
		// ������ ���ο�� ���� ���� �ٲ��ش�.
		if(this.attunement.getClass() != attunement.getClass()) {
			this.attunement = attunement;
			// ���� ����ٴ°� �˷��ִ� �޼��� - ���� ������� �˷���.
			this.attunement.onEntry();
		}
	}
	// �� �������� ������ �޶����� ���� ���� ��ü�� attack() �޼��忡 �� ������ �ñ�
	public void attack() {
		this.attunement.attack();
	}
	
	public void useEliteSkil() {
		this.attunement.useEliteSkill(this.lastEliteAttackUsedDateTime);
		this.lastEliteAttackUsedDateTime = OffsetDateTime.now(ZoneOffset.UTC);
	}
	
	public void onDeath() {
		// �����簡 ���� �� ���� ���� ������ ���� �ٸ� �ൿ�� ��.
		this.attunement.onDeath();
		// ������ ��Ÿ�� �ʱ�ȭ
		this.lastEliteAttackUsedDateTime = OffsetDateTime.of(1, 1, 1, 0, 0, 0, 0, ZoneOffset.UTC);
	}
}





















