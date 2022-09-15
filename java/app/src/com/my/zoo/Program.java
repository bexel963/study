package com.my.zoo;


class Animal {
	public void shout() {
		System.out.println("�� �����̴�!!!");
	}
}
// �θ��� �޼��带 �ڽ��� �������̵� �ϰ�, �ڽ��� �� �޼��带 ȣ���ϸ� �ڽ��� �޼��常 ȣ��ȴ�.
class Bird extends Animal {
	public void shout() {
		System.out.println("�߾�");
	}
}

class Dog extends Animal {
	public void shout() {
		System.out.println("�۸�");
	}
}

class Cat extends Animal {
	public void shout() {
		System.out.println("�߿�");
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