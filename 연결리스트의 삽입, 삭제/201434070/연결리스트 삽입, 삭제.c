#include <stdio.h>
#include <stdlib.h>

typedef struct node {
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


void appendNode(NODE** head, NODE** tail,NODE* cur) //앞에 계속 붙여나감
{
	NODE* temp;
	if (*head == NULL) // head가 NULL인 경우(리스트가 비었을 경우)
	{
		(*head) = cur;
		(*tail) = (*head);
	}

	else
	{
		(*tail)->next = cur;
		(*tail) = (*tail)->next;
	}
}
void printList(NODE* head)
{
	NODE* cur = head;
	while (cur)
	{
		printf("%5d", cur->data);
		cur = cur->next;
	}
}


void insert(NODE** head,NODE * prev ,NODE* cur) // cur : 삽입하려는 노드 짝수인 경우 적절한 위치에 삽입되어야 함
{
	NODE* temp;
	if (prev == NULL)
	{
		temp = (*head);
		*head = cur;
		cur->next = temp;
	}

	else
	{
		printf("check\n");
		temp = prev->next;
		prev->next = cur;
		cur->next = temp;
	}
	
}


void delete(NODE** head, NODE* trail) //trail은 지우려고 하는 노드의 선행노드
{
	NODE* temp;
	if (trail == (*head))
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	else
	{
		temp = trail->next; //temp는 지우는 노드
		trail->next = temp->next;
		free(temp);
	}
	
}

int main()
{
	int x, num;
	NODE* head = NULL, * tail = NULL, * cur, *p = NULL;
	FILE* f;
	f = fopen("list.txt", "r");
	if (!f) {
		fprintf(stderr, "error01 : file open\n");
		exit(1);
	}
	while (!feof(f))
	{
		fscanf(f, "%d", &num);
		cur = createNode(num);
		appendNode(&head, &tail, cur);
	}
	printf("현재 리스트 : \n");
	printList(head);


	do {
		printf("\ninput number : ");
		scanf("%d", &x);
		cur = createNode(x);
		p = head;
		switch (x % 2)
		{
		case 0: //even
			if (head->data >= x) insert(&head, NULL, cur);

			else
			{
				while (p->next->data <= x)
				{
					p = p->next;
				}
				insert(&head, p, cur);
			}
			printList(head);
			break;

		case 1: // odd

			if (head->data == x)
			{
				delete(&head, head);
				printList(head);
			}
			else
			{	
				while (p->next)
				{
					if (p->next->data == x) 
					{
						delete(&head, p);
						break;
					}
					p = p->next;
				}
				if (p ->data != x) printf("no key!\n %d", x);
				printList(head);
			}

			break;
		}
	} while (x != -1);
}