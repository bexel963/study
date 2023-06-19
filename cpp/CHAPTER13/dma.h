#ifndef DMA_H_
#define DMA_H_
#include <iostream>


/*
	- 상속과 동적 메모리 대입
		: 기초 클래스가 동적 메모리 대입을 사용하고, 대입과 복사 생성자를 다시 정의한다면 그것이 파생 클래스를 구현하는 데 어떠한 영향을 미치는지는
		  파생 클래스의 성질에 달려 있따.
		  파생 클래스 자신이 동적 메모리 대입을 사용하지 않는다면, 어떤 특별한 조치도 필요가 없다.
		  그러나 파생 클래스 자신이 동적 메모리 대입을 사용한다면, 이 때 취할 수 있는 조치는 두 가지가 있다.

	- 경우1) 파생 클래스가 new를 사용하지 않는다.
	  경우2) 파생 클래스가 new를 사용한다.
*/

// DMA를 사용하는 기초 클래스 => 생성자가 new를 사용할 때 요구되는 특별한 메서드들. 즉, 파괴자, 복사생성자, 오버로딩 대입 연산자를 가진다.
class baseDMA
{
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	baseDMA& operator=(const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

// 경우1) DMA를 사용하지 않는 파생 클래스 => 파괴자가 필요 없고, 암시적 복사 생성자, 암시적 대입 연산자를 사용한다.
class lacksDMA : public baseDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};
/*
	- 명시적 파괴자를 정의하지 않으면, 컴파일러는 아무 일도 하지 않는 디폴트 파괴자를 정의한다.
	  파생 클래스를 위한 그 디폴트 파괴자는, 자신의 코드를 수행한 후 기초 클래스의 파괴자를 항상 호출한다.
	  lacksDMA 멤버들은 어떤 특별한 동작도 요구하지 않는다고 가정했기 때문에, 이 경우 디폴트 파괴자만 있으면 충분하다.

	- 디폴트 복사 생성자는 멤버별 복사를 한다. 멤버별 복사는 동적 메모리 대입에는 사용할 수 없다.
	  멤버별 복사는 데이터형에 맞게 정의된 복사 형식을 사용한다. 그래서 long을 long으로 복사하는 것은 일반적인 대입을 통하여 이루어진다.
	  그러나 클래스 멤버 또는 상속받은 클래스 성분을 복사하는 것은, 그 클래스의 복사 생성자를 통하여 이루어진다.
	  lacksDMA 클래스의 디폴트 복사 생성자는, lacksDMA 객체의 baseDMA 성분을 복사하기 위해 명시적인 baseDMA 복사 생성자를 사용한다.
	  그러므로 lacksDMA 클래스의 디폴트 복사 생성자는 새로운 lacksDMA 멤버에 대해 사용할 수 있고, 상속받은 baseDMA 객체에 대해서도 사용할 수 있다.

	- 어떤 클래스의 디폴트 대입 연산자는, 기초 클래스 성분의 대입을 위해 기초 클래스의 대입 연산자를 자동적으로 사용한다.

	- 상속된 객체들의 이러한 속성들은, 그들 자체가 객체인 클래스 멤버들에도 여전히 적용된다.
		ex) 10장 Stock클래스의 멤버 string company
			: 표준 string클래스는 동적 메모리 대입을 사용하는데 이것은 문제를 일으키지 않는다.
			: Stock클래스의 디폴트 복사 생성자는 string 클래스의 복사 생성자를 사용하여 객체의 company 멤버를 복사한다.
			  Stock클래스의 디폴트 대입 연산자는 string 클래스의 대입 연산자를 사용하여 객체의 company 멤버를 대입한다.
			: (디폴트 또는 디폴트가 아닌)Stock 파괴자는 자동적으로 string 파괴자를 호출한다.
*/



// 경우2) DMA를 사용하는 파생 클래스 => 파생 클래스를 위한 명시적 파괴자, 복사 생성자, 대입 연산자를 당연히 정의해야 한다.
class hasDMA : public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};

#endif

