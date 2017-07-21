#include <stdio.h>
#include <string.h>



#include "../../stackLib/stackLib.h"

#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)


int isOperator(int op) {

	if(op == '+' || 
	   op == '-' || 
	   op == '*' || 
 	   op == '/' || 
	   op == '^'	) {

		return 1;
	}

	return 0;
}

int evaluateExp(int a, int b, int operator) {

	switch(operator) {

		case '+' : {
			return a+b;
		}
		case '-' : {
			return a-b;
		}
		case '*' : {
			return a*b;
		}
		case '/' : {
			return a/b;
		}
		case '^' : {
			return a^b;
		}
	}
}

void postFixEvaluation(char *exp, int len) {

	printf("evaluating expression  %s\n",exp);
	int i = 0;
	struct myStack **st = creatStack();
	//struct myStack **operatorSt = creatStack();

	while(exp[i]) {

		if(!isOperator(exp[i])) {
			push(st,(exp[i]-'0'));
		}
		else {
	
			int op1 = 0;
			int op2 = 0;

			if(sizeOfStack(st) >= 2) {
				op1 = pop(st);
				op2 = pop(st);
			}
			else {
				printf("Invalide posfix expression\n");
				return;
			}
	
			push(st,evaluateExp(op1,op2,exp[i]));
		}
		i++;
	}

	printf("result = %d\n",topOfStack(st));
}

int main() {

	char *exp = "34*78++"; //This is a postfix expression

	postFixEvaluation(exp,strlen(exp));
	return 0;
}
