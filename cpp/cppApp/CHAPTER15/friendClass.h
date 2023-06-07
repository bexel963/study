/*
	- 프렌드 클래스의 모든 메서드는 오리지널 클래스의 private 멤버와 protected 멤버에 접근할 수 있다.
	  또한 더욱 제한을 가하여 어떤 클래스의 특정 멤버 함수들만 다른 클래스의 프렌드가 되도록 지정할 수 있다.
	  클래스는 함수, 멤버함수, 클래스 중 어떤 것이 프렌드인지 정의한다.
	  프렌드 관계는 바깥 세계에서는 설정할 수 없다.

	- 티비 <-> 리모콘
		: 리모콘은 티비의 상태를 변경할 수 있다. 이것이 Remote클래스를 Tv클래스의 프렌드로 만들어야 한다는 것을 암시한다.

	- 프렌드 선언은 public, private, protected 부분 어디에나 둘 수 있다. (위치에 따른 차이는 없음)

	- 컴파일러는 Remote클래스를 처리하기 전에 Tv 클래스에 대해 알아야 한다.
		1) Tv 클래스를 먼저 정의
		2) 사전 선언
*/

#ifndef TV_H_
#define TV_H_

class Tv
{
private:
	int state;
	int volume;
	int maxChannel;
	int channel;
	int mode;
	int input;
public:
	friend class Remote;	// -> Remote는 Tv의 private 부분에 접근할 수 있다.
	enum { Off, On };
	enum { MinVal, MaxVal=20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125) : state(s), volume(5), maxChannel(mc), channel(2), mode(Cable), input(TV) { }
	void onOff()
	{
		state = (state == On) ? Off : On;
	}
	bool volUp();
	bool volDown();
	void channelUp();
	void channelDown();
	void set_mode()
	{
		mode = (mode == Antenna) ? Cable : Antenna;
	}
	void set_input()
	{
		input = (input == TV) ? DVD : TV;
	}
	void setting() const;	// 설정값 출력....
};

class Remote
{
private:
	int mode;		// TV 조정기 또는 DVD 조정기
public:
	Remote(int m=Tv::TV) : mode(m) { }

	bool volUp(Tv& t) { return t.volUp(); }
	bool volDown(Tv& t) { return t.volDown(); }
	void onOff(Tv& t) { t.onOff(); }
	void channelUp(Tv& t) { t.channelUp(); }
	void channelDown(Tv& t) { t.channelDown(); }
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }

	void set_channel(Tv& t, int c) { t.channel = c; }
};

#endif

/*
	- 클래스 프렌드와 같은 형식이 없다면, Tv 클래스의 private 부분을 public으로 만들거나,
	  티비와 리모콘이 함께 들어 있는 다루기 어렵고 덩치가 더 큰 클래스를 구성해야할 것이다.
	  그리고 그 방법에서는, 하나의 리모콘으로 여러 대의 티비를 제어할 수 있다는 사실을 반영하지 못할 것이다.
*/