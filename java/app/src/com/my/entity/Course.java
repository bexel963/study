package com.my.entity;

import java.time.OffsetDateTime;
import java.time.ZoneOffset;
import java.util.ArrayList;
import java.util.UUID;

public class Course extends BaseEntity {

	private String courseCode;
	private String title;
	private ArrayList<CourseTerm> courseTerms;
	
	Course(UUID id, OffsetDateTime createdDateTime, OffsetDateTime modifiedDateTime, String coursecode, String title){
		super(id, createdDateTime, modifiedDateTime);
		this.courseCode = courseCode;
		this.title = title;
		this.courseTerms = new ArrayList<>();
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public ArrayList<CourseTerm> getCourseTerms() {
		return courseTerms;
	}

	public void setCourseTerms(ArrayList<CourseTerm> courseTerms) {
		this.courseTerms = courseTerms;
	}

	public String getCourseCode() {
		return courseCode;
	}
	
	public void addCourseTerm(int term) {
		CourseTerm courseTerm = new CourseTerm(UUID.randomUUID(), OffsetDateTime.now(ZoneOffset.UTC), OffsetDateTime.now(ZoneOffset.UTC), this, term);
		
		this.courseTerms.add(courseTerm);
	}
}













