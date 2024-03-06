#include <iostream>

using namespace std;

class Rectangle
{
private:
	int lenght;
	int breadth;

public:
	Rectangle() { lenght = 1; breadth = 1; } //default constructor
	Rectangle(int l, int b);
	int area();		//will be implemented outside the class
	int perimeter();
	int getLenght() {
		return lenght;
	}
	void setLenght(int l) {
		lenght = l;
	}
	~Rectangle(); //destructor
};

//scope resolution zone
Rectangle::Rectangle(int l, int b)
{
	lenght = l;
	breadth = b;
}

int Rectangle::area()
{
	return lenght * breadth;
}

int Rectangle::perimeter()
{
	return 2 * (lenght + breadth);
}

Rectangle::~Rectangle()
{
}


int main()
{	
	Rectangle r(10, 5);
	cout << r.area()<< endl;
	cout << r.perimeter() << endl;
	r.setLenght(20);
	cout << r.getLenght() << endl;
	
	return 0;
}