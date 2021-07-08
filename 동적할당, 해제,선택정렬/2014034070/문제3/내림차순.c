#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))


int main()
{
	int* arr;
	int size, max,i, j,temp;
	FILE *f;

	f = fopen("in.txt" , "r");

	if(f == NULL) 
	{
		printf("error\n");
		exit(1);
	}

	fscanf(f, "%d", &size);

	arr = (int*)malloc(sizeof(int) * size);
	i = 0;

	while(!feof(f))
	{
		fscanf(f, "%d", &arr[i]);
		i++;
	}
	
	for(i = 0; i < size - 1; i++)
	{
		max = i;
		for(j = i + 1; j < size; j++)
		{
			if(arr[j] < arr[max]) max = j;
			SWAP(arr[i], arr[max], temp);
		}
	}

	for(i = 0; i < size; i++)
	{
		printf("%5d", arr[size - 1 - i]);
	}
	puts("");
	return 0;

}