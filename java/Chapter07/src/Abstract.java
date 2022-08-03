abstract class Player {
	boolean pause;
	int currentPos;
	
	Player() {				// �߻�Ŭ������ �����ڰ� �־���Ѵ�.
		pause = false;
		currentPos = 0;
	}
	
	abstract void play(int pos);
	abstract void stop();
	
	void play() {
		play(currentPos);		// �߻� �޼��带 ����� �� �ִ�.
	}
	void pause() {
		if(pause) {
			pause = false;
			play(currentPos);	// �߻� �޼��带 ����� �� �ִ�.
		} else {
			pause = true;
			stop();				// �߻� �޼��带 ����� �� �ִ�.
		}
	}
}
class CDPlayer extends Player {
	int currentTrack;
	
	void play(int current) {	// ������ �߻�޼ҵ带 ����
		
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
