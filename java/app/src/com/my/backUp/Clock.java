package com.my.backUp;

public class Clock {

//	private byte hours = 12;
//	private byte minutes;
//	private byte seconds;
	private int seconds;
	
	Clock(){
//		setTime((byte)0, (byte)0, (byte)0);
	}
	public byte getHours() {
		int hours = this.seconds / 60 / 60;
		return hours == 0 ? 12 : (byte) hours;
	}
	public byte getMinutes() {
		return (byte)(this.seconds / 60 % 60);
	}
	public byte getSeconds() {
		return (byte)(this.seconds % 60);
	}
//  < 1. setter >
//	public void setHours(byte hours) {
//		this.hours = (byte)Math.min(12, Math.max(1, hours));
//	}
//	public void setMinutes(byte minutes) {
//		this.minutes = (byte)Math.min(59, Math.max(0, minutes));
//	}
//	public void setSeconds(byte seconds) {
//		this.seconds = (byte)Math.min(59, Math.max(0, seconds));
//	}
	
//  < 2. setter>
//	public void setHours(byte hours) {
//		int value = hours - 1;
//		
//		while(value < 0) {
//			value += 12;
//		}
//		
//		this.hours = (byte)(value % 12 +1);
//	}
//	public void setMinutes(byte minutes) {
//		int wrapCount = 0;
//		
//		while(minutes < 0) {
//			minutes += 60;
//		}
//		wrapCount += minutes / 60;
//		this.minutes = (byte)(minutes % 60);
//		
//		if(wrapCount != 0) {
//			setHours((byte)(this.hours + wrapCount));
//		}
//	}
//	public void setSeconds(byte seconds) {
//		
//		int wrapCount = 0;
//		
//		while(seconds < 0){
//			seconds += 60;
//		}
//		wrapCount += this.seconds / 60;
//		this.seconds = (byte)(seconds % 60);
//		
//		if(wrapCount != 0) {
//			setMinutes((byte)(this.minutes + wrapCount));
//		}
//	}
	
	// 3. setter 대신 초를 시간으로 환산해서 입력하는 메서드를 사용
	// 		- 코드가 복잡함 : 매개변수는 한개인데 바꾸는 멤버 변수는 3개
	//					 : 초가 음수일 때 처리 부분, 시는 1을 뺏다가 더하는 부분(0시를 12시로 표시하기 위해)
	// => 시/분/초를 따로 저장하는 대신 하나의 상태(seconds)로 저장하고, 실제 시/분/초를 알고 싶을 때 마다 저장된 멤버 변수로부터 계산을 해서 얻게한다.
//	public void addSeconds(short seconds) {
//		
//		final int HALF_DAY_IN_SECONDS = 60 * 60 * 12;
//		
//		int value = this.seconds += seconds;
//		while(value < 0) {
//			value += HALF_DAY_IN_SECONDS;
//		}
//		this.seconds = (byte)(value % 60);
//		
//		value = value / 60;
//		value += minutes;
//		
//		this.minutes = (byte)(value % 60);
//		
//		value = value / 60;
//		value += this.hours - 1;
//		this.hours = (byte)(value % 12 + 1);
//	}
	public void addSeconds(short seconds) {
		final int HALF_DAY_IN_SECONDS = 60 * 60 * 12;
		
		int value = this.seconds + seconds;
		while(value<0) {
			value += HALF_DAY_IN_SECONDS;
		}
		this.seconds = value % HALF_DAY_IN_SECONDS;
	}
//	public byte getHours() {
//		return hours;
//	}
//	public byte getMinutes() {
//		return minutes;
//	}
//	
//	public byte getSeconds() {
//		return seconds;
//	}
//	public void setTime(byte hours, byte minutes, byte seconds) {
//		setHours(hours);
//		setMinutes(minutes);
//		setSeconds(seconds);
//	}
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
	public void tick() {
		addSeconds((short)1);
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
		String angle = String.format("hour: %d, min: %d, sec: %d", getHourHandAngle(), getMinutesHandAngle(), getSecondHandAngle());
		return time + "\n" + angle;
	}
	
}
