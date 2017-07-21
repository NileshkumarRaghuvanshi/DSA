#include <stdio.h>
#include <string.h>
#include "../../stackLib/stackLib.h"


#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)


int checkForMatchingPair(char a, char b) {


	if((a == '{' && b == '}')|| (a == '[' && b ==']') || (a == '(' && b == ')'))
		return 1;
	else 
		return 0;

}


int checkBalancedParanthesis(char *str, int size) {

	int i =0;
	printf("checking paranthessis for %s\n",str);
	
	struct myStack **st = createStack();
	
	while(str[i]) {

		if(str[i] == '{' || str[i] == '[' || str[i] == '(') {
			push(st,str[i]);
		}
		else if(str[i] == '}' || str[i] == ']' || str[i] == ')') {
			if(!isStackEmpty(st)) {
				if(!checkForMatchingPair(pop(st),str[i])) {
					printf("No matching pair\n");
					return 0;
				}
			}
			else {
				printf("stack is empty and there is closing bracket\n");
				return 0;
			}
		}
		i++;
	}

	if(isStackEmpty(st))
		return 1;
	else {
		printf("stack is not empty\n");
		return 0;
	}

}


int main() {

	char *str = "({}{[([{}])]}){}{}";
	int ret = checkBalancedParanthesis(str,strlen(str));

	if(ret)
		printf("paranthesis is balanced\n");
	else
		printf("paranthesis is not balanced\n");

	return 0;
}
