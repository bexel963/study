/*
	- 대부분의 Remote 메서드들은 Tv클래스의 public 인터페이스를 사용하여 구현되었고,
	  Tv의 private멤버에 직접 접근하는 유일한 Remote 메서드는 Remote::set_channel() 이다.
		=> 클래스 전체를 프렌드로 만드는 대신, 원하는 메서드들만 다른 클래스에 대해 프렌드로 만드는 것이 가능하다.

			class Tv;				// 사전 선언
			class Remote { ... };	// Tv를 사용하는 Remote 메서드들의 원형
			class Tv { ... };		
			.....					// 여기에 Remote 메서드들의 실제 정의들을 넣는다.
*/

#ifndef TV_H_
#define TV_H_

class Tv;	
/*
	- 사전 선언
		: Remote 메서드들이 Tv 객체를 사용하므로 Tv정의가 Remote 정의 앞에 나타나야 한다.
		  이러한 순환 종속을 피하는 방법은, 사전 선언을 사용하는 것이다.
*/

class Remote
{
private:
	int mode;		// TV 조정기 또는 DVD 조정기
public:
	Remote(int m = Tv::TV) : mode(m) { }

	// 원형만...
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
		- Remote클래스의 멤버 중 이 메서드 하나만 Tv 클래스에 대해 프렌드로 만든다.
		  이 구문을 처리하려면, 컴파일러가 Remote 정의를 미리 알고 있어야 한다.
			=> Remote정의가 Tv정의 앞에 와야 한다.
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

// 인라인 함수로 선언된 Remote 메서드들
/*
	- Remote를 메서드 선언으로 제한하고, 실제 정의들은 Tv 클래스 뒤에 둔다.
		=> Remote클래스의 원형을 조사할 때, 컴파일러는 사전 선언을 통해 Tv가 클래스라는 사실을 알고있다.
		   Remote 메서드들의 실제 정의에 도달하는 시점에서, 컴파일러는 Tv 클래스 선언을 이미 알고 있고,
		   Remote 메서드들을 컴파일하는 데 필요한 추가 정보들도 알고 있다.
	- 메서드 정의에 inline 키워드를 사용함으로써, 그 메서드들을 여전히 인라인 메서드로 만들 수 있다.				   
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
	- 인라인 함수들은 내부 링크를 가진다. 이것은 함수 정의가 그 함수를 사용하는 파일 안에 들어 있어야 한다는 것을 의미한다.
	  따라서 인라인 함수의 정의들을 헤더 파일에 두고, 그 정의를 사용하는 파일에서 헤더 파일을 포함시켜 함수 정의가 그 함수를
	  사용하는 파일 안에 들어 있게 한다.
	  inline 키워드를 제거하여 그 함수들이 외부 링크를 갖게 한다면, 그 정의들을 구현 파일에 넣을 수도 있다.
*/

#endif

/*
	- 상호 프렌드 관계 만들기

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

	- Remote 객체를 사용하는 Tv 메서드는 Remote 클래스 선언 앞에 원형을 둘 수 있지만,
	  컴파일러가 그 메서드를 컴파일하는 데 충분한 정보를 가질 수 있도록, Remote 클래스 선언 뒤에 정의를 두어야 한다.

	- Remote 선언이 Tv 선언 뒤에 나오기 때문에, Tv 객체를 사용하는 Remote::volUp()을 Remote 클래스 선언 안에 정의할 수 있다.

	- Tv::buzz() 메서드 정의는 Remote 선언 뒤에 올 수 있도록 하기 위해, Tv 선언 바깥에 정의되어야 한다.

	- buzz()를 인라인으로 만들고 싶지 않다면, 그것을 독립된 별개의 메서드 정의 파일에 정의할 필요가 있다.
*/

/*
	- 공유 프렌드
		: 하나의 함수가 서로 다른 두 클래스에 들어 있는 private 데이터에 접근해야 할 때.
		: 어떤 함수가 한 클래스의 멤버라면 다른 클래스에 대해서는 프렌드일 수 있다.
		  그런데 때로는 두 클래스 모두에 대해 프렌드로 만드는 것이 합리적인 경우가 있다.
			ex) 각 클래스에 내부 시계를 하나씩 가지고 있고, 두 시계를 서로 일치시킬 수 있게 하고 싶을 때...

			class Analyzer;		// 사전 선언 : 사전 선언은, 컴파일러가 Probe 클래스 선언 안에 있는 프렌드 선언들에 도달했을 때 Analyzer가 클래스라는 사실을 알게 해 준다.
			
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