#include <stdio.h>
#include <stdlib.h>

int hashFunction(int data, int bucketSize);
void insert(int *bucket, int data, int divisor);
int search(int key, int *ht, int divisor);

int hashFunction(int data, int divisor)
{
	return data % divisor;
}

void insert(int* bucket, int data, int divisor)
{
	int index = hashFunction(data, divisor);
	int temp = index;
	if (bucket[temp] == 0) bucket[temp] = data;
	else
	{
		while (bucket[temp] != 0)
		{
			temp++;
		}
		bucket[temp] = data;
	}

}

int search(int key, int* ht, int divisor)
{
	int homeBucket, currentBucket;
	homeBucket = hashFunction(key, divisor);
	for (currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket] != key; )
	{
		currentBucket = (currentBucket + 1) % divisor;
		if (currentBucket == homeBucket) return 0;
	}
	if (ht[currentBucket] == key) return ht[currentBucket];

	return NULL;
}

void main()
{
	FILE* f;
	int temp;
	int bucketSize;
	int divisor;
	int* bucket;
	int input; int result;

	printf("input bucket size : "); scanf("%d", &bucketSize);
	printf("input D : "); scanf("%d", &divisor);

	bucket = calloc(bucketSize,sizeof(int));

	f = fopen("in.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%d", &temp);
		insert(bucket, temp, divisor);
	}

	for (int i = 0; i < bucketSize; i++)
	{
		printf("[%d] : %5d\n", i,bucket[i]);
	}

	printf("input num(quit for 0) : "); scanf("%d", &input);
	while (input != 0)
	{
		result = search(input, bucket, divisor);
		if (result == 0) printf("Fail\n");
		else printf("Success\n");


		printf("input num(quit for 0) : "); scanf("%d", &input);
	}

	printf("Exit\n");



}