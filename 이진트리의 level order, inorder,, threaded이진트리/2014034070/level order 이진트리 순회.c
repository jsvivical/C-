#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_QUEUE 101

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}TREE;


TREE* queue[MAX_SIZE_QUEUE];
int front = 0;
int rear = 0;


void addq(TREE* item)
{
	rear = (rear + 1) % MAX_SIZE_QUEUE;
	queue[rear] = item;
}

TREE* deleteq()
{
	front = (front + 1) % MAX_SIZE_QUEUE;

	return queue[front];
}



void levelorder(TREE* ptr)
{
	front = 0; rear = 0;
	if (!ptr) return;
	addq(ptr);
	for (;;)
	{
		ptr = deleteq();
		if (ptr)
		{
			printf("%3d", ptr->data);
			if (ptr->left) addq(ptr->left);
			if (ptr->right) addq(ptr->right);
		}
		else break;
	}
}

TREE* createNode(int* item)
{
	TREE* temp = malloc(sizeof(TREE));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = *item;
	(*item)++;


	return temp;
}



void inorder(TREE* ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		printf("%3d", ptr->data);
		inorder(ptr->right);
	}
}


void printq()
{
	int i = 0;
	for (i = front; i < rear; i++)
	{
		printf("%3d", queue[rear]->data);
	}
}
void construct(TREE** tree, int size)
{
	int i = 1; 
	*tree = createNode(&i);
	TREE* ptr = *tree;
	addq(ptr);
	for (; i <= size  ;)
	{

		ptr = deleteq();
		ptr->left = createNode(&i);
		addq(ptr->left);
		if (i > size) break;
		ptr->right = createNode(&i);
		addq(ptr->right);


	}
}

void main()
{
	TREE* root = NULL;
	int size;
	int i = 1;
	
	printf("input number : "); scanf("%d", &size);

	construct(&root, size);

	printf("level order : ");
	levelorder(root);
	puts("");

	printf("inorder : ");
	inorder(root);
	puts("");







}