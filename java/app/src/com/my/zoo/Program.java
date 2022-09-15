package com.my.zoo;


class Animal {
	public void shout() {
		System.out.println("나 동물이다!!!");
	}
}
// 부모의 메서드를 자식이 오버라이딩 하고, 자식이 그 메서드를 호출하면 자식의 메서드만 호출된다.
class Bird extends Animal {
	public void shout() {
		System.out.println("삐약");
	}
}

class Dog extends Animal {
	public void shout() {
		System.out.println("멍멍");
	}
}

class Cat extends Animal {
	public void shout() {
		System.out.println("야옹");
	}
}

public class Program {

	public static void main(String[] args) {
		
		Animal[] pets = new Animal[3];
		
		pets[0] = new Bird();
		pets[1] = new Dog();
		pets[2] = new Cat();
		
		for(Animal animal : pets) {
			animal.shout();
		}
		System.out.println("=========================");
		Animal animal = new Dog();
		animal.shout();
	}
}