/* program to implement a simple calculator 
 * Amelia Cui 260824815 software engineering . Feb 15th Initial version
 */
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
	if (argc != 4){
		puts("Error: usage is simplecalc <x> <op> <y>");
		return 1;
	}else{
	
		int a = atoi(argv[1]);
		int b = atoi(argv[3]);
		char op = *(argv[2]);
		int result;
		switch (op) {
			case '+': 
				result = a+b;
				printf("%d\n", result);
				break;
			case '-':
				result = a-b;
				printf("%d\n", result);
				break;
			case '*':
				result = a*b;
				printf("%d\n", result);
				break;
			case '/':
				result = a/b;
				printf("%d\n", result);
				break;
			default:
                printf("%s is not a valis operator \n",argv[2]);
				//puts("not a valid operator");
				return 2;
				break;

	}
	}
		return 0;
}
