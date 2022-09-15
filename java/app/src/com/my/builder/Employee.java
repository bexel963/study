package com.my.builder;
// 빌더
//	- 개체의 생성 과정을 그 개체의 클래스로부터 분리하는 방법
//	- 개체의 부분부분을 만들어 나가다 준비되면 그제서야 개체를 생성
//	- ex) StringBuilder (다형성이 없는 빌더)
public class Employee {

	private String firstName;
	private String lastName;
	private int id;
	private int yearStarted;
	private int age;
	
	public Employee(CreateEmployeeParams params) {
		this.firstName = params.firstName;
		this.lastName = params.lastName;
		this.id = params.id;
		this.yearStarted = params.yearStarted;
		this.age = params.age;
	}

	@Override
	public String toString() {
		return "Employee [firstName=" + firstName + ", lastName=" + lastName + ", id=" + id + ", yearStarted="
				+ yearStarted + ", age=" + age + "]";
	}
	
	
}
