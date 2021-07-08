#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int heap[MAX_SIZE];
int front = 0; int rear = 0;
int n = 0;

void push(int item) 
{

	int i;
	i = ++n;
	while ((i != 1) && item < heap[i / 2])
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

void levelOrder(int size)
{
	for (int i = front + 1; i <= size; i++)
	{
		printf("%3d", heap[i]);
	}
	puts("");
}


int pop()
{
	front = (front + 1) % MAX_SIZE;
	
	return heap[front];
}

void main()
{
	int temp; int size = 0; int delete;

	FILE* f;
	f = fopen("in.txt", "r");
	
	while (!feof(f))
	{
		fscanf(f, "%d", &temp);
		push(temp);
		size++;
	}
	levelOrder(size);
	printf("input delete number : "); scanf("%d", &delete);
	for (int i = 0; heap[i] != delete; i++)
	{
		printf("item(deleted) : %d\n", pop());
	}
	printf("after deleting....\n");
	levelOrder(size);




}