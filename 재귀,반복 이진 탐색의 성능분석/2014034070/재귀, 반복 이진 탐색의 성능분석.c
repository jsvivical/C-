#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#define REPETITION 500000

#define COMPARE(x ,y) (((x) < (y))? -1:((x) == (y))? 0 : 1)

int iter_binserach(int[], int, int, int);
int recur_binsearch(int[], int, int, int);
void setarray(int[],int);

void main()
{
	clock_t iter_start, iter_finish;
	clock_t recur_start, recur_finish;
	long repetition = 0;
	double iter_elapsed, recur_elapsed;
	int list[SIZE];
	int searchnum, left = 0, right =SIZE - 1;
	int size = SIZE;
	setarray(list, SIZE);
	printf("찾을 숫자 : ");
	scanf("%d", &searchnum);
	iter_start = clock();
	do 
	{
		iter_binsearch(list, searchnum, left, right);
		repetition++;
	} while (repetition <= REPETITION);
	iter_finish = clock();

	iter_elapsed = ((double)(iter_finish)-(double)(iter_start)) / CLOCKS_PER_SEC;
	printf("iterative binary search 결과 : %f\n", iter_elapsed * 1000.0F);

	printf("찾을 숫자 : ");
	scanf("%d", &searchnum);
	repetition = 0;
	recur_start = clock();
	do
	{
		recur_binsearch(list, searchnum, left, right);
		repetition++;
	} while (repetition <= REPETITION);
	recur_finish = clock();
	recur_elapsed = ((double)(recur_finish)-(double)(recur_start)) / CLOCKS_PER_SEC;
	printf("recursive binary search 결과 : %f\n", recur_elapsed * 1000.0F);

}

int iter_binsearch(int list[], int searchnum, int left, int right)
{
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum))
		{
		case -1 :
			left = middle + 1;
			break;
		case 0:
			return middle;
		case 2:
			right = middle - 1;
		}
	}
}int recur_binsearch(int list[], int searchnum, int left, int right)
{
	int middle;
	
	if (left <= right)
	{
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum))
		{
		case -1:
			return recur_binsearch(list, searchnum, middle + 1, right);
		case 0:
			return middle;
		case 1:
			recur_binsearch(list, searchnum, left, middle - 1);
		}
	}
	return -1;
}

void setarray(int list[], int n)
{
	for (int i = 0; i < SIZE; i++)
	{
		list[i] = i;
	}
}