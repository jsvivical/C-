#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	int data;
}element;

element* stack;
int capacity =1;
int top = -1;

void push(int);
void stackEmpty();
void pop();
void stackFull();

void push(int temp)
{
	if (top >= capacity -1) //스택이 가득참
	{
		printf("\tstackfull : ");
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
	else stack[top--];
}

void stackFull()
{
	stack = (element *)realloc(stack, 2 * capacity * sizeof(element));
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
		case -1 :
			printf("pop\n");
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

