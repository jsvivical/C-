#include <stdio.h>
#include <stdlib.h>

#define FOPEN(f, name, mode) f = fopen(name,mode);\
							if(f == NULL){\
							printf("failed to open file\n");\
							exit(1);\
							}

#define MAX_TERMS 100

typedef struct terms
{
	int row;
	int col;
	int value;
}term;

void printmatrix(term* arr, int row, int col)
{
	int i, j, index = 1;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[index].row == i && arr[index].col == j)
			{
				printf("%3d", arr[index].value);
				index++;
			}
			else printf("%3d", 0);
		}
		puts("");
	}
}

void sub(term* a, term *b, term *result)
{
	int aIndex, bIndex, cIndex = 1;
	int ma[10][10] = { 0 }, mb[10][10] = { 0 }, mc[10][10] = { 0 };
	int i, j;
	for (i = 1; i <= a[0].value ; i++)
	{
		ma[a[i].row][a[i].col] = a[i].value;
	//	printf("%3d", ma[a[i].row][a[i].col]);
	}


	for (i = 1; i <= b[0].value; i++)
	{
		mb[b[i].row][b[i].col] = b[i].value;
		//printf("%3d", mb[b[i].row][b[i].col]);
	}
	
	for (i = 0; i < a[0].row; i++)
	{
		for (j = 0; j < a[0].col; j++)
		{
			mc[i][j] = ma[i][j] - mb[i][j];
			//printf("%3d", mc[i][j]);
			if (mc[i][j] != 0)
			{
				result[cIndex].row = i;
				result[cIndex].col = j;
				result[cIndex].value = mc[i][j];
			/*	printf("result[%d]. row, col, value : %d %d %d\n", 
					cIndex, result[cIndex].row, result[cIndex].col, result[cIndex].value);*/
				cIndex++;
			}
		}
	} 

	result[0].row = a[0].row;
	result[0].col = a[0].col;
	result[0].value = cIndex;
 }

void main()
{
	FILE* f1, *f2, *f3;
	term a[MAX_TERMS], b[MAX_TERMS], result[MAX_TERMS];
	int i = 0, m[10][10];
	FOPEN(f1, "m1.txt", "r");
	FOPEN(f2, "m2.txt", "r");

	while (!feof(f1))
	{
		fscanf(f1, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);
		//printf("check : %d %d %d\n", a[i].row, a[i].col, a[i].value);
		i++;
	}

	i = 0;

	while (!feof(f2))
	{
		fscanf(f2, "%d %d %d", &b[i].row, &b[i].col, &b[i].value);
		//printf("check : %d %d %d\n", b[i].row, b[i].col, b[i].value);
		i++;
	}
	
	sub(a, b,result);
	printmatrix(result, result[0].row, result[0].col);

	FOPEN(f3, "out.txt", "w");
	for (i = 0; i < result[0].value; i++)
	{
		fprintf(f3, "%d %d %d\n", result[i].row, result[i].col, result[i].value);
	}

	fclose(f1);
	fclose(f2);
	fclose(f3);

}