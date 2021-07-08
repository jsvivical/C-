#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}TREE;

TREE* root;
TREE* createNode(int item);
void inorder(TREE* ptr);
void Lchild(TREE* p, int item);
void Rchild(TREE* p, int item);


TREE* createNode(int item)
{
	TREE* node;
	node = malloc(sizeof(TREE));
	(node)->left = NULL;
	(node)->right = NULL;
	(node)->data = item;

	return node;
}

void inorder(TREE* ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		printf("%5d", ptr->data);
		inorder(ptr->right);
	}
}

void child(TREE * p, int item)
{
	TREE* cur1, *cur2;

	if (item  < 100 && item < 100)
	{
		cur1 = createNode(item * 2);
		 cur2 = createNode(item * item);

		if (item * 2 <= 100) p->left = cur1;
		if ((item * item) <= 100) p->right = cur2;

		child(p->left, item * 2);
		child(p->right, item * item);
	}
}





void main()
{
	int item;
	int temp1; int temp2;
	TREE* cur1; TREE* cur2; TREE* p1, *p2;
	temp1 = 0; temp2 = 0;
	printf("input data : ");
	scanf("%d", &item);
	root = createNode(item);
	p1 = root;
	p2 = root;

	child(p1, item);


	inorder(root);



}