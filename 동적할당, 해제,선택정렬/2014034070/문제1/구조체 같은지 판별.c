#include <stdio.h>
#include <string.h>


typedef struct date
{
	int month;
	int day;
	int year;
}date;

typedef struct {
	char name[10];
	int age;
	float salary;
	date dob;
}humanBeing;

int main()
{
	humanBeing p1, p2;
	printf("input person1's name, age, and salary :\n");
	scanf("%s %d %f", p1.name, &p1.age, &p1.salary);

	printf("input person2's name, age, and salary :\n");
	scanf("%s %d %f", p2.name, &p2.age, &p2.salary);

	if(strcmp(p1.name, p2.name) == 0 && p1.age == p2.age && p1.salary == p2.salary) printf("same!\n");

	else printf("not same!");

	return 0;
}