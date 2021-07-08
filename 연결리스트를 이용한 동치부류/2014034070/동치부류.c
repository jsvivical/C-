#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node
{
	int data;
	struct node* next;
}NODE;

void main()
{
	bool out[MAX_SIZE];
	NODE* seq[MAX_SIZE];
	NODE* x, * y, * top;
	int i, j, n; int menu;
	FILE* f;
	char* filename[3] = { "e1.txt", "e2.txt" , "e3.txt" };

		printf("1.%s\n2.%s\n3.%s\n\n choose : ", filename[0], filename[1], filename[2]);
		scanf("%d", &menu);

		f = fopen(filename[menu - 1], "r");
		fscanf(f, "%d", &n); //사이즈

		for (i = 0; i <= n; i++)
		{
			out[i] = true;
			seq[i] = NULL;
		} //초기화

		while (!feof(f))
		{
			fscanf(f, "%d %d", &i, &j); //동치쌍 입력

			x = malloc(sizeof(NODE));
			x->data = j;
			x->next = seq[i];
			seq[i] = x;

			x = malloc(sizeof(NODE));
			x->data = i;
			x->next = seq[j];
			seq[j] = x;
		}

		for (i = 0; i < n; i++)
		{
			if (out[i])
			{
				printf("\nNew class : %5d", i);
				out[i] = false;
				x = seq[i];
				top = NULL;
				for (;;)
				{
					while (x)
					{
						j = x->data;
						if (out[j])
						{
							printf("%5d", j);
							out[j] = false;
							y = x->next;
							x->next = top;
							top = x;
							x = y;

						}
						else x = x->next;
					}
					if (!top) break;
					
					x = seq[top->data];
					top = top->next;
				
				}
			}
		}
}