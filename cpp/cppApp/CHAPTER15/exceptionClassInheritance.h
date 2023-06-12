#include <stdexcept>
#include <string>

class Sales
{
protected:
	enum { MONTHS = 12 };
public:	
	class bad_index : public std::logic_error
	{
	private:
		int bi;
	public:
		explicit bad_index(int ix, const std::string& s = "Sales 객체에서 인덱스 에러\n");
		int bi_val() const { return bi; }
		virtual ~bad_index() throw() { }
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales() { }
	int Year() const { return year; }

	virtual double operator[](int i) const;
	virtual double& operator[](int i);
	
private:
	double gross[MONTHS];
	int year;
};

class LabeledSales : public Sales
{
public:
	class nbad_index : public Sales::bad_index 
	{
	private:
		std::string lbl;
	public:
		nbad_index(const std::string& lb, int ix, const std::string& s = "LabeledSales 객체에서 인덱스 에러\n");
		const std::string& label_val() const { return lbl; }
		virtual ~nbad_index() throw() { }		
	};

	explicit LabeledSales(const std::string& lb = "없음", int yy = 0);
	LabeledSales(const std::string& lb, int yy, const double* gr, int n);
	virtual ~LabeledSales() { }
	const std::string& Label() const { return label; }

	virtual double operator[](int i) const;
	virtual double& operator[](int i);
private:
	std::string label;
};

/*
	- 기호 상수 MONTHS는 Sales의 protected 부분에 들어 있다.
	  이것은 LabeledSales와 같은 파생 클래스에서 그 값을 사용할 수 있게 만든다.

	- bad_index 클래스는 Sales의 public 부분에 내포되어 있다. 이것은 클라이언트 catch 블록들에서 그 클래스를 하나의 데이터형으로 사용할 수 있게 만든다.
	  Sales 클래스 외부에서는 그 데이터형이 Sales::bad_index로 인식될 것을 요구한다.
	  (내포된 클래스들은 밖에서 사용 시 사용 범위 결정 연산자를 한 번 이상 사용할 것을 요구한다.)

	- nbad_index 클래스는 LabeledSales의 public 부분에 내포되어 있다. 이것은 클라이언트 코드에서 LabeledSales::nbad_index로 그것을 사용할 수 있게 만든다.
*/