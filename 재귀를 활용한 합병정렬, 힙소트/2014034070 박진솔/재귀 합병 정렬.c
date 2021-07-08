#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

typedef struct node
{
	char name[20];
	int key;
}element;



int listMerge(element a[], int link[], int start1, int start2);
int rmergeSort(element a[], int link[], int left, int right);


int listMerge(element a[], int link[], int start1, int start2)
{
	int last1, last2, lastResult = 0;
	for (last1 = start1, last2 = start2; last1 && last2; )
	{
		if (a[last1].key >= a[last2].key)
		{
			link[lastResult] = last1;
			lastResult = last1; 
			last1 = link[last1];
		}
		else
		{
			link[lastResult] = last2;
			lastResult = last2;
			last2 = link[last2];
		}
	
	}
	if (last1 == 0) link[lastResult] = last2;
	else link[lastResult] = last1;
	return link[0];
}




int rmergeSort(element a[], int link[], int left, int right)
{
	if (left >= right) return left;
	int mid = (left + right) / 2;

	return listMerge(a, link, rmergeSort(a, link, left, mid), rmergeSort(a, link, mid + 1, right));
}

void print(element list[],int link[] ,int size)
{
	
	int i = link[0];
	while (link[i] != 0)
	{
		printf("%10s : %5d\n", list[i].name, list[i].key);
		i = link[i];
	}

}
void main()
{
	FILE* f; int size;
	f = fopen("in.txt", "r");
	fscanf(f, "%d", &size);
	element* students;
	int* link;
	students = malloc(sizeof(element) * (size + 1));
	link = calloc(size+1, sizeof(int));

	int i = 1;
	while (!feof(f))
	{
		fscanf(f, "%s %d", students[i].name, &students[i].key);
		i++;
	}

	printf("<<before merge sort>>\n");
	for (int i = 1; i <= size; i++)
	{
		printf("%10s : %5d\n", students[i].name, students[i].key);

	}
	puts(""); puts("");
	printf("<<after merge sort>>\n");
	rmergeSort(students, link, 1, size);
	 /*i = link[0];
	while (link[i] != 0)
	{
		printf("%10s : %5d\n", students[i].name, students[i].key);
		i = link[i];
	}
	*/
	for (i = link[0]; i != 0; i = link[i])
	{
		printf("%10s : %5d\n", students[i].name, students[i].key);
	}
}