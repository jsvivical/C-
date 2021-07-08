#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t = x), (x = y), (y = t))

typedef struct node
{
	char name[20];
	int key; 
}element;

void insert(element e, element a[], int i)
{
	a[0] = e;
	while(e.key < a[i].key)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;
}

void insertionSort(element a[], int n)
{
	int j;
	for (j = 2; j <= n; j++)
	{
		element temp = a[j];
		insert(temp, a, j - 1);
	}
}

void quickSort(element a[], int left, int right)
{
	int pivot, i, j;
	
	element temp;
	pivot = a[left].key;
	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = a[left].key;
		do 
		{
			do { i++; } while (a[i].key < pivot);
			do { j--; } while (a[j].key > pivot);
			if (i < j) SWAP(a[i], a[j], temp);
		} while (i < j);
		SWAP(a[left], a[j], temp);
		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);

	}
}


void print(element list[], int right)
{
	int i;
	for (i = 1; i < right + 1; i++)
	{
		printf("%10s : %5d\n", list[i].name, list[i].key);
	}
}



void main()
{
	FILE* f;
	int left = 0; int right;
	element* students;
	int i = 1;
	f = fopen("in.txt", "r");
	fscanf(f, "%d", &right);

	students = malloc(sizeof(element) * (right + 1));

	while (!feof(f))
	{
		fscanf(f, "%s %d", students[i].name, &students[i].key);
		i++;
	}

	printf("<<before insert sort>>\n");
	insertionSort(students, right);
	print(students, right);
	printf("<<after insert sort>>\n");
	print(students, right);


	free(students);
}