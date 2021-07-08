#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 4

typedef struct person
{
	char name[20];
	int age;
	int bus;
}PERSON;

typedef struct queue
{
	PERSON p;
	struct queue* next;
}QUEUE;

QUEUE* front[MAX_SIZE];
QUEUE* rear[MAX_SIZE];

void addQ(int, PERSON);
PERSON deleteQ(int);
void printQ(int);
int busIntoIndex(int num);

int busIntoIndex(int num)
{
	if (num == 55) return 0;
	else if (num == 121) return 1;
	else if (num == 100) return 2;
	else if(num == 413) return 3;

}
void main()
{
	FILE* f;
	QUEUE* head, * tail;
	PERSON temp;
	f = fopen("bus.txt", "r");
	int i; //버스번호
	int input;

	while (!feof(f))
	{
		fscanf(f,"%s %d %d", temp.name, &temp.age, &temp.bus);
		i = busIntoIndex(temp.bus);
		addQ(i, temp);

	}
	for (int j = 0; j < 4; j++)
	{
		printf("BUS %3d : ", front[j]->p.bus);
		printQ(j);
	}

	do 
	{
		printf("input bus number\n");
		scanf("%d", &input);
		deleteQ(input);
		printQ(busIntoIndex(input));
		
	} while (1);






}

void addQ(int i, PERSON person)
{
	if (!front[i])
	{
		front[i] = malloc(sizeof(QUEUE));
		rear[i] = front[i];
	}

	else
	{
		rear[i]->next = malloc(sizeof(QUEUE));
		rear[i] = rear[i]->next;
	}
	strcpy(rear[i]->p.name , person.name);
	rear[i]->p.age = person.age;
	rear[i]->p.bus = person.bus;
	rear[i]->next = NULL;

}

void printQ(int i)
{
	QUEUE* cur = front[i];
	
	
		while (cur)
		{
			printf("[%4s %3d]", cur->p.name, cur->p.age);
			cur = cur->next;
		}

		puts("");

}

PERSON deleteQ(int bus)
{
	PERSON* temp;
	int i = busIntoIndex(bus);
	if (front[i] == NULL) printf("empty queue");
	else if (front[i]->next == NULL)
	{
		temp = front[i];
		free(temp);
		front[i] = NULL;
		printf("empty list\n");
		return;
	}
	else 
	{
		temp = front[i];
		front[i] = front[i]->next;

		free(temp);
	}
	return;

}