package com.my.builder;
// ����
//	- ��ü�� ���� ������ �� ��ü�� Ŭ�����κ��� �и��ϴ� ���
//	- ��ü�� �κкκ��� ����� ������ �غ�Ǹ� �������� ��ü�� ����
//	- ex) StringBuilder (�������� ���� ����)
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
