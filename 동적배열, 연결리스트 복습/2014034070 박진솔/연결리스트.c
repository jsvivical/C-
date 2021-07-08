#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char name[20];
	int result;
	struct Student* next;
}Student;


int main(void)
{
	FILE* f;
	Student* head = NULL, * tail = NULL, *cur = NULL;
	Student temp;
	int standard;
	int count = 0;
	f = fopen("result.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%*d %*s %s %d\n", temp.name, &temp.result);
		
		if (head == NULL)
		{
			head = (Student*)malloc(sizeof(Student));
			tail = head;
		}
		else
		{
			tail->next = (Student*)malloc(sizeof(Student));
			tail = tail->next;
		}
		strcpy(tail->name, temp.name);
		tail->result = temp.result;
		tail->next = NULL;
	}

	cur = head;

	printf("기준 총점 입력 : ");
	scanf("%d", &standard);
	printf("총점 %d 이상 : ",standard);
	while (cur != NULL)
	{
		if (cur->result > standard) 
		{
			printf("%s ", cur->name);
			count++;
		}
		cur = cur->next;
	}
	if (count == 0) printf("없습니다.");

	while (head == NULL)
	{
		cur = head;
		head = head->next;
		free(cur);
	}
	tail = NULL;

	return 0;
}