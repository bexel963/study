abstract class Player {
	boolean pause;
	int currentPos;
	
	Player() {				// 추상클래스도 생성자가 있어야한다.
		pause = false;
		currentPos = 0;
	}
	
	abstract void play(int pos);
	abstract void stop();
	
	void play() {
		play(currentPos);		// 추상 메서드를 사용할 수 있다.
	}
	void pause() {
		if(pause) {
			pause = false;
			play(currentPos);	// 추상 메서드를 사용할 수 있다.
		} else {
			pause = true;
			stop();				// 추상 메서드를 사용할 수 있다.
		}
	}
}
class CDPlayer extends Player {
	int currentTrack;
	
	void play(int current) {	// 조상의 추상메소드를 구현
		
	}
	void stop() {
		
	}
	void nextTrack() {
		currentTrack++;
	}
	void preTrack() {
		if(currentTrack > 1) {
			currentTrack--;
		}
	}
}
