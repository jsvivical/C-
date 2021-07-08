#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	bool leftT;
	struct node* left;
	char data;
	struct node* right;
	bool rightT;
}TREE;
typedef TREE* TREEPOINTER;

TREE* insucc(TREE* tree)
{
	TREE* temp;
	temp = tree->right;
	if (!tree->rightT)
	{
		while (!temp->leftT) temp = temp->left;
	}
	return temp;
}

void tInorder(TREE* tree)
{
	TREE* temp = tree;
	for (;;)
	{
		temp = insucc(temp);
		if (temp == tree) break;
		printf("%3c", temp->data);
	}
}

TREE* createNode(char item)
{
	TREE* temp;
	temp = malloc(sizeof(TREE));
	temp->data = item;
	temp->right = NULL;
	temp->left = NULL;
	temp->leftT = false;
	temp->rightT = false;


	
}

void main()
{
	TREEPOINTER root, A, B, C, D, E, F, G, H, I;

	root = createNode('\0');
	//노드생성
	{
		A = createNode('A');
		B = createNode('B');
		C = createNode('C');
		D = createNode('D');
		E = createNode('E');
		F = createNode('F');
		G = createNode('G');
		H = createNode('H');
		I = createNode('I');
	}
	root->left = A;
	root->right = root;
	//연결
	{
		A->left = B;
		A->right = C;

		B->left = D;
		B->right = E;

		D->left = H;
		D->right = I;


		C->left = F;
		C->right = G;
	}

	//스레드
	{
		H->leftT = true;
		H->rightT = true;
		H->left = root;
		H->right = D;

		I->leftT = true;
		I->rightT = true;
		I->left = D;
		I->right = B;

		E->leftT = true;
		E->rightT = true;
		E->left = B;
		E->right = A;

		F->leftT = true;
		F->rightT = true;
		F->left = A;
		F->right = C;

		G->leftT = true;
		G->rightT = true;
		G->left = C;
		G->right = root;
	}
	tInorder(root);



}