package com.my.magician;

import java.time.OffsetDateTime;

public class Attunement {

	protected Magician magician;

	Attunement(final Magician magician){
		this.magician = magician;
	}
	
	// ������ �޼������ �׳� ���� ��� ����. �� ��ȯ ���� ���� ��ü���� �� �޼������ ���� ȣ���� �Ŷ� �̷��� �ؾ���.
	public void onEntry() {
		
	}
	public void attack() {
		
	}
	public void useEliteSkill(OffsetDateTime lastEliteAttackUsedDateTime) {
		
	}
	public void onDeath() {
		
	}
	// �̷��� �� �޼������ �δ� ���� ���� ������ �ƴ�. �� Ŭ������ �߻� Ŭ������ �ž� �´´�,,,
}
