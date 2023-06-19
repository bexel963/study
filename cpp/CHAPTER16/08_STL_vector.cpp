/*
	- ��� STL �����̳ʵ��� ������ ���� �⺻���� �޼������ �����Ѵ�.

			size()
			swap()
			begin()		-> �����̳ʿ� �ִ� ù ��° ���Ҹ� �����ϴ� ���ͷ����͸� ����
			end()		-> �����̳ʿ� �ִ� ������ ���� �ٷ� ������ �����ϴ� ���ͷ����͸� ����
*/

/*
	- ���ͷ�����
		: ���ͷ����ʹ� �������� �Ϲ�ȭ�̴�.
		: �����͸� ���ͷ����ͷ� �Ϲ�ȭ�ϸ�, �ܼ� �����͸� ������� ���۽�ų �� ���� Ŭ������ �����Ͽ� �پ��� �����̳� Ŭ�����鿡 �ϰ��� �������̽���
		  ������ �� �ִ�.
		  �� �����̳� Ŭ������ �ϳ��� ������ ���ͷ����͸� �����Ѵ�. �� ���ͷ������� �������� �̸��� iterator�ε�, Ŭ���� ��� ������ ������ typedef �̴�.
				
				vector<double>::iterator pd;

				vector<double> scores;

				pd = scores.begin();	// pd�� ù ��° ���Ҹ� �����ϰ� �Ѵ�.
				*pd = 22.3;				// pd�� ���� �����Ͽ� ù ��° ���ҿ� ���� �����Ѵ�.
				++pd;					// pd�� �� ���� ���Ҹ� �����ϰ� �����.

	- past-the-end
		: �����̳ʿ� �ִ� ������ ���� �ٷ� ������ �ִ� ���Ҹ� �����ϴ� ���ͷ������̴�.
		: end()�� past-the-end ��ġ�� �ν��Ѵ�.
		: ���ͷ����͸� �����̳ʿ� �ִ� ù ��° ���ҷ� �����ϰ�, ���ͷ����͸� ��� �������� past-the-end�� �����ϸ�, �����̳� �ȿ� �ִ� ��ü ������ ����� ���� �ȴ�.

				for(pd = scores.begin() ; pd != scores.end() ; pd++)
					cout << *pd << endl;
*/

/*
	- vector ���ø� Ŭ������ �Ϻ� STL �����̳ʵ鸸 ������ �ִ� �� ������ �޼����....

		1) push_back()
			: ������ ���� �ϳ��� ���Ҹ� �߰��Ѵ�. �̰��� �ϴ� ����, �� �޼���� �޸� ������ �����Ͽ� ������ ���� ����� �߰��� �� �ֵ��� ������ ũ�⸦ �ø���.
		2) erase()
			: ������ ������ ���Ϳ��� ����, �� ���� ���ͷ����͸� �Ű������� ����Ѵ�.
		3) insert()
			: 3���� ���ͷ����� �Ű����� ���
				1     -> ���ο� ���ҵ��� ���Ե� ��ġ �ٷ� ���� ��ġ�� ����
				2 ~ 3 -> ���̿� ����� ������ ����
*/

#include <iostream>
#include <string>
#include <vector>

struct Review {
	std::string title;
	int rating;
};
bool fillReview(Review& r);
void showReview(const Review& r);

int main()
{
	using std::cout;
	using std::vector;
	
	vector<Review> books;
	Review temp;
	while (fillReview(temp))
		books.push_back(temp);

	int num = books.size();
	if (num > 0)
	{
		cout << "�����մϴ�. ����� ������ ���� �Է��ϼ̽��ϴ�.\n";
		for (int i = 0; i < num; i++)
			showReview(books[i]);

		cout << "�� �� �� ����Ѵ�:\n ���\t����\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			showReview(*pr);

		vector<Review> oldList(books);	// ���� ������ ���

		if (num > 3)
		{
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "������ ��:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				showReview(*pr);

			books.insert(books.begin(), oldList.begin() + 1, oldList.begin() + 2);
			cout << "������ ��:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				showReview(*pr);
		}
		books.swap(oldList);
		cout << "oldList�� books�� ��ȯ�� ��:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
			showReview(*pr);
	}
	else
		cout << "�Է��� ���� ����, ���� ���� �����ϴ�.\n";

	return 0;

}

bool fillReview(Review& r)
{
	std::cout << "å ������ �Է��Ͻʽÿ�(�������� quit�� �Է�): ";
	std::getline(std::cin, r.title);
	if (r.title == "quit")
		return false;
	std::cout << "å �(0-10)�� �Է��Ͻʽÿ�: ";
	std::cin >> r.rating;
	if (!std::cin)
		return false;

	while (std::cin.get() != '\n')
		continue;

	return true;
}

void showReview(const Review& r)
{
	std::cout << r.rating << "\t" << r.title << std::endl;
}