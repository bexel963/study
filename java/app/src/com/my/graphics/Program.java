package com.my.graphics;

public class Program {

	public static void main(String[] args) {

		Point p1 = new Point("Point1", 2, 7);
		Point p2 = new Point("Point2", 2, 7);
		
		p1.draw();
		p2.draw();
		
		System.out.println("---------------------------------------");
		
		Line l1 = new Line("Line 1", p1, p2);
		
		l1.draw();

		System.out.println("---------------------------------------");
		
		Circle c1 = new Circle("Circle", p1, 5);
		Circle c2 = new Circle("Circle", p2, 10);
		
		c1.draw();
		c2.draw();
		
		System.out.println("---------------------------------------");
		
		Picture pic1 = new Picture("Picture with a line and a circle");
		
		pic1.add(c1);
		pic1.add(l1);
		
		pic1.draw();
		
		System.out.println("---------------------------------------");
		
		Picture pic2 = new Picture("More complicated pic");
		
		pic2.add(pic1);	// 그림은 다른 그림의 일부가 될 수도 있음
		pic2.add(c2);
		
		pic2.draw();
		
		System.out.println("---------------------------------------");
		
		Picture pic3 = new Picture("Even more complicated pic");
		
		pic3.add(pic1);	// 그림은 다른 여러개의 그림으로 이루어질 수도 있음
		pic3.add(pic2);
		
		pic3.draw();
	}

}














