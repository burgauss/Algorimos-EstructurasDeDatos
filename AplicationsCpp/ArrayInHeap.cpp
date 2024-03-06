#include <iostream>
#include <stdio.h>
using namespace std;


struct Array
{
	int A[10];
	int size;
	int lenght;
};


void Append(struct Array* arr, int x)
{
	if (arr->lenght < arr->size)
	{
		arr->A[arr->lenght] = x;
	}
	arr->lenght++;
}

void Insert(struct Array* arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->lenght)
	{
		for (i = arr->lenght; i > index; i--)
		{
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = x;
		arr->lenght++;
	}
}

int Delete(struct Array* arr, int index)
{
	int x = 0;	

	if (index >= 0 && index <= arr->lenght)
	{
		x = arr->A[index];
		for (int i = index; i < arr->lenght - 1; i++)
		{
			arr->A[i] = arr->A[i + 1];
		}
		arr->lenght--;
		return x;
	}

	return 0;
}

void Display(struct Array arr)
{
	int i;
	printf("Elements are\n");
	for (i = 0; i < arr.lenght; i++)
	{
		printf("%d ", arr.A[i]);
	}
}

int LinearSearch(struct Array arr, int key)
{
	int i;
	for (i = 0; i < arr.lenght; i++)
	{
		if (key == arr.A[i])
			return i;
	}
	return -1;
}

int main()
{
	struct Array arr = { {2,3,4,5,6},10,5 };
	//printf("%d\n", Delete(&arr,0));
	printf("%d\n", LinearSearch(arr,15));
	Display(arr);

	return 0;
}