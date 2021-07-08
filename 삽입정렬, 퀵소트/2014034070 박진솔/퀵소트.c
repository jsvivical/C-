#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t = x), (x = y), (y = t))

typedef struct node
{
	char name[20];
	int key;
}element;

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
	for (i = 0; i < right; i++)
	{
		printf("%10s : %5d\n", list[i].name, list[i].key);
	}
}



void main()
{
	FILE* f;
	int left = 0; int right;
	element* students;
	int i = 0;
	f = fopen("in.txt", "r");
	fscanf(f, "%d", &right);

	students = malloc(sizeof(element) * (right));

	while (!feof(f))
	{
		fscanf(f, "%s %d", students[i].name, &students[i].key);
		i++;
	}

	printf("<<before quick sort>>\n");
	print(students, right);
	quickSort(students, left, right);
	printf("<<afterquick sort>>\n");
	print(students, right);


}