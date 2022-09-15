package com.my.graphics;

public class Graphic {

	protected String label;

	Graphic(String label) {
		this.label = label;
	}
	
	public String getLabel() {
		return label;
	}

	public void setLabel(String label) {
		this.label = label;
	}

	@Override
	public String toString() {
		return "Graphic [label=" + label + "]";
	}
	
	
	
}
