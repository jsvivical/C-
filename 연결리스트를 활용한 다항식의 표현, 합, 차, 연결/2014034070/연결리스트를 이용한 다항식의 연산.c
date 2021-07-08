#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x,y) (((x) < (y)) ? -1 : ((x) == (y))? 0 : 1)

typedef struct node
{
	int coef;
	int expon;
	struct node* next;
}POLY;

POLY* createNode(int, int);
void appendNode(POLY** head, POLY** tail, POLY* cur);
void printList(POLY* head);
void printList(POLY* head);
POLY* psub(POLY** result, POLY** r_tail, POLY* a, POLY* b);
void attach(int coefficient, int exponent, POLY*** r_tail);

POLY* createNode(int c, int e)
{
	POLY* cur = (POLY*)malloc(sizeof(POLY));
	cur->coef = c;
	cur->expon = e;
	cur->next = NULL;
}

void appendNode(POLY** head, POLY** tail, POLY* cur)
{
	if ((*head) == NULL)
	{
		(*head) = cur;
		(*tail) = *head;
	}
	else
	{
		(*tail)->next = cur;
		(*tail) = (*tail)->next;
	}
	(*tail)->next = NULL;
}

void printList(POLY* head)
{
	
	POLY* p;
	p = head;
	if (p) {
		while (p)
		{
			printf("[%d, %d] ", p->coef, p->expon);
			p = p->next;
		}
		puts("");
	}
	else {
		printf("empty List!\n");
	}
}

POLY* psub(POLY** result, POLY** r_tail,POLY* a, POLY* b)
{
	int sub;
	POLY* c, * rear, * temp;
	rear = malloc(sizeof(POLY));
	c = rear;

	while (a && b)
	{
		switch (COMPARE(a->expon, b->expon))
		{
		case -1:
			attach(-(b->coef), b->expon, &rear);
			b = b->next;
			break;

		case 0:
			sub = a->coef - (b->coef);
			if (sub != 0) attach(sub, a->expon, &rear);
			a = a->next;
			b = b->next;
			break;

		case 1:
			attach(a->coef, a->expon, &rear);
			a = a->next;
			break;
		}
	}
		for (; a; a = a->next) attach(a->coef, a->expon, &rear);
		for (; b; b = b->next) attach(-(b->coef), b->expon, &rear);
		rear->next = NULL;
	temp = c; c = c->next; free(temp);

	return c;

}

void attach(int coefficient, int exponent, POLY** rear)
{
	POLY* temp;
	temp = malloc(sizeof(POLY));
	temp->coef = coefficient;
	temp->expon = exponent;
	(*rear)->next = temp;
	(*rear) = (*rear)->next;;
}

void erase(POLY** ptr)
{
	POLY* temp;
	while (*ptr)
	{
		temp = *ptr;
		*ptr = (*ptr)->next;
		free(temp);
	}
}

void main()
{
	POLY *a = NULL, *b = NULL, *result = NULL;
	POLY* a_tail = NULL, *b_tail= NULL, *result_tail = NULL;
	POLY* cur;
	FILE* f1, * f2;
	int temp1, temp2;
	f1 = fopen("psub1.txt", "r");
	f2 = fopen("psub2.txt", "r");
	while (!feof(f1))
	{
		fscanf(f1, "%d %d", &temp1, &temp2);
		cur = createNode(temp1, temp2);
		appendNode(&a, &a_tail, cur);
	}
	printf("%10s : ", "POLY A");
	printList(a);

	while (!feof(f2))
	{
		fscanf(f2, "%d %d", &temp1, &temp2);
		cur = createNode(temp1, temp2);
		appendNode(&b, &b_tail, cur);
	}
	printf("%10s : ", "POLY B");
	printList(b);
	
	result = psub(&result, &result_tail, a, b);
	printf("%10s : ", "POLY A - B");
	printList(result);

	printf("\nafter erasing\n");


	erase(&a);
	erase(&b);
	erase(&result);

	printf("%10s : ", "POLY A");
	printList(a);
	printf("%10s : ", "POLY B");
	printList(b);
	printf("%10s : ", "POLY A - B");
	printList(result);

}