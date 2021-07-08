#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* prev;
	int data;
	struct node* next;
}NODE;

void insert(NODE**, NODE*);
void delete(NODE**, NODE*);
void printList();
NODE* createNode(int item);
void appendNode(NODE** first, NODE** last, NODE* cur);
void rprint();
NODE* header;

int main()
{
	FILE* f = fopen("in.txt", "r");
	int temp; int input;
	NODE* new; NODE* p;
	NODE* first = NULL; NODE* last = NULL;
	header = malloc(sizeof(NODE));
	header->next = header;
	header->prev = header;



	while (!feof(f))
	{
		fscanf(f, "%d", &temp);
		new = createNode(temp);
		appendNode(&first, &last, new);
	}
	printf("print List\n");
	printList();

	printf("print inversed List\n");
	rprint();

	printf("input number : "); scanf("%d", &input);
	p = first;
	new = createNode(input);

	if (first->data > input)
	{
		new->next = p;
		p->prev = new;
		header->next = new;
	}

	else if  (last->data < input) appendNode(&first, &last, new);

	else
	{
		while (p->data <= input)
		{
			p = p->next;
		}
		insert(&p, new);


	}
	rprint();
	printList();




	fclose(f);
}

NODE* createNode(int item)
{
	NODE* temp = malloc(sizeof(NODE));
	temp->data = item;
	temp->prev = NULL;
	temp->next = NULL;

	return temp;
}
void insert(NODE** node, NODE* new)
{
	new->prev = (*node);
	new->next = (*node)->next;
	(*node)->next->prev = new;
	(*node)->next = new;
}


void printList()
{
	NODE* p = header->next;
	while (p != header->prev)
	{
		printf("<%3d> ", p->data);
		p = p->next;
	}
	printf("<%3d> ", p->data);

	puts("");
	puts("");
}


void rprint()
{
	NODE* p = header->prev;
	while (p != header->next)
	{
		printf("<%3d> ", p->data);
		p = p->prev;
	}
	printf("<%3d> ", p->data);
	puts("");
	puts("");
}


void appendNode(NODE** first, NODE** last, NODE* cur)
{
	if (!(*first))
	{
		(*first) = cur;
		(*last) = (*first);
		(*first)->prev = header;
	}
	else
	{
		(*last)->next = cur;
		cur->prev = (*last);
		(*last) = (*last)->next;
	}
		
	header->next = (*first);
	header->prev = (*last);


}