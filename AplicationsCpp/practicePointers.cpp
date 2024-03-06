#include<iostream>
#include<stdio.h>
#include<string>
#include <vector>
#include<stdlib.h>
using namespace std;

struct Rectangle
{
	int lenght;
	int breadth;
};

class Triangle
{
public:
	Triangle(double base, double height) {
		width_ = base;
		height_ = height;
	}

private:
	double width_;
	double height_;
};

int main()
{
	//Rectangle* p_Rectangle;
	//struct Rectangle rectangle = { 2,5 };

	//p_Rectangle = &rectangle;

	Rectangle* p_Rectangle;
	p_Rectangle = new Rectangle;
	p_Rectangle->lenght = 10;
	p_Rectangle->breadth = 5;

	cout << "value of p_Rectangle " << p_Rectangle << endl;
	cout << "value of p_Rectangle->lenght " << p_Rectangle->lenght << endl;
	//cout << "value of rectangle.lenght " << rectangle.lenght << endl;

	return 0;
}