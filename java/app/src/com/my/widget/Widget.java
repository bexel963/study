package com.my.widget;

// ������ GUI�� ��� �� �ϳ��� ������ �����ְų� ����ڰ� ���α׷��� ��ȣ�ۿ��� �� �ִ� ����� ������.
// ex) ������, ��ư, â, ���� ���� ��..
// �������� ������� ����(ex: Ŭ��, �巡��)�� �����ϴ� ����� �ٸ�
public abstract class Widget {

	private static int numWidgets = 0;	// �� ������ ������ ��
	
	protected String label;		// ��ư ���� â�� ����⿡ ǥ�õǴ� �ؽ�Ʈ ���� ��
	protected int x;			// ������ ��ġ
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
