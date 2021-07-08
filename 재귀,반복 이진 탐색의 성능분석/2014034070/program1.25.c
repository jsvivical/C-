#include <stdio.h>
#include <time.h>
#define SWAP(x,y,t) ((t) = (y),(x) = (y), (y) = (t))
#define MAX_SIZE 1001

void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[min]) min = j;
		}
		SWAP(list[i], list[min], temp);
	}
}

void main()
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;

	printf("     n  repetition   time\n");
	for (n = 0; n <= 1000; n += step)
	{
		long repetition = 0;
		clock_t start = clock();
		do {
			repetition++;
			for (i = 0; i < n; i++)
			{
				a[i] = n - 1;
			}
			sort(a, n);
		} while (clock() - start < 1000);

		duration = (double)(clock() - start) / CLOCKS_PER_SEC;
		duration /= repetition;
		printf("%6d %9d %f\n", n, repetition, duration);
		if (n == 100) step = 100;
	}

}