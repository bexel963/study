package com.my.clock;

public class Clock {
	
	// 부모와 자식 클래스 모두 사용하는 상수는 부모 클래스에 정의해 놓는다.
//	protected static final int HALF_DAY_IN_SECONDS = 60 * 60 * 12;
	protected static final int DAY_IN_SECONDS = 60 * 60 * 24;	// (1)디지털 시계를 추가하면서 24시간 체제로 변경
	protected int seconds = 60000;
	
	/*
	  	! 현재 설계는 아날로그와 디지털 모두 시간을 12시간 체제로 프린트 한다.
	  	  이 때 디지털만 24시간 체제로 출력하고자 하면 ???
	  	  방법1) 부모의 getter() 자식에 각각 옮겨서 자식에 맞게 구현한ㄷ.
	  	  		-> 더 이상 부모형 참조변수로 자식의 getter()를 호출할 수 없음.
	  	  방법2) 부모의 getter()를 유지한 채 디지털 전용 getter()를 따로 만들어 준다.
	  	  방법3) 다형성을 이용한다. 
	*/
	public byte getHours() {
		int hours = this.seconds / 60 / 60;
		hours = hours % 12;		// (1)24시간 체제로 변경했으니 1~24 까지 들어오는데 hour를 반환할 때는 12시간 체제로 반환 하기로 한다.
		return hours == 0 ? 12 : (byte) hours;
	}
	public byte getMinutes() {
		return (byte)(this.seconds / 60 % 60);
	}
	public byte getSeconds() {
		return (byte)(this.seconds % 60);
	}
	
	public void tick() {
		
		this.seconds = (this.seconds + 1) % DAY_IN_SECONDS;	// (1)24시간 체제로 변경
	}
	public void mount() {
		System.out.println("벽에 시계를 검");
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
