package com.my.widget;

public final class Button extends Widget implements IClickable{

	Button(int x, int y) {
		super(x, y);
	}
	
	Button(String label, int x, int y){
		super(label, x, y);
	}
	
	@Override
	public void onClick() {
		System.out.printf("Button %s clicked!%s", this.label, System.lineSeparator());
	}
}
