#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	int data;
}element;

element* stack;
int capacity = 1;
int top = -1;

void push(int);
void stackEmpty();
void pop();
void stackFull();
void reduce();

void push(int temp)
{
	if (top >= capacity - 1) //스택이 가득참
	{
		stackFull(); //용량을 늘려줌 
	}
	stack[++top].data = temp;
}
void stackEmpty()
{
	printf("stack empty.\n");
}
void pop()
{
	if (top == -1) //스택이 비었음
	{
		stackEmpty();
	}
	else
	{
		printf("pop item : %d  ", stack[top]);
		stack[top--];
		if (top < (capacity / 2) && capacity > 1) reduce();
		else puts("");
	}
}

void reduce()
{
	stack = (element*)realloc(stack,(0.5 * capacity * sizeof(element)));
	capacity /= 2;
	printf("\treducing size(/2) : %d\n", capacity);
}

void stackFull()
{
	stack = (element*)realloc(stack, 2 * capacity * sizeof(element));
	capacity *= 2;
	printf("doubling : %d", capacity);
}


int main()
{
	stack = (element*)malloc(sizeof(element));
	FILE* f1, * f2;
	int i = 0, temp;

	f1 = fopen("a.txt", "r");
	while (!feof(f1))
	{
		fscanf(f1, "%d", &temp);
		switch (temp)
		{
		case -1:
			pop();
			break;
		default:
			printf("push item : %d\t", temp);
			push(temp);
			puts("");
		}
	}
	printf("\n\n최종 stack 출력\n");
	while (top != -1)
	{
		printf("<%3d>\n", stack[top--]);
	}


	free(stack);
	fclose(f1);

}

