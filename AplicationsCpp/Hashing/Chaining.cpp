#include <stdlib.h>
#include "Chains.h"


int hash(int key)
{
	return key % 10;
}

void Insert(struct Node* H[], int key)
{
	int index = hash(key);
	InsertSorted(&H[index], key);
}

int DeleteHash(struct Node* H[], int key)
{
	struct Node * exists;
	int index = hash(key);
	exists = Search(H[index], key);
	if (exists == NULL)
	{
		return 0;
	}
	int val = Delete(&H[index], key);
	return val;
}


int main()
{
	struct Node* HT[10];
	struct Node* temp;
	int i;

	for (i = 0; i < 10; i++)
		HT[i] = NULL;

	Insert(HT, 12);
	Insert(HT, 22);
	Insert(HT, 42);
	Insert(HT, 7);
	Insert(HT, 6);

	//temp = Search(HT[hash(22)], 22);

	//printf("%d", temp->data);

	int res = DeleteHash(HT,7);
	printf("%d", res);
	Insert(HT, 17);
	

	return 0;
}