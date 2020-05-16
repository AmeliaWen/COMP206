#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Amelia Cui 260824815 software engineering
 *Initial version feb 28th 
 */
void addaccount(char*number, char* newname, FILE *s){
	char array[1000];
	char type[200]="";
	char num[200]="";
	char name[200]="";
	int i,j,k;
	while(fgets(array,999,s)){
			i=0;
			for (j=0;j<200&&array[i]!=',';i++,j++){
			type[j]=array[i];
			}
			i++;
			for (j=0;j<200&&array[i]!=',';i++,j++){
			num[j]=array[i];
			}
			i++;
			if (strcmp(number,num)==0&&strcmp(type, "AC")==0){
				fprintf(stderr,"Error, account number %s already exists\n",num);
				exit (50);
			}
	}
        s = fopen("bankdata.csv","at");
	fputs("AC",s);
	fputs(",",s);
	fputs(number, s);
	fputs(",",s);
	fputs(newname,s);
	fputs("\n",s);
	fclose(s);
}
void deposit(char*number, char*newdate, char*newamount, FILE *s){
	char array[1000];
	char type[200]="";
	char num[200]="";
	char date[200]="";
	int hasaccount = 0;
	char amount[200]="";
	int i,j;
	while (fgets(array,999,s)){
		i=0;
		for (j=0;j<200&&array[i]!=',';i++,j++){
			type[j]=array[i];
		}
		i++;
		for (j=0;j<400&&array[i]!=',';i++,j++){
			num[j]=array[i];
		}
		if (strcmp(type, "TX")==0&&strcmp(num, number)==0){
			hasaccount = 1;
		}
	}
	if (hasaccount == 0){
		fprintf(stderr,"Error, account number %s does not exists\n",number);
		exit(50);
	}
	s = fopen("bankdata.csv","at");
	fputs("TX",s);
	fputs(",",s);
	fputs(number,s);
	fputs(",",s);
	fputs(newdate, s);
	fputs(",",s);
	fputs(newamount,s);
	fputs("\n",s);
	fclose(s);
}
void withdraw(char*number, char *newdate, char* newamount, FILE *s){
	char array[1000];
	char type[200]="";
	char num[200]="";
	char date[200]="";
	char amount[200]="";
	int hasaccount=0;
	float balance=0;
	int i,j;
	while (fgets(array,999,s)){
		i=0;
		for (j=0;j<200&&array[i]!=',';i++,j++){
			type[j]= array[i];
		}
		i++;
		for (j=0;j<200&&array[i]!=',';i++,j++){
			num[j]=array[i];
		}
		i++;
		for (j=0;j<200&&array[i]!=',';i++,j++){
			date[j]= array[i];
		}
		i++;
		for (j=0;j<200&&array[i]!='\0'&&array[i]!='\n'&&array[i]!='\r';i++,j++){
			amount[j]=array[i];
		}
		if (strcmp(type,"TX")==0&&strcmp(number,num)==0){
			hasaccount=1;
			balance+=atof(amount);
		}
	}
	if (hasaccount ==0){
		fprintf(stderr,"Error, account number %s does not exists\n",number);
		exit (50);
	}
	if (balance< atof(newamount)){
		fprintf(stderr,"Error, account number %s has only %.2f\n", number, balance);
		exit(60);
	}else{
		s = fopen("bankdata.csv","at");
		fputs("TX,",s);
		fputs(number,s);
		fputs(",",s);
		fputs(newdate,s);
		fputs(",",s);
		float cur = -atof(newamount);
		char wd[100];
		sprintf(wd, "%.2f",cur);
		fputs(wd, s);
		fputs("\n",s);
		fclose(s);
	}
}

int main (int argc, char*argv[]){
	if (argc < 4|| (argc>5)){
		fprintf(stderr, "Error, incorrect usage!\n");
		if (argc ==1){
			fprintf(stderr,"-a ACCTNUM NAME\n");
			fprintf(stderr,"-d ACCTNUM DATE AMOUNT\n");
			fprintf(stderr,"-w ACCTNUM DATE AMOUNT\n");
			exit (1);
		}else{
			if (strcmp(argv[1],"-a")==0){
				fprintf(stderr,"-a ACCTNUM NAME\n");
			}else if (strcmp(argv[1],"-d")==0){
				fprintf(stderr,"-d ACCTUM DATE AMOUNT\n");
			}else if(strcmp(argv[1],"-w")==0){
				fprintf(stderr,"-w ACCTNUM DATE AMOUNT\n");
			}else{
				fprintf(stderr,"-a ACCTNUM NAME\n");
				fprintf(stderr,"-d ACCTNUM DATE AMOUNT\n");
				fprintf(stderr,"-w ACCTNUM DATE AMOUNT\n");
			}
			exit (1);
		}
	}
	if (argc == 4){
		if (strcmp(argv[1],"-d")==0){
			fprintf(stderr,"Error, incorrect usage!\n");
			fprintf(stderr,"-d ACCTNUM DATE AMOUNT\n");
			exit (1);
		}else if (strcmp(argv [1],"-w")==0){
			fprintf(stderr,"Error, incorrect usage!\n");
			fprintf(stderr,"-w ACCTNUM DATE AMOUNT\n");
			exit (1);
		}else if (strcmp(argv [1],"-a")==0){
			FILE *s = fopen("bankdata.csv","rt");
			if (s== NULL){
				fprintf(stderr,"Error, unable to locate the data file bankdata.csv\n");
				exit (100);
			}

		//	FILE *d = fopen("bankdata.csv","rt");
			addaccount(argv[2], argv[3], s);
		}else{
			fprintf(stderr,"error, incorrect usage!\n");
			exit (1);
	}
	}
	if (argc == 5){
		if (strcmp(argv[1],"-a")==0){
			fprintf(stderr,"Error, incorrect usage!\n");
			fprintf(stderr,"-a ACCTNUM NAME\n");
			exit (1);
		}else if (strcmp(argv[1],"-d")==0){
			FILE *s = fopen("bankdata.csv", "rt");
			if (s == NULL){
				fprintf(stderr,"Error, unable to locate the data file bankdata.csv\n");
				exit (100);
			}
			deposit(argv[2], argv[3], argv[4],s);
		}else if (strcmp(argv[1],"-w")==0){
			FILE *s = fopen("bankdata.csv", "rt");
			if (s == NULL){
				fprintf(stderr,"Error, unable to locate the data file bankdata.csv\n");
				exit (100);
			}
			withdraw(argv[2], argv[3], argv[4], s);
		}else{
			fprintf(stderr,"error, incorrect usage!\n");
			exit (1);
		}
	
	}
}



