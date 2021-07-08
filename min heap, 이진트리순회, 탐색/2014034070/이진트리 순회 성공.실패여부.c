#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	struct tree* left;
	int data;
	struct tree* right;
}TREE;
TREE* prev; 

TREE* search(TREE* root, int key)
{
	if (!root) return NULL;
	if (key == root->data) return root;
	if (key < root->data) return search(root->left, key);
	return search(root->right, key);
}

TREE* modifiedSearch(TREE* root, int key)
{
	if (!root) return prev;
	if (key == root->data) return NULL;
	if (key < root->data)
	{
		prev = root;
		return modifiedSearch(root->left, key);
	}
	prev = root;
	return modifiedSearch(root->right, key);
}

void insert(TREE** node, int k)
{
	TREE* ptr,*temp = modifiedSearch(*node, k);
	if (temp || (*node))
	{
		ptr = malloc(sizeof(TREE));
		ptr->data = k;
		ptr->left = ptr->right = NULL;
		if (*node)
		{
			if (k < temp->data) temp->left = ptr;
			else
			{
				temp->right = ptr;
			}
		}
		else *node = ptr;
	}
	
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

void main()
{
	int temp;
	TREE* root = NULL;
	FILE* f; FILE* f2;
	f = fopen("in.txt", "r");
	fscanf(f, "%d", &temp);
	root = malloc(sizeof(TREE));
	root->data = temp;
	root->left = NULL;
	root->right = NULL;
	while (!feof(f))
	{
		fscanf(f, "%d", &temp);
		insert(&root, temp);

	}
	inorder(root);
	puts("");
	f2 = fopen("search.txt", "r");
	while (!feof(f2))
	{
		fscanf(f2, "%d", &temp);
		printf("%d : ", temp);
		if (!search(root, temp)) printf("X\n");
		else printf("O\n");
	}





}