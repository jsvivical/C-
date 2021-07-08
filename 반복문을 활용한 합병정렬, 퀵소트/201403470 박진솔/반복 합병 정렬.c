#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101

typedef struct node
{
	char name[20];
	int key;
}element;



void merge(element initList[], element mergedList[], int i, int m, int n);
void mergePass(element initList[], element mergedList[], int n, int s);
void mergeSort(element a[], int n);

void merge(element initList[], element mergedList[], int i, int m, int n)
{
	int j, k, t;
	j = m + 1;
	k = i;

	while (i <= m && j <= n)
	{
		if (initList[i].key >= initList[j].key) mergedList[k++] = initList[i++];
		else mergedList[k++] = initList[j++];
	}
	if (i > m)
	{
		for (t = j; t <= n; t++) mergedList[t] = initList[t];
	}
	else
	{
		for (t = i; t <= m; t++) mergedList[k + t - i] = initList[t];
	}
}


void mergePass(element initList[], element mergedList[], int n, int s)
{
	int i, j;
	for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
	{
		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
	}
	if (i + s - 1 < n) merge(initList, mergedList, i, i + s - 1, n);
	else
	{
		for (j = i; j <= n; j++)
		{
			mergedList[j] = initList[j];
		}
	}

}

void mergeSort(element a[], int n)
{
	element extra[MAX_SIZE];
	int s = 1;
	while (s < n)
	{
		mergePass(a, extra, n, s);
		s *= 2;
		mergePass(extra, a, n, s);
		s *= 2;
	}
}

void print(element list[], int size)
{
	for (int i = 1; i <= size; i++)
	{
		printf("%10s : %5d\n", list[i].name, list[i].key);
	}
}

void main()
{
	FILE* f; int size;
	f = fopen("in.txt", "r");
	fscanf(f,"%d", &size);
	element *students;
	students = malloc(sizeof(element) * (size + 1));
	int i = 1;

	while (!feof(f))
	{
		fscanf(f, "%s %d", students[i].name, &students[i].key);
		i++;
	}

	printf("<<before merge sort>>\n");
	print(students, size);
	puts("");puts("");
	printf("<<after merge sort>>\n");
	mergeSort(students, size);
	print(students, size);
}