#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct
{
	int key;
}element;

element* queue;
int front = 0, rear = 0;
bool errorFlag = true;

void createQ(int size)
{
	queue = (element*)malloc(sizeof(element) * (size));
}



bool isEmpty()
{
	if (front == rear) return true;
	else return false;
}

bool isFull(int size)
{
	if ((rear + 1) % size == front)
	{
		return true;
	}
	else return false;
}

void addQ(element input, int size)
{
	if (isFull(size))
	{
		printf("queue is full\n");
		errorFlag = false;
	}
	else
	{
		queue[rear].key = input.key;
		rear = rear + 1;
		rear = rear % size;
	}


}

element deleteQ(int size)
{
	if (isEmpty())
	{
		printf("queue is empty\n");
		errorFlag = false;
	}
	else
	{
		front = front + 1;
		front = front % size;
		return queue[front];
	}
}

printQ(size)
{
	int i = 0;
	if (front < rear) 
	{
		for (i = front; i < rear; i++)
		{
			printf("%d ", queue[i]);
		}
	}
	else
	{
		i = front;
		while (i % size != 0)
		{
			printf("%d ", queue[i]);
			i++;
		}
		for (i = 0; i < rear; i++)
		{
			printf("%d ", queue[i]);
		}
	}
	puts("");
}


void main()
{
	int size;
	element a;
	char choice;
	printf("input size : ");
	scanf("%d", &size);
	createQ(size);
	printf("Circular queue size : %d\n", size);

	do
	{
		getchar();
		element a;
		printf("input : ");
		scanf("%c", &choice);
		switch (choice)
		{
		case 'd':
			deleteQ(size);
			printQ(size);
			break;
		case 'q':
			printf("quit\n");
			exit(1);
			break;
		case 'a':
			scanf("%d", &a.key);
			addQ(a, size);
			printQ(size);
			break;
		}

	} while (errorFlag);

	free(queue);
}