package com.my.entity;

import java.time.OffsetDateTime;
import java.util.ArrayList;
import java.util.UUID;

public class CourseTerm extends BaseEntity{

	private int term;
	private Course course;
	private ArrayList<Student> students;
	
	CourseTerm(UUID id, OffsetDateTime createdDateTime, OffsetDateTime modifiedDateTime, Course course, int term) {
		super(id, createdDateTime, modifiedDateTime);
		this.course = course;
		this.term = term;
		this.students = new ArrayList<>();
	}

	public ArrayList<Student> getStudent() {
		return students;
	}

	public void setStudent(ArrayList<Student> students) {
		this.students = students;
	}

	public int getTerm() {
		return term;
	}

	public Course getCourse() {
		return course;
	}
	
	public void addStudent(Student student) {
		this.students.add(student);
	}
	public int getStudentCount() {
		return this.students.size();
	}
}
