import java.util.HashSet;
import java.util.Objects;

class Person {
	String name;
	int age;
	
	Person(String name, int age){
		this.name = name;
		this.age = age;
	}
	public String toString() {
		return name + ":" + age;
	}
}

class Person2 {
	String name;
	int age;
	
	Person2(String name, int age){
		this.name = name;
		this.age = age;
	}
	public String toString() {
		return name + ":" + age;
	}
	public boolean equals(Object obj) {
		if(obj instanceof Person2) {
			Person2 tmp = (Person2)obj;
			return this.name.equals(tmp.name) && this.age==tmp.age; 
		}
		return false;
	}
	public int hashCode() {
		return Objects.hash(name, age);
	}
}

public class Ex23_24_HashSetEquals {

	public static void main(String[] args) {

		HashSet set = new HashSet();
		
		set.add("abc");
		set.add("abc");
		set.add(new Person("David", 10));
		set.add(new Person("David", 10));
		set.add(new Person2("David2", 10));
		set.add(new Person2("David2", 10));
		
		System.out.println(set);
	}

}
