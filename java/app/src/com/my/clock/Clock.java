package com.my.clock;

public class Clock {
	
	// �θ�� �ڽ� Ŭ���� ��� ����ϴ� ����� �θ� Ŭ������ ������ ���´�.
//	protected static final int HALF_DAY_IN_SECONDS = 60 * 60 * 12;
	protected static final int DAY_IN_SECONDS = 60 * 60 * 24;	// (1)������ �ð踦 �߰��ϸ鼭 24�ð� ü���� ����
	protected int seconds = 60000;
	
	/*
	  	! ���� ����� �Ƴ��α׿� ������ ��� �ð��� 12�ð� ü���� ����Ʈ �Ѵ�.
	  	  �� �� �����и� 24�ð� ü���� ����ϰ��� �ϸ� ???
	  	  ���1) �θ��� getter() �ڽĿ� ���� �Űܼ� �ڽĿ� �°� �����Ѥ�.
	  	  		-> �� �̻� �θ��� ���������� �ڽ��� getter()�� ȣ���� �� ����.
	  	  ���2) �θ��� getter()�� ������ ä ������ ���� getter()�� ���� ����� �ش�.
	  	  ���3) �������� �̿��Ѵ�. 
	*/
	public byte getHours() {
		int hours = this.seconds / 60 / 60;
		hours = hours % 12;		// (1)24�ð� ü���� ���������� 1~24 ���� �����µ� hour�� ��ȯ�� ���� 12�ð� ü���� ��ȯ �ϱ�� �Ѵ�.
		return hours == 0 ? 12 : (byte) hours;
	}
	public byte getMinutes() {
		return (byte)(this.seconds / 60 % 60);
	}
	public byte getSeconds() {
		return (byte)(this.seconds % 60);
	}
	
	public void tick() {
		
		this.seconds = (this.seconds + 1) % DAY_IN_SECONDS;	// (1)24�ð� ü���� ����
	}
	public void mount() {
		System.out.println("���� �ð踦 ��");
	}
	
	public String toString() {
		String m_zero = "";
		String s_zero = "";
		if(getMinutes() < 10) {
			m_zero = "0";
		}
		if(getSeconds()< 10) {
			s_zero = "0";
		}
		
		String time = String.format("%d : %s%d : %s%d", getHours(), m_zero, getMinutes(), s_zero, getSeconds());
		return time;
	}
}
