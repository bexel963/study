/*
	- ������ Ŭ������ ��� �޼���� �������� Ŭ������ private ����� protected ����� ������ �� �ִ�.
	  ���� ���� ������ ���Ͽ� � Ŭ������ Ư�� ��� �Լ��鸸 �ٸ� Ŭ������ �����尡 �ǵ��� ������ �� �ִ�.
	  Ŭ������ �Լ�, ����Լ�, Ŭ���� �� � ���� ���������� �����Ѵ�.
	  ������ ����� �ٱ� ���迡���� ������ �� ����.

	- Ƽ�� <-> ������
		: �������� Ƽ���� ���¸� ������ �� �ִ�. �̰��� RemoteŬ������ TvŬ������ ������� ������ �Ѵٴ� ���� �Ͻ��Ѵ�.

	- ������ ������ public, private, protected �κ� ��𿡳� �� �� �ִ�. (��ġ�� ���� ���̴� ����)

	- �����Ϸ��� RemoteŬ������ ó���ϱ� ���� Tv Ŭ������ ���� �˾ƾ� �Ѵ�.
		1) Tv Ŭ������ ���� ����
		2) ���� ����
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
	friend class Remote;	// -> Remote�� Tv�� private �κп� ������ �� �ִ�.
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
	void setting() const;	// ������ ���....
};

class Remote
{
private:
	int mode;		// TV ������ �Ǵ� DVD ������
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
	- Ŭ���� ������� ���� ������ ���ٸ�, Tv Ŭ������ private �κ��� public���� ����ų�,
	  Ƽ��� �������� �Բ� ��� �ִ� �ٷ�� ��ư� ��ġ�� �� ū Ŭ������ �����ؾ��� ���̴�.
	  �׸��� �� ���������, �ϳ��� ���������� ���� ���� Ƽ�� ������ �� �ִٴ� ����� �ݿ����� ���� ���̴�.
*/