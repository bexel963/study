package com.my.Point;

import java.util.HashSet;

public class Program {

	public static void main(String[] args) {

		Point p1 = new Point(4, 1);
		Point p2 = p1;
		
		Point p3 = new Point(4, 1);
		Point p4 = new Point(9, 11);
		
		System.out.println(p1 == p2);			// true
		System.out.println(p1.equals(p2));		// true
		
		System.out.println(p1 == p3);			// false
		System.out.println(p1.equals(p3));		// true
		
		Line l1 = new Line(p1, p4);
		Line l2 = new Line(p1, p4);
		
		System.out.println(l1 == l2);			// false
		System.out.println(l1.equals(l2));		// true
		
		Point p5 = new Point(4, 1);
		Point p6 = new Point(9, 11);
		
		Line l3 = new Line(p5, p6);
		
		System.out.println(l1.equals(l3));		// true
		
		// HashSet, HashMap ���� Ű ������ �ؽð��� ����Ѵ�.
		// Point, Line Ŭ������ hashCode()�� �������̵� ���� �ʾƼ� ��ü�� �ּҰ��� ���Ѵ�.
		// ����, Point, Line�� HashSet�� �ùٸ��� �۵��ϰ� ������� hashCode() �޼��嵵 �������̵� �ؾ��Ѵ�.
		HashSet<Point> points = new HashSet<>();
		points.add(p1);
		System.out.println(points.contains(p3));	// false
		
		System.out.println("==========�ؽ� �׽�Ʈ==========");
		HashSet<Point> points2 = new HashSet<>();
		
		Point p7 = new Point(1, 7);
		Point p8 = new Point(1, 7);
		Point p9 = new Point(7, 1);
		
		points2.add(p7);
		
		System.out.println(points2.contains(p8));	// true
		System.out.println(points2.contains(p9));	// true
		
		HashSet<Line> lines = new HashSet<>();
		
		Line l4 = new Line(p7, p9);
		
		Point p10 = new Point(1, 7);
		Point p11 = new Point(7, 1);
		
		Line l5 = new Line(p10, p11);
		
		lines.add(l4);
		
		System.out.println(lines.contains(l5));	// true
		
		Line l6 = new Line(p11, p10);
		System.out.println(lines.contains(l6));

	}

}


















