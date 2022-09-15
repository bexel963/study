package com.my.clock;

public class DigitalClock extends Clock{
	
	// 참이면 오전
	public boolean isBeforeMidday() {
		return (super.seconds / (DAY_IN_SECONDS / 2) == 0);	
	}
	
	public void setIsBeforeMidday(boolean am_pm) {		
		if(am_pm) {
			if(!isBeforeMidday()) {				
				super.seconds -= (DAY_IN_SECONDS / 2);	
			}
		}else {
			if(isBeforeMidday()) {
				super.seconds += (DAY_IN_SECONDS / 2);
			}
		}
	}

	public void setHours(byte hours) {
		int value = hours - 1;
		while(value < 0) {
			value += 12;
		}
		hours = (byte)(value % 12);
		super.seconds += hours * 60 * 60;
	}
	public void setMinutes(byte minutes) {
		
		int wrapCount = 0;
		while(minutes < 0) {
			minutes += 60;
		}
		wrapCount += minutes / 60;
		if(wrapCount != 0) {
			super.seconds += 60 * 60 * wrapCount;
		}
		minutes = (byte)(minutes % 60);
		super.seconds += minutes * 60;
	}
	public void setSeconds(byte seconds) {
		int wrapCount = 0;
		while(seconds <0) {
			seconds += 60;
		}
		wrapCount += seconds / 60;
		if(wrapCount != 0) {
			super.seconds += 60 * wrapCount;
		}
		seconds = (byte)(seconds % 60);
		super.seconds += seconds;
	}
	public void setTime(byte hours, byte minutes, byte seconds) {
		setHours(hours);
		setMinutes(minutes);
		setSeconds(seconds);
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
		String am_pm = isBeforeMidday() ? "AM" : "PM";
		String time = String.format("[%s] %d : %s%d : %s%d", am_pm, getHours(), m_zero, getMinutes(), s_zero, getSeconds());
		return time;
	}
}
