#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}NODE;

NODE* createNode(int num)
{
	NODE* cur = (NODE*)malloc(sizeof(NODE));
	cur->data = num;
	cur->next = NULL;

	return cur;
}


void appendNode(NODE** head, NODE* cur) //앞에 계속 붙여나감
{
	NODE* temp;
	if (*head == NULL) // head가 NULL인 경우(리스트가 비었을 경우)
	{
		(*head) = cur;
	}

	else
	{
		temp = (*head);
		(*head) = cur;
		(*head)->next = temp;
	}
}
void printList(NODE* head)
{
	NODE* cur = head;
	while (cur)
	{
		printf("%3d", cur->data);
		cur = cur->next;
	}
}

int main()
{
	FILE* f;
	int num;
	f = fopen("list.txt","r");
	NODE *odd = NULL, *even = NULL , *cur;

	if (!f) {
		fprintf(stderr, "error01 : file open\n");
		exit(1);
	}
	while (!feof(f))
	{1
		fscanf(f, "%d", &num);
		if ((num % 2) == 0) //even 
		{
			cur = createNode(num);
			appendNode(&even, cur);
		}
		else //odd
		{
			cur = createNode(num);
			appendNode(&odd, cur);
		}
	}
	printf("odd list...\n");
	printList(odd);
	puts("");
	printf("even list...\n");
	printList(even);
	
}
