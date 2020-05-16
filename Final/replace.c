#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"replace.h"
// this function is responsible for detecting that the word read from the file matches word1. If it does match word1 then it returns word2, otherwise it returns word1. 
const char* replace (char word[], char*word1, char*word2){
	// convert string to constant in order to return 
        const char*word11=word;
        const char*word22=word2;
        if(strcmp(word, word1)==0){
                return word22;
        }else{
                return word11;
        }
}


              
