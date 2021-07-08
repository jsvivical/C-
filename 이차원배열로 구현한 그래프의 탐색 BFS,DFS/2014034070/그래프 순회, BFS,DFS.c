#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 101

int** matrix;
bool visited[MAX_SIZE];
int queue[MAX_SIZE];
int front; int rear;


void dfs(int row);
void bfs(int row, int col);



void addq(int i)
{
	queue[rear++] = i;
}

int deleteq()
{
	return queue[front++];
}

void dfs(int from)
{
	int to; //다음 노드 숫자
	visited[from] = true;
	printf("%3d", from);
	for (int i = 0; i < 9; i++)
	{
		if (matrix[from][i] == 1 && visited[i] == false) dfs(i);
	}


}

void bfs(int from)
{
	int node;
	front = rear = 0;
	printf("%3d", from);
	visited[from] = true;
	addq(from);

	while (front != rear)
	{
		node = deleteq();
		for (int i = 0; i < 9; i++)
		{
			if (matrix[node][i] == 1 && visited[i] == false)
			{
				printf("%3d", i);
				addq(i);
				visited[i] = true;
			}
		}
	}


}



void main()
{
	int size;
	FILE* f;
	int input;
	f = fopen("in.txt", "r");
	fscanf(f, "%d", &size);
	matrix = malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++)
	{
		matrix[i] = malloc(sizeof(int) * size);
		visited[i] = false;
	}


	//초기화
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fscanf(f, "%d", &matrix[i][j]);
		}
	}
	

	//for (int i = 0; i < size; i++)
	//{
	//	for (int j = 0; j < size; j++)
	//	{
	//		printf("%3d", matrix[i][j]);

	//	}
	//	puts("");
	//}
	printf("DFS...\n");
	printf("input starting number : "); scanf("%d", &input);
	while (input != -1) 
	{
		dfs(input);
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		puts("");
		printf("input starting number : "); scanf("%d", &input);
	}



	for (int i = 0; i < size; i++)
	{
		visited[i] = false;
		queue[i] = 0;
	}

	printf("BFS...\n");
	printf("input starting number : "); scanf("%d", &input);
	while (input != -1)
	{
		bfs(input);
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		puts("");
		printf("input starting number : "); scanf("%d", &input);
	}


}
