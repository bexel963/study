/*
	- 검색, 정렬, 순서를 무작위화하는 등의 작업 같이 일반적인 작업들은 클래스의 멤버로 들어가있지 않고,
	  모든 컨테이너 클래스에 사용할 수 있도록 비멤버 함수로 정의한다.
	  따라서, 새로운 컨테이너 클래스를 정의하더라도, 적절한 지침을 따른다면 비멤버 함수를 사용하여 검색, 정렬 등을 처리할 수 있다.
	- 한편, STL은 동일한 작업을 하는 비멤버 함수가 있더라도 멤버 함수를 따로 만드는 경우가 있다.
	  그 이유는 일반적인 알고리즘에 비해서 클래스에 특화된 알고리즘이 더 효율적이기 때문이다.

	- 대표적인 STL 함수들...

		1) for_each()
			: 1 ~ 2번째 매개변수 -> 컨테이너 범위 정의하는 이터레이터
			: 3번째 매개변수		-> 함수를 지시하는 포인터
			: 이 함수는 매개변수로 지시된 함수를 그 범위 안에 있는 각 컨테이너 원소에 적용한다.
			  지시된 함수는 컨테이너 원소들의 값을 변경하면 안 된다.
			: for 루프 대신에 이 함수를 사용할 수 있다.

				vector<Review>::iterator pr;
				for(pr=books.begin() ; pr!=books.end() ; pr++)
					showReview(*pr);
						
						===>

				for_each(books.begin(), books.end(), showReview);

			: 이렇게 하면 이터레이터 변수를 명시적으로 사용해야 하는 번거로운 수고와 코드를 줄일 수 있다.

		2) random_shuffle()
			: 범위를 지정하는 두 개의 이터레이터를 사용하여, 그 범위 안에 있는 원소들을 무작위 순서로 재배치한다.

				random_shuffle(books.begin(), books.end());

			: 모든 컨테이너 클래스에 사용되는 for_each와는 달리, 이 함수는 컨테이너 클래스가 임의 접근을 허용할 것을 요구한다. vector 클래스는 임의 접근을 허용한다.

		3) sort()
			: 이 함수도 컨테이너가 임의 접근을 허용할 것을 요구한다.
			: 이 함수는 두 가지 버전이 있다.
				version1) 범위를 지정하는 두 개의 이터레이터를 사용한다.
						  이 버전은 컨테이너에 저장되어 있는 데이터형의 원소에 맞게 정의된 < 연산자를 사용하여 그 범위를 오름차순으로 정렬한다.

								vector<int> coolstuff;
								...
								sort(coolstuff.begin(), coolstuff.end());

						  컨테이너의 원소들이 사용자 정의 객체일 때, sort()를 사용하려면, 그 객체의 데이터형에 맞게 저으이된 operator<()가 있어야 한다.

								bool operator<(const Review& r1, const Review& r2)
								{
									if(r1.title < r2.title)
										return true;
									else if (r1.title == r2.title && r1.rating < r2.rating)
										return true;
									else
										return false;
								}
						  위와 같은 함수가 준비되어 있으면, Review 객체들의 벡터를 정렬할 수 있다.
								sort(books.begin(), books.end());

				version2) 데이터형의 원소에 맞게 정의된 < 연산자로 정렬 안 하고, 사용자가 임의로 원하는 방식으로 정렬한다.

					
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
		cout << "감사합니다. 당신은 다음과 같이 " << books.size() << "개의 책 등급을 입력하셨습니다.\n 등급\t제목\n";
		for_each(books.begin(), books.end(), showReview);

		sort(books.begin(), books.end());
		cout << "책 제목을 기준으로 정렬: \n등급\t제목\n";
		for_each(books.begin(), books.end(), showReview);

		sort(books.begin(), books.end(), worseThan);
		cout << "책 등급으로 기준으로 정렬: \n등급\t제목\n";
		for_each(books.begin(), books.end(), showReview);

		random_shuffle(books.begin(), books.end());
		cout << "무작위 순서로 다시 배치:\n등급\t제목\n";
		for_each(books.begin(), books.end(), showReview);
	}
	else
		cout << "프로그램을 종료합니다.\n";

	return 0;
}



bool fillReview(Review& r)
{
	std::cout << "책 제목을 입력하십시오(끝내려면 quit를 입력): ";
	std::getline(std::cin, r.title);
	if (r.title == "quit")
		return false;
	std::cout << "책 등릅(0-10)을 입력하십시오: ";
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
