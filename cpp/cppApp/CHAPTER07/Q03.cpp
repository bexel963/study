#include <iostream>

using namespace std;

struct Box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void print(Box);
void setVolume(Box*);

int main()
{
	Box box = {
		"아디다스",
		10, 20, 30, 0
	};

	print(box);
	setVolume(&box);
	cout << "--------------------\n";
	print(box);
	return 0;
}

void print(Box box)
{
	cout << "maker: " << box.maker << endl;
	cout << "height: " << box.height << endl;
	cout << "width: " << box.width << endl;
	cout << "length: " << box.length << endl;
	cout << "volume: " << box.volume << endl;
}

void setVolume(Box* box)
{
	box->volume = box->height * box->width * box->length;
}