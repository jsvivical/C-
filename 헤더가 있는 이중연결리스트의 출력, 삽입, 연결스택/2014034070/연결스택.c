#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct node 
{
	int id;
	int score;
	struct node* next;
}element;

element* top[MAX_SIZE];

element* createNode(int id, int sc);
void push(int i, element item);
element pop(int i);
element stackEmpty();

void main()
{
	FILE* f = fopen("score.txt", "r");
	int class, identity, scr;
	element new;

	while (!feof(f))
	{
		fscanf(f, "%d %d %d", &class, &new.id, &new.score);
		push(class, new);
	}
	element temp;
	int i = 0;
	printf("과목 %d\n", i);
	while (top[i])
	{
		temp = pop(i);
		printf("pop from top[%d] : %d %d\n", i,temp.id, temp.score);
		if (!top[i] && i < 2)
		{
			i++;
			printf("과목 %d\n", i);
		}
	}
	





}

element* createNode(int identity, int s)
{
	element* p = malloc(sizeof(element));
	p->id = identity;
	p->score = s;

	return p;
}
void push(int i, element item)
{
	printf("push to top[%d] : (%3d, %3d)\n",i, item.id, item.score);
	element* temp;
	temp = malloc(sizeof(element));
	temp->id = item.id;
	temp->score = item.score;
	temp->next = top[i];
	top[i] = temp;
}

element pop(int i)
{
	element* temp = top[i];
	element item;
	if (!temp) (i)++;
	item.id = temp->id;
	item.score = temp->score;
	top[i] = temp->next;
	free(temp);

	return item;
}



