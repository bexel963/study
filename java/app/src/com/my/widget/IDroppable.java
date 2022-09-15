package com.my.widget;

// 다른 위젯을 끌어다 놓을 수 있는 위젯은 이것을 상속
public interface IDroppable {

	void onDrop(Widget widget);
}
