class Data {
	int x;
}
public class Ex14 {

	public static void main(String[] args) {
		Data d = new Data();
		d.x = 10;
		
		Data d2 = copy(d);
		System.out.println("d.x = " + d.x);
		System.out.println("d2.x = " + d2.x);
	}

	static Data copy(Data d) {
		Data newd = new Data();
		newd.x = d.x;
		return newd;
	}
}
