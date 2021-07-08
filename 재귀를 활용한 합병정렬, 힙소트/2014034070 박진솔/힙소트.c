#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
#define SWAP(x,y,t) ((t = x), (x = y), (y = t))
typedef struct node
{
	char name[20];
	int key;
}element;

void adjust(element a[], int root, int n);
void heapSort(element a[], int n);


void heapSort(element a[], int n)
{
	int i, j;
	element temp;
	for (i = 2 / n; i > 0; i--)
	{
		adjust(a, i, n);
	}
	for (i = n - 1; i > 0; i--)
	{
		SWAP(a[1], a[i + 1], temp);
		adjust(a, 1, i);
	}
}

void adjust(element a[], int root, int n)
{
	int rootkey, child;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;

	while (child <= n)
	{
		if ((child < n) && (a[child].key < a[child + 1].key)) child++;
		
		if (rootkey > a[child].key) break;
		else
		{
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
}


void main()
{
	FILE* f; int size;
	f = fopen("in.txt", "r");
	fscanf(f, "%d", &size);
	element* students;
	int* link;
	students = malloc(sizeof(element) * (size + 1));
	link = calloc(size, sizeof(int));
	int i = 1;



	while (!feof(f))
	{
		fscanf(f, "%s %d", students[i].name, &students[i].key);
		i++;
	}

	printf("<<before merge sort>>\n");
	for (int i = 1; i < size; i++)
	{
		printf("%10s : %5d\n", students[i].name, students[i].key);
	}
	puts(""); puts("");
	heapSort(students, size);
	printf("<<after merge sort>>\n");
	
	for (int i = 1; i < size; i++)
	{
		printf("%10s : %5d\n", students[i].name, students[i].key);
	}
}