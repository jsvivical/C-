#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	int* p;
	int count, temp;
	int i = 0;
	printf("input array size : ");
	scanf("%d", &count);
	p = (int*)malloc(sizeof(int) * count);
	int j, k;
	int sum = 0 , mean = 1;
	srand(time(NULL));
	

	while(i < count)
	{
		temp = rand() % 101;
		*(p + i) = temp;
		i++;
	}
	system("cls");


	for (j = 0; j < (count / 10) ; j++)
	{
		for (k = 0; k < 10; k++)
		{
			printf("%5d", *(p + (k + (10 * j))));
			sum = sum + *(p + (k + (10 * j)));
		}
		printf("\n");
	}
	mean = sum / count;

	printf("\nÆò±Õ : %d\n", mean);
	free(p);

	return 0;
}