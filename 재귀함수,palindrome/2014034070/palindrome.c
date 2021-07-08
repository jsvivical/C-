#include <stdio.h>
#include <string.h>

int palindrom( char *str, int left, int right)
{
	if (left == right) return 1; //베이스 케이스
	if (left == right - 1 && str[left] == str[right]) return 1; //베이스케이스 : 문자열 개수 짝수일 때
	if (left < right) return palindrom(str, left + 1, right -1); //제너럴케이스

	else return 0;
		
}


int main()
{
	char word[20];
	int num;
	int start = 0;
	printf("문자열을 입력하세요 : ");
	scanf("%s", word);


	num = palindrom(word, start, strlen(word) - 1 );


	if(num == 1) printf("palindrom\n");
	else printf("not palindrom\n");



	return 0;
}