#include <stdio.h>

#define BUFFER 10

void filecopy(FILE*, FILE*);
char* getTextFromFile(char* , int, FILE*);

//compares two strings, must be same length
int findPattern(char* pattern, char* text){
	
	while(*text++){
		
		if(*text == *pattern){
			
			while(*text == *pattern){
				
				*text++;
				*pattern++;
				
				if(*pattern == '\0' || *pattern == '\n' || *pattern == EOF) return 1;
				
			}
			
		}
		
	}
	
	return 0;
	
}


int main(int argc, char* argv[]){
	
	FILE* fpFileToSearch;
	FILE* fpPattern;
	char* prog = argv[0];
	char patternFromFile[BUFFER];
	char textFromFile[BUFFER];
	int i;
	
	if(argc >= 1){
		
		fpPattern = fopen(*++argv, "r");
		if(fpPattern == NULL) return 1;
		fpFileToSearch = fopen("test1.txt", "r");
		if(fpFileToSearch == NULL) return 1;
		
		getTextFromFile(patternFromFile, BUFFER, fpPattern);			//retrieve the pattern from text file
		i = 0;
		
		while(i < 20){
			
			getTextFromFile(textFromFile, BUFFER, fpFileToSearch);
			
			if(findPattern(patternFromFile, textFromFile)){
				
				printf("%s\n", textFromFile);
				
			}
			
			i++;
			
		}
		
		fclose(fpPattern);
		fclose(fpFileToSearch);
		
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
		if(c == '\n'){
			
			*cs--;
			break;
			
		}
		
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