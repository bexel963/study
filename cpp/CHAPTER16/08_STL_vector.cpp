/*
	- 모든 STL 컨테이너들은 다음과 같은 기본적인 메서드들을 제공한다.

			size()
			swap()
			begin()		-> 컨테이너에 있는 첫 번째 원소를 참조하는 이터레이터를 리턴
			end()		-> 컨테이너에 있는 마지막 원소 바로 다음을 참조하는 이터레이터를 리턴
*/

/*
	- 이터레이터
		: 이터레이터는 포인터의 일반화이다.
		: 포인터를 이터레이터로 일반화하면, 단순 포인터를 가지고는 동작시킬 수 없는 클래스를 포함하여 다양한 컨테이너 클래스들에 일관된 인터페이스를
		  제공할 수 있다.
		  각 컨테이너 클래스는 하나의 적절한 이터레이터를 정의한다. 그 이터레이터의 데이터형 이름은 iterator인데, 클래스 사용 범위를 가지는 typedef 이다.
				
				vector<double>::iterator pd;

				vector<double> scores;

				pd = scores.begin();	// pd가 첫 번째 원소를 지시하게 한다.
				*pd = 22.3;				// pd를 내용 참조하여 첫 번째 원소에 값을 대입한다.
				++pd;					// pd가 그 다음 원소를 지시하게 만든다.

	- past-the-end
		: 컨테이너에 있는 마지막 원소 바로 다음에 있는 원소를 참조하는 이터레이터이다.
		: end()는 past-the-end 위치를 인식한다.
		: 이터레이터를 컨테이너에 있는 첫 번째 원소로 설정하고, 이터레이터를 계속 증가시켜 past-the-end에 도달하면, 컨테이너 안에 있는 전체 내용을 통과한 셈이 된다.

				for(pd = scores.begin() ; pd != scores.end() ; pd++)
					cout << *pd << endl;
*/

/*
	- vector 템플릿 클래스와 일부 STL 컨테이너들만 가지고 있는 몇 가지의 메서드들....

		1) push_back()
			: 벡터의 끝에 하나의 원소를 추가한다. 이것을 하는 동안, 이 메서드는 메모리 관리에 관여하여 벡터의 끝에 멤버를 추가할 수 있도록 벡터의 크기를 늘린다.
		2) erase()
			: 지정된 범위를 벡터에서 삭제, 두 개의 이터레이터를 매개변수로 사용한다.
		3) insert()
			: 3개의 이터레이터 매개변수 사용
				1     -> 새로운 원소들이 삽입될 위치 바로 앞의 위치를 제공
				2 ~ 3 -> 삽이에 사용할 범위를 정의
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
		cout << "감사합니다. 당신은 다음과 같이 입력하셨습니다.\n";
		for (int i = 0; i < num; i++)
			showReview(books[i]);

		cout << "한 번 더 출력한다:\n 등급\t제목\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			showReview(*pr);

		vector<Review> oldList(books);	// 복사 생성자 사용

		if (num > 3)
		{
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "삭제한 후:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				showReview(*pr);

			books.insert(books.begin(), oldList.begin() + 1, oldList.begin() + 2);
			cout << "삽입한 후:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				showReview(*pr);
		}
		books.swap(oldList);
		cout << "oldList와 books를 교환한 후:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
			showReview(*pr);
	}
	else
		cout << "입력한 것이 없어, 얻은 것이 없습니다.\n";

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