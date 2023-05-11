#ifndef DMA_H_
#define DMA_H_
#include <iostream>


/*
	- ��Ӱ� ���� �޸� ����
		: ���� Ŭ������ ���� �޸� ������ ����ϰ�, ���԰� ���� �����ڸ� �ٽ� �����Ѵٸ� �װ��� �Ļ� Ŭ������ �����ϴ� �� ��� ������ ��ġ������
		  �Ļ� Ŭ������ ������ �޷� �ֵ�.
		  �Ļ� Ŭ���� �ڽ��� ���� �޸� ������ ������� �ʴ´ٸ�, � Ư���� ��ġ�� �ʿ䰡 ����.
		  �׷��� �Ļ� Ŭ���� �ڽ��� ���� �޸� ������ ����Ѵٸ�, �� �� ���� �� �ִ� ��ġ�� �� ������ �ִ�.

	- ���1) �Ļ� Ŭ������ new�� ������� �ʴ´�.
	  ���2) �Ļ� Ŭ������ new�� ����Ѵ�.
*/

// DMA�� ����ϴ� ���� Ŭ���� => �����ڰ� new�� ����� �� �䱸�Ǵ� Ư���� �޼����. ��, �ı���, ���������, �����ε� ���� �����ڸ� ������.
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

// ���1) DMA�� ������� �ʴ� �Ļ� Ŭ���� => �ı��ڰ� �ʿ� ����, �Ͻ��� ���� ������, �Ͻ��� ���� �����ڸ� ����Ѵ�.
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
	- ����� �ı��ڸ� �������� ������, �����Ϸ��� �ƹ� �ϵ� ���� �ʴ� ����Ʈ �ı��ڸ� �����Ѵ�.
	  �Ļ� Ŭ������ ���� �� ����Ʈ �ı��ڴ�, �ڽ��� �ڵ带 ������ �� ���� Ŭ������ �ı��ڸ� �׻� ȣ���Ѵ�.
	  lacksDMA ������� � Ư���� ���۵� �䱸���� �ʴ´ٰ� �����߱� ������, �� ��� ����Ʈ �ı��ڸ� ������ ����ϴ�.

	- ����Ʈ ���� �����ڴ� ����� ���縦 �Ѵ�. ����� ����� ���� �޸� ���Կ��� ����� �� ����.
	  ����� ����� ���������� �°� ���ǵ� ���� ������ ����Ѵ�. �׷��� long�� long���� �����ϴ� ���� �Ϲ����� ������ ���Ͽ� �̷������.
	  �׷��� Ŭ���� ��� �Ǵ� ��ӹ��� Ŭ���� ������ �����ϴ� ����, �� Ŭ������ ���� �����ڸ� ���Ͽ� �̷������.
	  lacksDMA Ŭ������ ����Ʈ ���� �����ڴ�, lacksDMA ��ü�� baseDMA ������ �����ϱ� ���� ������� baseDMA ���� �����ڸ� ����Ѵ�.
	  �׷��Ƿ� lacksDMA Ŭ������ ����Ʈ ���� �����ڴ� ���ο� lacksDMA ����� ���� ����� �� �ְ�, ��ӹ��� baseDMA ��ü�� ���ؼ��� ����� �� �ִ�.

	- � Ŭ������ ����Ʈ ���� �����ڴ�, ���� Ŭ���� ������ ������ ���� ���� Ŭ������ ���� �����ڸ� �ڵ������� ����Ѵ�.

	- ��ӵ� ��ü���� �̷��� �Ӽ�����, �׵� ��ü�� ��ü�� Ŭ���� ����鿡�� ������ ����ȴ�.
		ex) 10�� StockŬ������ ��� string company
			: ǥ�� stringŬ������ ���� �޸� ������ ����ϴµ� �̰��� ������ ����Ű�� �ʴ´�.
			: StockŬ������ ����Ʈ ���� �����ڴ� string Ŭ������ ���� �����ڸ� ����Ͽ� ��ü�� company ����� �����Ѵ�.
			  StockŬ������ ����Ʈ ���� �����ڴ� string Ŭ������ ���� �����ڸ� ����Ͽ� ��ü�� company ����� �����Ѵ�.
			: (����Ʈ �Ǵ� ����Ʈ�� �ƴ�)Stock �ı��ڴ� �ڵ������� string �ı��ڸ� ȣ���Ѵ�.
*/



// ���2) DMA�� ����ϴ� �Ļ� Ŭ���� => �Ļ� Ŭ������ ���� ����� �ı���, ���� ������, ���� �����ڸ� �翬�� �����ؾ� �Ѵ�.
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

