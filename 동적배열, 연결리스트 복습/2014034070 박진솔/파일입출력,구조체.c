#include <stdio.h>
#include <string.h>

typedef struct Student
{
	char name[20];
	int score1;
	int score2;
	int result;
} Student;

int main(void)
{
	Student s[5];
	FILE* f1 = fopen("score.txt", "r");
	FILE* f2 = fopen("result.txt", "w");
	Student temp;
	int rank = 1;
	int i = 0, j = 0, k;
	
	while(!feof(f1))
	{
		fscanf(f1, "%s %d %d\n", temp.name, &temp.score1, &temp.score2);
		strcpy(s[i].name, temp.name);
		s[i].score1 = temp.score1;
		s[i].score2 = temp.score2;
		s[i].result = s[i].score1 + s[i].score2;
		//printf("%s %d %d %d\n", s[i].name, s[i].score1, s[i].score2, s[i].result);
		i++;
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++) 
		{
			if (s[j].result < s[i].result)
			{
				strcpy(temp.name, s[i].name);
				temp.score1 = s[i].score1;
				temp.score2 = s[i].score2;
				temp.result = s[i].result;

				strcpy(s[i].name, s[j].name);
				s[i].score1 = s[j].score1;
				s[i].score2 = s[j].score2;
				s[i].result = s[j].result;

				strcpy(s[j].name, temp.name);
				s[j].score1 = temp.score1;
				s[j].score2 = temp.score2;
				s[j].result = temp.result;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d µî %s %d\n", i+ 1,s[i].name, s[i].result);
		fprintf(f2, "%d µî %s %d\n", (i + 1), s[i].name, s[i].result);
	}


	
	return 0;
}