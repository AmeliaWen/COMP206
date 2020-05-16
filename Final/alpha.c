#include<stdio.h>
#include<stdlib.h>
int main (int argc, char *argv[]){
	//use temp to store the argument passed
	char*temp=argv[1];
	// pre points to the first char in the the string
        char pre=*temp;
	// result var to indicate if found or not
	int result = 0;
	while(pre != '\0'){
		if(pre== 'p'||(pre=='q')||(pre=='r')||(pre=='x')||(pre=='y')||(pre=='z')||(pre=='P')||(pre=='Q')||(pre=='R')||(pre=='X')||(pre=='Y')||(pre=='Z')){
//			result changed when at least one char match the pattern
			result= 1;

			break;
		}
		//pre now points to the next char in string
		pre=*(temp++);
	}
	//if there exist required alphabet
	if(result==1){
		return 0;
	}else{
		return 1;
	}
}

	
