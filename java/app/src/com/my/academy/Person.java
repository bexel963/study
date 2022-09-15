package com.my.academy;

public class Person {

	private String firstName;
	private String lastName;
	protected String email;
	
	Person(String firstName, String lastName){
		
		this.firstName = firstName;
		this.lastName = lastName;
		this.email = String.format("%c%s@naver.com", firstName.toLowerCase().charAt(0), lastName.toLowerCase());
	}
	
	public String getFullName() {
		
		return firstName + lastName;
	}
	public void changeName(String firstName, String lastName){
		
		this.firstName = firstName;
		this.lastName = lastName;
	}
	public String getEmail() {
		
		return email;
	}
	
}
