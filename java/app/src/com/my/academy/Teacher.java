package com.my.academy;

public class Teacher extends Person {
	
	private Department department;
	
	Teacher(String firstName, String lastName, Department department){
		
		super(firstName, lastName);
		this.department = department;
	}
	
	public Department getDepartment() {
		
		return department;
	}
	public void setDepartment(Department department) {
		
		this.department = department;
	}
	public void setEmail(String email) {
		
		super.email = email;
	}
}
