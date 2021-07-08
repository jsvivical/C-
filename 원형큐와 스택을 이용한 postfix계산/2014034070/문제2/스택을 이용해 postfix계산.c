#include <stdio.h>

typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
int stack[100];
char expr[100];
int top = -1;


int eval();
void push(int num);
int pop();
precedence getToken(char* symbol, int* n);




int eval()
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	token = getToken(&symbol, &n);
	while (token != eos)
	{
		if (token == operand) push(symbol - '0');
		else
		{
			op2 = pop();
			op1 = pop();
			switch (token)
			{
			case plus:
				push(op1 + op2);
				break;
			case minus:
				push(op1 - op2);
				break;
			case times :
				push(op1 * op2);
				break;
			case divide :
				push(op1 / op2);
				break;
			case mod:
				push(op1 % op2);
				break;
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();

}

int pop()
{
	return stack[top--];
}

void push(int num)
{
	stack[++top] = num;
}

precedence getToken(char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '*': return times;
	case '/': return divide;
	case '%': return mod;
	case '\n': return eos;
	default: return operand;
	}
}

void main()
{
	FILE * f = fopen("eval.txt", "r");
	fgets(expr, 100, f);
	while (!feof(f))
	{
		printf("\npostfix expression : ");
		fputs(expr, stdout);
		printf("evaluation result: ");
		printf("%d\n", eval(expr));
		fgets(expr, 100, f);
	}
	fclose(f);
}