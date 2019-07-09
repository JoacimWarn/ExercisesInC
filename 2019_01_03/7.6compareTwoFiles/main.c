#include <stdio.h>

#define BUFFER 10

void filecopy(FILE*, FILE*);
char* getTextFromFile(char* , int, FILE*);

//compares two strings, must be same length
int compareStrings(char* s1, char* s2){
	
	while(*s1) if(*s1++ != *s2++) return 0;
	
	return 1;
	
}


int main(int argc, char* argv[]){
	
	FILE* fpFirst;
	FILE* fpSecond;
	char* prog = argv[0];
	char textFromFileFirst[BUFFER];
	char textFromFileSecond[BUFFER];
	
	if(argc == 1){
		
		filecopy(stdin, stdout);
		
	}
	else{
		
		fpFirst = fopen(*++argv, "r");
		if(fpFirst == NULL) return 1;
		fpSecond = fopen(*++argv, "r");
		if(fpSecond == NULL) return 1;
		
		//compare line at a time
		while(1){
			
			getTextFromFile(textFromFileFirst, BUFFER, fpFirst);
			getTextFromFile(textFromFileSecond, BUFFER, fpSecond);
			
			if(!compareStrings(textFromFileFirst, textFromFileSecond)){
				//two lines that differ
				printf("two lines that differ:\n");
				printf("%s\n", textFromFileFirst);
				printf("%s\n", textFromFileSecond);
				break;
				
			}
			
		}
		
		fclose(fpFirst);
		fclose(fpSecond);
		/*
		while(--argc > 0){
			
			if((fp = fopen(*++argv, "r")) == NULL){
				
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				return 1;
				
			}
			else{
				
				//two files
				filecopy(fp, stdout);
				fclose(fp);
				
			}
			
		}
		*/
	}
	if(ferror(stdout)){
		
		fprintf(stderr, "%s: error writing stdout\n", prog);
		return 2;
		
	}
	
	return 0;
	
}

char* getTextFromFile(char *s, int n, FILE* iop){
	
	int c;
	char* cs;
	cs = s;
	
	while(n > 0){
		
		c = getc(iop);
		*cs++ = c;
		
		if(c == EOF) break;
		if(c == ' ') break;
		if(*cs == '\n') break;
		
		n--;
		
	}
	
	*cs = '\0';
	
	if(c == EOF && cs == s) return NULL;
	else return s;
	
}

void filecopy(FILE* ifp, FILE* ofp){
	
	int c;
	
	while((c = getc(ifp)) != EOF) putc(c, ofp);
	
}