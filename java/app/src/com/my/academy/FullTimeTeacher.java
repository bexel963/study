package com.my.academy;

public class FullTimeTeacher extends Teacher {
	
	private int officeNumber;

	FullTimeTeacher(String firstName, String lastName, Department department) {
		
		super(firstName, lastName, department);
	}

	public int getOfficeNumber() {
		return officeNumber;
	}

	public void setOfficeNumber(int officeNumber) {
		this.officeNumber = officeNumber;
	}
	
	
	
	
}
