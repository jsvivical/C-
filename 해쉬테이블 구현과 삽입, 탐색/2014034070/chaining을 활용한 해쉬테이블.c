#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node* next;
}NODE;

NODE** bucket;

int hashFunction(int data, int bucketSize)
{
	return data % bucketSize;
}

NODE* create(int data)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->key = data;
	temp->next = NULL;


	return temp;
}

void insert(int index, NODE* new)
{
	NODE* temp = bucket[index];
	//printf("%5d, %5d\n", index, new->key);
	
	bucket[index] = new;
	new->next = temp;
}

NODE* search(int index, int searchnum)
{
	NODE* cur = bucket[index];
	while (cur)
	{
		if (cur->key == searchnum) break;
		cur = cur->next;
	}

	return cur;
}

void main()
{
	FILE* f;
	NODE* temp; NODE* find;
	int bucketSize; int input; int tempKey; int result; int searchnum;
	f = fopen("in.txt", "r");
	printf("input D : "); scanf("%d", &bucketSize);

	bucket = (NODE**)malloc(sizeof(NODE*) * bucketSize);
	for (int i = 0; i < bucketSize; i++)
		bucket[i] = NULL;
	while (!feof(f))
	{
		fscanf(f, "%d", &input);
		tempKey = hashFunction(input, bucketSize);

		temp = create(input);
		
		insert(tempKey, temp);

	}
	
	for (int i = 0; i < bucketSize; i++)
	{
		printf("[%d] ", i);
		NODE* cur = bucket[i];
		while (cur)
		{
			printf("%5d", cur->key);
			cur = cur->next;
		}
		puts("");
	}

	printf("input num(quit for 0) : "); scanf("%d", &searchnum);
	while (searchnum != 0)
	{
		result = hashFunction(searchnum, bucketSize);

		find = search(result, searchnum);

		if (find == NULL) printf("Fail\n");

		else printf("Success\n");


		printf("input num(quit for 0) : "); scanf("%d", &searchnum);
	}

	printf("Exit\n");

}
