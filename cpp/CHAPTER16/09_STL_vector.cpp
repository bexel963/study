/*
	- �˻�, ����, ������ ������ȭ�ϴ� ���� �۾� ���� �Ϲ����� �۾����� Ŭ������ ����� ������ �ʰ�,
	  ��� �����̳� Ŭ������ ����� �� �ֵ��� ���� �Լ��� �����Ѵ�.
	  ����, ���ο� �����̳� Ŭ������ �����ϴ���, ������ ��ħ�� �����ٸ� ���� �Լ��� ����Ͽ� �˻�, ���� ���� ó���� �� �ִ�.
	- ����, STL�� ������ �۾��� �ϴ� ���� �Լ��� �ִ��� ��� �Լ��� ���� ����� ��찡 �ִ�.
	  �� ������ �Ϲ����� �˰��� ���ؼ� Ŭ������ Ưȭ�� �˰����� �� ȿ�����̱� �����̴�.

	- ��ǥ���� STL �Լ���...

		1) for_each()
			: 1 ~ 2��° �Ű����� -> �����̳� ���� �����ϴ� ���ͷ�����
			: 3��° �Ű�����		-> �Լ��� �����ϴ� ������
			: �� �Լ��� �Ű������� ���õ� �Լ��� �� ���� �ȿ� �ִ� �� �����̳� ���ҿ� �����Ѵ�.
			  ���õ� �Լ��� �����̳� ���ҵ��� ���� �����ϸ� �� �ȴ�.
			: for ���� ��ſ� �� �Լ��� ����� �� �ִ�.

				vector<Review>::iterator pr;
				for(pr=books.begin() ; pr!=books.end() ; pr++)
					showReview(*pr);
						
						===>

				for_each(books.begin(), books.end(), showReview);

			: �̷��� �ϸ� ���ͷ����� ������ ��������� ����ؾ� �ϴ� ���ŷο� ����� �ڵ带 ���� �� �ִ�.

		2) random_shuffle()
			: ������ �����ϴ� �� ���� ���ͷ����͸� ����Ͽ�, �� ���� �ȿ� �ִ� ���ҵ��� ������ ������ ���ġ�Ѵ�.

				random_shuffle(books.begin(), books.end());

			: ��� �����̳� Ŭ������ ���Ǵ� for_each�ʹ� �޸�, �� �Լ��� �����̳� Ŭ������ ���� ������ ����� ���� �䱸�Ѵ�. vector Ŭ������ ���� ������ ����Ѵ�.

		3) sort()
			: �� �Լ��� �����̳ʰ� ���� ������ ����� ���� �䱸�Ѵ�.
			: �� �Լ��� �� ���� ������ �ִ�.
				version1) ������ �����ϴ� �� ���� ���ͷ����͸� ����Ѵ�.
						  �� ������ �����̳ʿ� ����Ǿ� �ִ� ���������� ���ҿ� �°� ���ǵ� < �����ڸ� ����Ͽ� �� ������ ������������ �����Ѵ�.

								vector<int> coolstuff;
								...
								sort(coolstuff.begin(), coolstuff.end());

						  �����̳��� ���ҵ��� ����� ���� ��ü�� ��, sort()�� ����Ϸ���, �� ��ü�� ���������� �°� �����̵� operator<()�� �־�� �Ѵ�.

								bool operator<(const Review& r1, const Review& r2)
								{
									if(r1.title < r2.title)
										return true;
									else if (r1.title == r2.title && r1.rating < r2.rating)
										return true;
									else
										return false;
								}
						  ���� ���� �Լ��� �غ�Ǿ� ������, Review ��ü���� ���͸� ������ �� �ִ�.
								sort(books.begin(), books.end());

				version2) ���������� ���ҿ� �°� ���ǵ� < �����ڷ� ���� �� �ϰ�, ����ڰ� ���Ƿ� ���ϴ� ������� �����Ѵ�.

					
								bool woresThan(const Review& r1, const Review& r2)
								{
									if(r1.rating < r2.rating)
										return true;
									else
										return false;
								}

								sort(books.begin(), books.end(), worseThan);											   
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review {
	std::string title;
	int rating;
};

bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);
bool fillReview(Review& r);
void showReview(const Review& r);

int main()
{
	using namespace std;
	
	vector<Review> books;
	Review temp;
	while (fillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "�����մϴ�. ����� ������ ���� " << books.size() << "���� å ����� �Է��ϼ̽��ϴ�.\n ���\t����\n";
		for_each(books.begin(), books.end(), showReview);

		sort(books.begin(), books.end());
		cout << "å ������ �������� ����: \n���\t����\n";
		for_each(books.begin(), books.end(), showReview);

		sort(books.begin(), books.end(), worseThan);
		cout << "å ������� �������� ����: \n���\t����\n";
		for_each(books.begin(), books.end(), showReview);

		random_shuffle(books.begin(), books.end());
		cout << "������ ������ �ٽ� ��ġ:\n���\t����\n";
		for_each(books.begin(), books.end(), showReview);
	}
	else
		cout << "���α׷��� �����մϴ�.\n";

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

bool operator<(const Review& r1, const Review& r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool worseThan(const Review& r1, const Review& r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}
