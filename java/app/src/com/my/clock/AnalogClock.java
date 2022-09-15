package com.my.clock;

public class AnalogClock extends Clock{

	
	
	AnalogClock(){
		
	}
	
	public void tick() {
		addSeconds((short)1);
	}
	public void addSeconds(short seconds) {
		
		int value = this.seconds + seconds;
		while(value<0) {
			value += DAY_IN_SECONDS;	// (1)부모와 마찬가지로 24시간 체제로
		}
		this.seconds = value % DAY_IN_SECONDS;
	}

	public short getSecondHandAngle() {
		return (short) (getSeconds() * 6);
	}
	public short getMinutesHandAngle() {
		return (short) (getMinutes() * 6);
	}
	public short getHourHandAngle() {
		final int ANGLE_PER_HOUR = 360 / 12;
		
		int hours = getHours() % 12;
		return (short)(hours * ANGLE_PER_HOUR + getMinutes() * ANGLE_PER_HOUR / 60);
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
		String angle = String.format("hour: %d, min: %d, sec: %d", getHourHandAngle(), getMinutesHandAngle(), getSecondHandAngle());
		return time + "\n" + angle;
	}
	
}
