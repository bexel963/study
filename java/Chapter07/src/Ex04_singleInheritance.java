
class VCR {
	boolean power;
	int counter = 0;
	void power() { power = !power; }
	void play() { }
	void stop() { }
	void rew() { }
	void ff() { }
}

class TVCR extends Tv{		// Tv를 상속 받고 VCR을 포함시켜 다중상속 효과를 낸다.
	VCR vcr = new VCR();
	
	void play() {
		vcr.play();
	}
	void stop() {
		vcr.stop();
	}
	void rew() {
		vcr.rew();
	}
	void ff() {
		vcr.ff();
	}
}