#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int size;
	int top;
	struct Node ** s;
};

void StackCreate(struct Stack* st, int size)
{
	st->size = size;
	st->top = -1;
	st->s = (struct Node**)malloc(st->size * sizeof(struct Node*));
}

void Display(struct Stack st)
{
	for (int i = st.top; i >= 0; i--)
	{
		printf("%d ", st.s[i]);
	}
	printf("\n");
}

void push(struct Stack* st, struct Node* x)
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

struct Node* pop(struct Stack* st)
{
	struct Node* x = NULL;
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


int isEmptyStack(Stack st)
{
	if (st.top == -1)
		return 1;
	else
		return 0;
}

int isFullStack(Stack st)
{
	if (st.top == st.size - 1)
		return 1;
	else
		return 0;
}
