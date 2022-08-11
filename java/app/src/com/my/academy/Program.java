package com.my.academy;

public class Program {

	public static void main(String[] args) {

		Person person = new FullTimeTeacher("Lim", "Jaehyung", Department.ARTS);
	
		System.out.println(person.getEmail());
		System.out.println(person.getFullName());
		
		Class clazz = person.getClass();
		System.out.println(clazz);
		System.out.println(clazz.getName());
		
		Person person2 = new Student("Lim", "JiSun");
		Person person3 = new Teacher("Lim", "Sunmin", Department.MUSIC);
		
		Teacher teacher = null;
		if(person2 instanceof Teacher) {
			teacher = (Teacher)person2;
		}
		try {
			System.out.println(teacher.getClass().getName());			
		}catch(Exception e) {
			System.out.println("null");
		}
		if(person3 instanceof Teacher) {
			teacher = (Teacher)person3;
		}
		System.out.println(teacher.getClass().getName());
	}

}
