#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//include replace h file for replace function
#include"replace.h"

int main (int argc, char*argv[]){
//	open file in read mode to scanf later and to check if file exists
	FILE* f= fopen(argv[1], "rt");
	if(f==NULL){
		printf("error\n");
		return 1;
	}
	// open a temp file to write to then rename later in order to contain same info as provided file
	char arg[100];
	int i;
	int cr;
	FILE *ptr= fopen("temp", "wt");
	char c;
//	read every word from file 
	while (fscanf(f, "%s", arg) != EOF ){
// cr is used to track \n when it exists in old file, we also need to print it on new file
	if(fgetc(f)=='\n'){
                   cr=1;
              }
	
	//	toRe is a constant string returned with original word or replaced word
		const char* toRe=replace(arg, argv[2], argv[3]);
	//	store the length of word tobe used later when copy paste
		int beforeLen= strlen(arg);
		int afterLen = strlen(toRe);
		int diff;
		const char *p, q;
		// we need to copy every char until the end, add \0 at the end to indicate end of string
		if(beforeLen>= afterLen){
			diff= beforeLen-afterLen;
			for(i=0;i<beforeLen;i++){
				arg[i]=*toRe;
				toRe++;
			}
			arg[i+1]='\0';
		}else{
			for(i=0;i<afterLen;i++){
				arg[i]=*toRe;
				toRe++;
			}
			arg[i+1]='\0';
		}
		//if no \n detected add the white space since we are ignoring it using scanf
		if(cr==0){
		fprintf(ptr, "%s ", arg);
		}
		//if there is \n start a new line
			if(cr ==1){
				fprintf(ptr, "%s", arg);
          
                      fprintf(ptr, "\n");
		      cr=0;
              }


		}
	// close the original file and rename it
	fclose(ptr);
	fclose(f);
	rename("temp", argv[1]);
}

		




