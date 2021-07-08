#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 6

typedef struct path
{
	int key;
	struct path* next;
}PATH;

void shortesPath(int v, int cost[][MAX_VERTICES], int distance[], int n, bool found[]);
int choose(int distance[], int n, bool found[]);
PATH* path[MAX_VERTICES];

void shortestPath(int v, int cost[][MAX_VERTICES], int distance[], int n, bool found[])
{
	int i, u, w; int k = 1; int j = 0;

	for (i = 0; i < n; i++)
	{
		found[i] = false;
		distance[i] = cost[v][i];
	}
	found[v] = true;
	distance[v] = 0;
	u = choose(distance, n, found);
	path[v]->next = path[u];
	for (i = 0; i < n - 2; i++)
	{
		u = choose(distance, n, found);
		found[u] = true;
		printf("%d", u);
		for (w = 0; w < n; w++)
		{
			if (!found[w])
			{
				if (distance[u] + cost[u][w] < distance[w])
				{
					distance[w] = distance[u] + cost[u][w];
					path[u]->next = path[w]; 
				}
			}
		}
	}
}





int choose(int distance[], int n, bool found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;



	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void main()
{
	int input;

	int distance[MAX_VERTICES];
	bool found[MAX_VERTICES];

	int cost[][MAX_VERTICES] =
	{
		{0, 50, 45, 10 , 1000, 1000},
		{1000, 0 , 10, 15, 1000, 1000},
		{1000, 1000, 0, 1000, 30, 1000},
		{20, 1000, 1000, 0, 15, 1000},
		{1000, 20, 35, 1000, 0, 1000},
		{1000, 1000, 1000, 1000, 3, 0},
	};
	printf("input start node : "); scanf("%d", &input);
	printf("cost : Path from vertex : %d\n", input);

	for (int i = 0; i < MAX_VERTICES; i++)
	{
		distance[i] = 1000;
		found[i] = false;
		path[i] = malloc(sizeof(PATH));
		path[i]->next = NULL;
		path[i]->key = i;

	}

	shortestPath(input, cost, distance, MAX_VERTICES, found);

	for (int i = 0; i < MAX_VERTICES; i++)
	{
		PATH* p = path[input];
		if (distance[i] == 1000) printf("[to %d] No path\n", i);
		else if (distance[i] == 0);
		else {
			printf("[to %d] Length : %d Path : ", i, distance[i], input);
			
			while (p->key != i)
			{
				printf("(%3d)", p->key);
				p = p->next;
			}

			printf("(%3d)", i);
		puts("");
		}

	}

}