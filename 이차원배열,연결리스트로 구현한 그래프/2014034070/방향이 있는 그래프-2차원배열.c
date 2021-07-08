#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 101

typedef struct node
{
	int key;
	struct node* next;
}graph;

graph* vertex[MAX_SIZE];
int matrix[MAX_SIZE][MAX_SIZE];


graph* createNode(int k)
{
	graph* temp;
	temp = malloc(sizeof(graph));

	temp->key = k;
	temp->next = NULL;

	return temp;
}

void appendNode(int i, graph* new)
{
	new->next = vertex[i];
	vertex[i] = new;

}

void printList(int size)
{
	graph* p; 
	for (int i = 0; i < size; i++)
	{
		p = vertex[i];
		printf("[%3d]", i);
		while(p)
		{
			printf("%3d",p->key);
			p = p->next;
		}
		puts("");
	}
}

void main()
{
	int size;
	int from, to;
	FILE* f1, *f2;
	graph* temp;

	f1 = fopen("in.txt", "r");
	fscanf(f1, "%d", &size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = 0;
		}
		
	}


	while (!feof(f1))
	{
		fscanf(f1, "%d %d", &from, &to);
		matrix[from][to] = 1;
	}
	printf("Adjacency matrix...\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%3d", matrix[i][j]);
		}
		puts("");
	}

	f2 = fopen("in.txt", "r");
	fscanf(f2, "%d", &size);
	puts(""); puts("");


	printf("Linked adjacency list...\n");

	while (!feof(f2))
	{
		fscanf(f2, "%d %d", &from, &to);
		temp = createNode(to);
		appendNode(from, temp);
	}
	printList(size);
	




}