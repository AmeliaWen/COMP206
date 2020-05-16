/*this is the implementation for caesaiecipher
 * amelia cui 260824815 software engineering . Feb 15th initial version 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]){
	if (argc != 2 ){
		printf("Error: usage is caesarcipher <offset> \n");
		return 1;
	}else{
		char name[100];
		int offset = atoi(argv[1]);
		char first;
		int i;
		while (fgets(name, 99, stdin) != NULL){
		int len = strlen(name);
		for (i = 0; i< len; i++){
			first = name[i];
			if (first >= 'a' && first <= 'z'){
				 first = first + offset-'a';
				 
				if (first>=26){
					first = (first-26)%26;
					name[i]= first +'a';
				}
				if (first<0){
					first = ((first+26)%26);
					name[i]= first+'a';
				}
				name[i]= first +'a';
	}
			
			}
		printf("%s", name);
		}
		return 0;
		}
	}

	




