#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int size;
	int top;
	int* s;
};

void Create(struct Stack *st)
{
	printf("enter size\n");
	scanf_s("%d", &st->size);
	st->top = -1;
	st->s = new int[st->size];
}

void Display(struct Stack st)
{
	for (int i = st.top; i >=0; i--)
	{
		printf("%d ", st.s[i]);
	}
	printf("\n");
}

void push(struct Stack* st, int x)
{
	if (st->top == st->size - 1)
	{
		printf("stack overflow!!\n");
	}
	else
	{
		st->top++;
		st->s[st->top] = x;
	}
}

int pop(struct Stack *st)
{
	int x = -1;
	if (st->top == -1)
	{
		printf("stack underflow\n");
	}
	else
	{
		x = st->s[st->top--];
	}
	return x;
}

int peek(struct Stack st, int pos)
{
	int x = -1;

	if (st.top - pos + 1 < 0 || pos <= 0)
		printf("invalid peek position \n");
	else
	{
		x = st.s[st.top - pos + 1];
	}
	return x;
}

int isEmpty(Stack st)
{
	if (st.top == -1)
		return 1;
	else
		return 0;
}

int isFull(Stack st)
{
	if (st.top == st.size - 1)
		return 1;
	else
		return 0;
}

int stackTop(Stack st)
{
	if (st.top == -1)
		return -1;
	else
		return st.s[st.top];
}

int main()
{
	struct Stack st;

	Create(&st);

	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);
	push(&st, 50);


	Display(st);

	printf("stack top element %d ", peek(st,1));


	return 0;
}