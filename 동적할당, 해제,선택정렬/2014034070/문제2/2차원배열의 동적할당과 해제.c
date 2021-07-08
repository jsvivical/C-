#include <stdio.h>
#include <stdlib.h>

void freeArray(int **arr, int row, int col);

int main()
{
	int row;
	int col;
	int** arr;
	int i , j;
	printf("row size :");
	scanf("%d" , &row);
	printf("column size : ");
	scanf("%d", &col);

	arr = (int**)malloc(sizeof(int*) * row);
	for(i = 0; i < row; i++)
	{
		arr[i] = (int *)malloc(sizeof(int)* col);
	}

	for(i = 0; i < row; i++)
	{
		for( j = 0; j < col; j++)
		{
			arr[i][j] = (i + 1)*(j + 1) -3;
			printf("%5d", arr[i][j]);
		}
		puts("");
	}

	freeArray(arr, row, col);

	return 0;

}
void freeArray(int** arr, int row, int col)
{
	int i, j;
	for(i = 0; i < row; i++) 
	{
		free(*(arr+i));
		printf("free(arr[%d])\n", i);
	}
	free(arr);
	printf("free(arr)\n");

}