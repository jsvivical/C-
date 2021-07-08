#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

typedef struct node
{
	int key;
	struct node* next;
}graph;


graph* vertex[MAX_SIZE];
graph* inverse[MAX_SIZE];

graph* createNode(int k)
{
	graph* temp;
	temp = malloc(sizeof(graph));

	temp->key = k;
	temp->next = NULL;

	return temp;
}

void appendNode1(int i, graph* new)
{
	new->next = inverse[i];
	inverse[i] = new;

}


void appendNode2(int i, graph* new)
{
	new->next = vertex[i];
	vertex[i] = new;

}


void printList1(int size)
{
	graph* p;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		count = 0;
		p = vertex[i];
		printf("[%3d]", i);
		while (p)
		{
			count++;
			p = p->next;
		}
		printf("%3d", count);
		puts("");
	}
}

void printList2(int size)
{
	graph* p;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		count = 0;
		p = inverse[i];
		printf("[%3d]", i);
		while (p)
		{
			count++;
			p = p->next;
		}
		printf("%3d", count);
		puts("");
	}
}


void main()
{
	FILE* f1, *f2;
	int from, to;
	int size;
	graph* temp;

	f1 = fopen("in.txt", "r");
	fscanf(f1, "%d", &size);
	puts(""); puts("");


	printf("indegree\n");

	while (!feof(f1))
	{
		fscanf(f1, "%d %d", &from, &to);
		temp = createNode(from);
		appendNode1(to, temp);
	}
	printList2(size);





	f2 = fopen("in.txt", "r");
	fscanf(f2, "%d", &size);
	puts(""); puts("");


	printf("Outdegree\n");

	while (!feof(f2))
	{
		fscanf(f2, "%d %d", &from, &to);
		temp = createNode(to);
		appendNode2(from, temp);
	}
	printList1(size);


}