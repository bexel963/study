package com.my.practice;

 class A {
	 
}
 
 class B {
    private int count;
    private A a0 = new A();
    private A a1;
    

}
 
 
 class BB extends B {
    private int length;
    private B b = new B();
    
    BB(){
    	System.out.println("BB»ý¼º");
    }
    
}

public class abc {

	public static void main(String[] args) {

		BB bb = new BB();
	}

}
