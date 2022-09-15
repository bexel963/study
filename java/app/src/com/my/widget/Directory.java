package com.my.widget;

// 클릭, 드래그, 드롭을 모두 할 수 있는 위젯
public final class Directory extends Widget implements IClickable, IDraggable, IDroppable {
	
	Directory(int x, int y){
		super(x, y);
	}
	Directory(String label, int x, int y){
		super(label, x, y);
	}
	@Override
	public void onDrop(Widget widget) {

		System.out.printf("Widget %s was dropped inside of Directory %s%s",
				widget.getLabel(), this.label, System.lineSeparator());
	}
	@Override
	public void onDrag(int x, int y) {
		
		System.out.printf("Drag Card %s from [ %d, %d ] -> [ %d, %d ]!%s",
				this.label, this.x, this.y, x, y, System.lineSeparator());
		this.x = x;
		this.y = y;		
	}
	@Override
	public void onClick() {

		System.out.printf("Button %s clicked!%s", this.label, System.lineSeparator());
	}
	
}
