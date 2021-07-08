#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int parent1[MAX_SIZE];
int parent2[MAX_SIZE];
int count[MAX_SIZE];

int simpleFind(int i)
{
	for (; parent2[i] >= 0; i = parent2[i]);
	return i;
}

void simpleUnion(int i, int j)
{
	parent2[j] = i;
}

void weightedUnion(int i, int j)
{
	int temp = parent1[i] + parent1[j];
	if (parent1[i] > parent1[j]) // j의 자식의 수가 많은 경우
	{
		parent1[i] = j;
		parent1[j] = temp;
	}
	else
	{
		parent1[j] = i;
		parent1[i] = temp;
	}
}

int collapsingFind(int i)
{
	int root, trail, lead;
	for (root = i; parent1[root] >= 0; root = parent1[root]);
	for (trail = i; trail != root; trail = lead)
	{
		lead = parent1[trail];
		parent1[trail] = root;
	}

	return root;
}


int collapsingFind2(int i)
{
	int root, trail, lead;
	for (root = i; parent2[root] >= 0; root = parent2[root]);
	for (trail = i; trail != root; trail = lead)
	{
		lead = parent2[trail];
		parent2[trail] = root;
	}

	return root;
}

void print1(int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%3d", parent1[i]);
	}
	puts("");
}
void print2(int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%3d", parent2[i]);
	}
	puts("");
}

void main()
{
	FILE* f;
	int input;
	int root1, root2;
	int find; int result;
	char func;
	

	f = fopen("in.txt", "r");
	
	printf("input size : "); scanf("%d", &input);
	puts("");
	input++;

	for (int i = 0; i < input; i++)
	{
		parent1[i] = -1;
		parent2[i] = -1;
	}

	printf("Weighted Union...\n");

	while (!feof(f))
	{
		fscanf(f, "%c", &func);
		printf("%3c", func);

		if (func == 'U')
		{
			fscanf(f, "%d %d", &root1, &root2);
			printf("%3d%3d : ", root1, root2);
			weightedUnion(root1, root2);
			print1(input);
		}

		else if (func == 'F')
		{
			fscanf(f, "%d", &find);
			printf("%3d : ", find);
			result = collapsingFind(find);
			print1(input);
			printf("%d의 root : %d", find, result);
		}
		
	}
	fclose(f);

	fopen("in.txt", "r");
	printf("\n\nSimple Union...\n");
	while (!feof(f))
	{
		fscanf(f, "%c", &func);
		printf("%3c", func);

		if (func == 'U')
		{
			fscanf(f, "%d %d", &root1, &root2);
			printf("%3d%3d : ", root1, root2);
			simpleUnion(root1, root2);
			print2(input);
		}

		else if (func == 'F')
		{
			fscanf(f, "%d", &find);
			printf("%3d : ", find);
			result = collapsingFind2(find);
			print2(input);
			printf("%d의 root : %d", find, result);
		}
	}
	



}