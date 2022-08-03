class Tv {
	String color;
	boolean power;
	int channel;
	
	void power() {
		power = !power;
	}
	void channelUp() {
		++channel;
	}
	void channelDown() {
		--channel;
	}
}

class Card {
	String kind;
	int number;
	static int width = 100;
	static int height = 250;
}