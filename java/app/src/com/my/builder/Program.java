package com.my.builder;

public class Program {

	public static void main(String[] args) {

		CreateEmployeeParams params = new CreateEmployeeParams();
		params.firstName = "Robert";
		params.lastName = "Lee";
		params.id = 1;
		params.age = 31;
		params.yearStarted = 2020;
		
		Employee robert = new Employee(params);
		
		System.out.println(robert);
	}

}
