#include <stdio.h>
#include <string.h>
#include "../../stackLib/stackLib.h"


#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)

int isOperator(char op) {

	if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^') {
		return 1;
	}

	return 0;

}

int checkPrecedence(char op) {

	switch(op) {

		case '+':
		case '-': {

			return 1;
		}
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}

	printf("something terribly wrong\n");
	return -1;

}

//more important thing you can do is store the postfix expression back to
//exp[], it is possible to do without any overhead, since it is processed char by char
// think about it
void infixToPostfix(char *exp, int size) {


	printf("parsing exp = %s\n",exp);
	int i = 0;
	struct myStack **st = creatStack();
	while(exp[i]) {

		//printf("parsing char %c\n",exp[i]);

		if(exp[i] == '(') {
			push(st,'(');
		}
		else if(exp[i] == ')') {
			
			while(!isStackEmpty(st)) {
				if(topOfStack(st) != '(') {
					printf("%c",(char)pop(st));
					
				}
				else
					break;

				if(isStackEmpty(st) && topOfStack(st) != '(') {
					printf("\ninvalid Expresion\n");
					return;
				}
			}

			pop(st);
		}
		else if(isOperator(exp[i])) {
		
			//printf("precedence of exp 		%c is %d\n",exp[i],checkPrecedence(exp[i]));	
			//printf("precedence of top of stack 	%c is %d\n",topOfStack(st),checkPrecedence(topOfStack(st)));
			
			while (!isStackEmpty(st) && (checkPrecedence(exp[i]) <= checkPrecedence(topOfStack(st)))) {

				printf("%c",(char)pop(st));
			}

			push(st,exp[i]);
		}
		else {
			//it must be an operand here. it will be printed directly
			printf("%c",exp[i]);
		}
		i++;
	}

	while(!isStackEmpty(st)) {

		if(topOfStack(st) == '(') {
			printf("\ninvalid Expression\n");
			return;
		}
		printf("%c",pop(st));
	}

	printf("\n");
}

int main() {

	char *exp = "a+b*(c^d-e)^(f+g*h)-i";//a+b*c^d+e";


	infixToPostfix(exp,strlen(exp));
	return 0;

}
