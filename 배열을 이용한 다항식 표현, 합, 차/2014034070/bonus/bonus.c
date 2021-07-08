#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 1001
typedef struct polynomial
{
	float coef;
	int expon;
}polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;



int compare(int x, int y)
{
	if(x < y) return -1;
	else if(x == y) return 0;
	else if (x > y) return 1;
}


void printexpression(int sa, int fa)
{

	int i;
	
	for(i = sa; i < fa; i++)
	{
		printf("%.3fx^%d + ", terms[i].coef, terms[i].expon);
	}
	if(terms[fa].coef == 0 && terms[fa].expon == 0) printf("0\n");
	else
	{
		printf("%.3f^x%d", terms[fa].coef, terms[fa].expon);
		puts("");
	}
}

void attach(float c, int e)
{
	if(avail >= MAX_TERMS)
	{
		fprintf(stderr, "to many terms in the polynomials\n");
		exit(1);
	}
	terms[avail].coef = c;
	terms[avail].expon = e;
	avail++;
	
}

void psub(int sa, int fa, int sb, int fb, int* sd, int* fd)
{
	float coefficient;
	*sd = avail;
	while(sa <= fa && sb <= fb)
	{
		switch (compare(terms[sa].expon, terms[sb].expon))
		{
		case -1 :
			//printf("check-1\n");
			attach(-terms[sb].coef, terms[sb].expon);
			sb++;
			break;
		case 0:
			
			coefficient = terms[sa].coef - terms[sb].coef;
			sa++;
			sb++;
			break;
			if(coefficient)
			{
				attach(coefficient , terms[sa].expon);
				sa++;
				sb++;
				break;
			}
		case 1:
			//printf("check1\n");
			attach(terms[sa].coef, terms[sa].expon);
			sa++;
		}
	}
	for( ; sa <= fa; sa++) attach(terms[sa].coef, terms[sa].expon);
	for( ; sb <= fb; sb++) attach(-terms[sb].coef, terms[sb].expon);

	*fd = avail -1;
}


int main()
{
	FILE* f = NULL;
	int sa = 0, fa = 0, sb = 0, fb = 0, sd =0, fd = 0;
	f = fopen("a.txt", "r");
	if(!f)
	{
		printf("파일열기 실패\n");
		exit(1);
	}

	while(!feof(f))
	{
		fscanf(f,"%f %d", &terms[avail].coef, &terms[avail].expon);
		avail++; 	
	}
	fa = avail -1;
	fclose(f);

	sb = avail;
	fb = sb;
	f = fopen("b.txt", "r");
	if(!f)
	{
		printf("파일열기 실패\n");
		exit(1);
	}
	while(!feof(f))
	{
		fscanf(f,"%f %d", &terms[avail].coef, &terms[avail].expon);
		avail++; 	
	}
	fb = avail -1;
	avail++;
	printf("A(x) : " );
	printexpression(sa,fa);
	printf("B(x) : " );
	printexpression(sb,fb);
	psub(sa, fa, sb, fb, &sd, &fd);
	printf("C(x) : " );
	printexpression(sd,fd);



}