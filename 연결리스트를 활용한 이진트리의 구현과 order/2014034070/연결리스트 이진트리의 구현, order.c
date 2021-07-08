#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node* left;
	struct node* right;
}TREE;

TREE* root = NULL;

void createNode(TREE** node, char item)
{
	*node = malloc(sizeof(TREE));
	(*node)->left = NULL;
	(*node)->right = NULL;
	(*node)->data = item;
}



void inorder(TREE* ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		printf("%3c", ptr->data);
		inorder(ptr->right);
	}
}

void preorder(TREE* ptr)
{
	if (ptr)
	{
		printf("%3c", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(TREE* ptr)
{
	if (ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%3c", ptr->data);
	}
}

void main()
{
	TREE* A, *B, *C, *D, *E, *F, *G, *H, *I, *J;
	{ //노드생성
		createNode(&A, 'A');
		createNode(&B, 'B');
		createNode(&C, 'C');
		createNode(&D, 'D');
		createNode(&E, 'E');
		createNode(&F, 'F');
		createNode(&G, 'G');
		createNode(&H, 'H');
		createNode(&I ,'I');
		createNode(&J, 'J');
	}
	//트리연결

	{
		A->left = B;
		A->right = C;
		B->left = D;
		B->right = E;
		C->left =F ;
		D->left = G;
		E->left =H;
		E->right = I;
		F->left = J;
	}

	printf("inorder : ");
	inorder(A);
	puts("");

	printf("preorder : ");
	preorder(A);
	puts("");

	printf("postorder : ");
	postorder(A);
	puts("");



}