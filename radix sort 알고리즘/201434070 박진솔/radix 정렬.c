#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 10000



int digit(int a, int index, int base)
{
	int temp[4];
	temp[0] = a / 1000;
	temp[1] = (a - (temp[1] * 1000)) / 100;
	temp[2] = (a - (temp[1] * 1000) - (temp[2] * 100)) / 10;
	temp[3] = (a - (temp[1] * 1000) - (temp[2] * 100) - temp[3] * 10);

	return temp[index];

}

int radixSort(int a[], int link[], int d, int r, int n)
{
	int* front, * rear;
	int i, bin, current, first, last;
	front = malloc(sizeof(int) * r);
	rear = malloc(sizeof(int) * r);
	first = 1;
	for (i = 1; i < n; i++) link[i] = i + 1;
	link[n] = 0;

	for (i = d - 1; i >= 0; i--)
	{
		for (bin = 0; bin < r; bin++) front[bin] = 0;

		for (current = first; current; current = link[current])
		{
			bin = digit(a[current], i, r);
			if (front[bin] == 0) front[bin] = current;
			else link[rear[bin]] = current;
			rear[bin] = current;
		}

		for (bin = 0; !front[bin]; bin++);
		first = front[bin];
		last = rear[bin];

		for (bin++; bin < r; bin++)
		{
			if (front[bin])
			{
				link[last] = front[bin];
				last = rear[bin];
			}
		}
		link[last] = 0;
	}

	return first;

}

void main()
{
	int size;
	int range;
	int* array; int* link;
	int r = 10;

	printf("Input size : ");
	scanf("%d", &size);
	array = malloc(sizeof(int) * size + 1);
	link = malloc(sizeof(int) * size + 1);
	printf("Input range(10 ~ 9999) : ");
	scanf("%d", &range);

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % range + 10;
	}

	printf("Before radis sort....\n");
	for (int i = 0; i < size; i++)
	{
		printf("%5d", array[i]);
	}
	puts("");

	int num = digit(7389, 1, 10);
	printf("%5d", num);



	//radixSort(array, link, 3, 10, size);

	//printf("Before radis sort....\n");

	//for(int i = link[0]; i != 0; i = link[i])
	//	printf("%5d", link[i]);

	
}