package com.my.academy;

public class PartTimeTeacher extends Teacher {

	private int weeklyHours = 0;
	
	PartTimeTeacher(String firstName, String lastName, Department department){
		
		super(firstName, lastName, department);
	}
	PartTimeTeacher(String firstName, String lastName, Department department, int weeklyHours){
		
		super(firstName, lastName, department);
		this.weeklyHours = weeklyHours;
	}
	public int getWeeklyHours() {
		return weeklyHours;
	}
	public void setWeeklyHours(int weeklyHours) {
		this.weeklyHours = weeklyHours;
	}
	
	
}
