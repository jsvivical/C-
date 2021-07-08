#include <stdio.h>
#include <stdlib.h>
#define FOPEN(f, name, mode) f = fopen(name,mode);\
							if(f == NULL){\
							printf("failed to open file\n");\
							exit(1);\
							}

#define MAX_TERMS 100
#define MAX_COL 10
#define MAX_ROW 10


typedef struct terms
{
	int row;
	int col;
	int value;
}term;

void fastTranspose(term a[], term b[])
{
	int rowTerms[MAX_COL], startingpos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;

	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;
	//rowTerms 설정
	if (numTerms > 0)
	{
		for (i = 0; i <= numCols; i++) rowTerms[i] = 0; //rowTerms의 요소들을 0으로 초기화
		for (i = 0; i <= numTerms; i++) rowTerms[a[i].col]++; //i의 열을 가지는 열의 요소를 카운트
	
		//startingpos 설정
		startingpos[0] = 1;
		for (i = 1; i < numCols; i++) startingpos[i] = startingpos[i - 1] + rowTerms[i - 1];

		//행과 열 바꾸고 b배열에 저장
		for (i = 1; i <= numTerms; i++)
		{
			j = startingpos[a[i].col]++;

			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}

	}

}

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

int main()
{
	FILE* f1, * f2;
	term a[MAX_TERMS], b[MAX_TERMS];
	term ta[MAX_TERMS], tb[MAX_TERMS];
	int i = 0, menu = 0,m[10][10];
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
	fastTranspose(a, ta);
	fastTranspose(b, tb);

	while (menu != 9999) 
	{
		
		printf("1. 실행예1 출력\n");
		printf("2. 실행예2 출력\n");
		printf("선택 : ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			system("cls");
			puts("Original matrix");
			printmatrix(a, a[0].row, a[0].col);
			puts("\n\n");

			puts("fast transpose");
			printmatrix(ta, ta[0].row, ta[0].col);
			puts("\n\n");
			break;
		case 2:
			system("cls");
			puts("Original matrix");
			printmatrix(b, b[0].row, b[0].col);
			puts("\n\n");

			puts("fast transpose");
			printmatrix(tb, tb[0].row, tb[0].col);
			puts("\n\n");
		}
	}

	puts("Original matrix");
	printmatrix(a, a[0].row, a[0].col);
	puts("\n\n");

	puts("fast transpose");
	printmatrix(ta, ta[0].row, ta[0].col);

}