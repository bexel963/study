package com.my.widget;

// 위젯은 GUI의 요소 중 하나로 정보를 보여주거나 사용자가 프로그램과 상호작용할 수 있는 방법을 제공함.
// ex) 아이콘, 버튼, 창, 선택 상자 등..
// 위젯마다 사용자의 행위(ex: 클릭, 드래그)에 반응하는 방법이 다름
public abstract class Widget {

	private static int numWidgets = 0;	// 총 생성한 위젯의 수
	
	protected String label;		// 버튼 위나 창의 꼭대기에 표시되는 텍스트 같은 것
	protected int x;			// 위젯의 위치
	protected int y;
	
	Widget(final int x, final int y){
		this(String.format("Widget%d", numWidgets), x, y);
	}
	Widget(String label, final int x, final int y){
		 this.label = label;
		 this.x = x;
		 this.y = y;
		 numWidgets++;
	}
	public String getLabel() {
		return label;
	}
	public void setLabel(String label) {
		this.label = label;
	}
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}
	
}
