#include <iostream>

using namespace std;

struct Rectangle
{
	int lenght;
	int breadth;
};

struct PossibleSizes
{
	int pS[5];
};

void func(struct Rectangle *r1)
{						   
	r1->lenght = 15;
	printf("Length %d \nBreadth %d \n", r1->lenght, r1->breadth);
}

void printPossibleSizes(struct PossibleSizes _possibleSizes)
{
	//_possibleSizes.pS[0] = 10;
	for (int i = 0; i <= 4; i++)
	{
		cout << _possibleSizes.pS[i] << endl;
	}
}

struct Rectangle* ptr_fun()
{
	struct Rectangle* p;
	p = new Rectangle;
	//p =(struct Rectangle *)malloc(sizeof(struct Rectangle));

	p->lenght = 15;
	p->breadth = 7;

	return p;
}

int main()
{
	PossibleSizes headSizes = { 10,15,10,2 };
	printPossibleSizes(headSizes);


	return 0;
}