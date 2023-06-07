/*
	- ��κ��� Remote �޼������ TvŬ������ public �������̽��� ����Ͽ� �����Ǿ���,
	  Tv�� private����� ���� �����ϴ� ������ Remote �޼���� Remote::set_channel() �̴�.
		=> Ŭ���� ��ü�� ������� ����� ���, ���ϴ� �޼���鸸 �ٸ� Ŭ������ ���� ������� ����� ���� �����ϴ�.

			class Tv;				// ���� ����
			class Remote { ... };	// Tv�� ����ϴ� Remote �޼������ ����
			class Tv { ... };		
			.....					// ���⿡ Remote �޼������ ���� ���ǵ��� �ִ´�.
*/

#ifndef TV_H_
#define TV_H_

class Tv;	
/*
	- ���� ����
		: Remote �޼������ Tv ��ü�� ����ϹǷ� Tv���ǰ� Remote ���� �տ� ��Ÿ���� �Ѵ�.
		  �̷��� ��ȯ ������ ���ϴ� �����, ���� ������ ����ϴ� ���̴�.
*/

class Remote
{
private:
	int mode;		// TV ������ �Ǵ� DVD ������
public:
	Remote(int m = Tv::TV) : mode(m) { }

	// ������...
	bool volUp(Tv& t);						
	bool volDown(Tv& t);
	void onOff(Tv& t);
	void channelUp(Tv& t);
	void channelDown(Tv& t);
	void set_mode(Tv& t);
	void set_input(Tv& t);
	void set_channel(Tv& t, int c);
};

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
	friend void Remote::set_channel(Tv& t, int c);
	/*
		- RemoteŬ������ ��� �� �� �޼��� �ϳ��� Tv Ŭ������ ���� ������� �����.
		  �� ������ ó���Ϸ���, �����Ϸ��� Remote ���Ǹ� �̸� �˰� �־�� �Ѵ�.
			=> Remote���ǰ� Tv���� �տ� �;� �Ѵ�.
	*/

	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
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
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void setting() const;	
};

// �ζ��� �Լ��� ����� Remote �޼����
/*
	- Remote�� �޼��� �������� �����ϰ�, ���� ���ǵ��� Tv Ŭ���� �ڿ� �д�.
		=> RemoteŬ������ ������ ������ ��, �����Ϸ��� ���� ������ ���� Tv�� Ŭ������� ����� �˰��ִ�.
		   Remote �޼������ ���� ���ǿ� �����ϴ� ��������, �����Ϸ��� Tv Ŭ���� ������ �̹� �˰� �ְ�,
		   Remote �޼������ �������ϴ� �� �ʿ��� �߰� �����鵵 �˰� �ִ�.
	- �޼��� ���ǿ� inline Ű���带 ��������ν�, �� �޼������ ������ �ζ��� �޼���� ���� �� �ִ�.				   
*/
inline bool Remote::volUp(Tv& t) { return t.volUp(); }
inline bool Remote::volDown(Tv& t) { return t.volDown(); }
inline void Remote::onOff(Tv& t) { t.onOff(); }
inline void Remote::channelUp(Tv& t) { t.channelUp(); }
inline void Remote::channelDown(Tv& t) { t.channelDown(); }
inline void Remote::set_mode(Tv& t) { t.set_mode(); }
inline void Remote::set_input(Tv& t) { t.set_input(); }

inline void Remote::set_channel(Tv& t, int c) { t.channel = c; }

/*
	- �ζ��� �Լ����� ���� ��ũ�� ������. �̰��� �Լ� ���ǰ� �� �Լ��� ����ϴ� ���� �ȿ� ��� �־�� �Ѵٴ� ���� �ǹ��Ѵ�.
	  ���� �ζ��� �Լ��� ���ǵ��� ��� ���Ͽ� �ΰ�, �� ���Ǹ� ����ϴ� ���Ͽ��� ��� ������ ���Խ��� �Լ� ���ǰ� �� �Լ���
	  ����ϴ� ���� �ȿ� ��� �ְ� �Ѵ�.
	  inline Ű���带 �����Ͽ� �� �Լ����� �ܺ� ��ũ�� ���� �Ѵٸ�, �� ���ǵ��� ���� ���Ͽ� ���� ���� �ִ�.
*/

#endif

/*
	- ��ȣ ������ ���� �����

			class Tv
			{
			friend class Remote;
			public:
				void buzz(Remote& r);
				...
			};

			class Remote
			{
			friend class Tv;
			public:
				void bool volUp(Tv& t) { t.volUp(); }
				...
			};

			inline void Tv::buzz(Remote& r)
			{
				...
			}

	- Remote ��ü�� ����ϴ� Tv �޼���� Remote Ŭ���� ���� �տ� ������ �� �� ������,
	  �����Ϸ��� �� �޼��带 �������ϴ� �� ����� ������ ���� �� �ֵ���, Remote Ŭ���� ���� �ڿ� ���Ǹ� �ξ�� �Ѵ�.

	- Remote ������ Tv ���� �ڿ� ������ ������, Tv ��ü�� ����ϴ� Remote::volUp()�� Remote Ŭ���� ���� �ȿ� ������ �� �ִ�.

	- Tv::buzz() �޼��� ���Ǵ� Remote ���� �ڿ� �� �� �ֵ��� �ϱ� ����, Tv ���� �ٱ��� ���ǵǾ�� �Ѵ�.

	- buzz()�� �ζ������� ����� ���� �ʴٸ�, �װ��� ������ ������ �޼��� ���� ���Ͽ� ������ �ʿ䰡 �ִ�.
*/

/*
	- ���� ������
		: �ϳ��� �Լ��� ���� �ٸ� �� Ŭ������ ��� �ִ� private �����Ϳ� �����ؾ� �� ��.
		: � �Լ��� �� Ŭ������ ������ �ٸ� Ŭ������ ���ؼ��� �������� �� �ִ�.
		  �׷��� ���δ� �� Ŭ���� ��ο� ���� ������� ����� ���� �ո����� ��찡 �ִ�.
			ex) �� Ŭ������ ���� �ð踦 �ϳ��� ������ �ְ�, �� �ð踦 ���� ��ġ��ų �� �ְ� �ϰ� ���� ��...

			class Analyzer;		// ���� ���� : ���� ������, �����Ϸ��� Probe Ŭ���� ���� �ȿ� �ִ� ������ ����鿡 �������� �� Analyzer�� Ŭ������� ����� �˰� �� �ش�.
			
			class Probe
			{
				friend void sync(Analyzer& a, const Probe& p);
				friend void sync(Probe& p, const Anlyzer& a);
				...
			};
			
			class Analyzer
			{
				friend void sync(Analyzer& a, const Probe& p);
				friend void sync(Probe& p, const Analyzer& a);
				...
			};

			inline void sync(Analyzer& a, const Probe& p)
			{
				...
			}
			inline sync(Probe& p, const const Analyzer& a)
			{
				...
			}
*/