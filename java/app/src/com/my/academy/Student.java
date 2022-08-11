package com.my.academy;

public class Student extends Person{

	private Major major;
	
	Student(String firstName, String lastName){
		
		super(firstName, lastName);
	}
	public Major getMajorOrNull() {
		
		return major;
	}
	public void setMajor(Major major) {
		
		this.major = major;
	}
}
