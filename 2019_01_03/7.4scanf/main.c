#include <stdio.h>
#include <stdarg.h>
#include <string.h>
int getword(char *, int);
int aToi(const char*);

#define BUFFER 10

int scanff(char* format, ...){
	//%c %s %d %f
	
	va_list ap;
	char* p;
	char sval[BUFFER], *sdest;
	int *idest;
	double dval;
	int i  = -1;
	
	va_start(ap, format);
	
	for(p = format; *p; p++){
		
		while((getchar()) != '\n');				//flush standard input
		
		if(*p != '%'){
			
			putchar(*p);
			continue;
			
		}
		
		switch(*++p){
			
			case 's':
			do{
				
				i++;
				sval[i] = getchar();
				
			}while(sval[i] != '\n' && sval[i] != EOF);
			sdest = va_arg(ap, char*);
			strcpy(sdest, sval);
			break;
			
			case 'd':
			do{
				
				i++;
				sval[i] = getchar();
				
			}while(sval[i] != '\n' && sval[i] != EOF);
			idest = va_arg(ap, int*);
			*idest = aToi(sval);
			break;
			
			case 'f':
			//dval = va_arg(ap, double);
			
			break;
			
			default:
			//putchar(c);
			//putchar(*p);
			break;
			
		}
		
	}
	
	va_end(ap);
	
}

int main(){
	
	char a[BUFFER];
	int b;
	
	scanf("%s", a);
	printf("main:%s\n", a);
	
	scanff("%d", &b);
	printf("main:%d\n", b);
	
	return 0;
	
}

/* getword:  get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	while (isspace(c = getch()));
	
	if (c != EOF){
		
		*w++ = c;
		
	}
	
	if (!isalpha(c) && !(c == 45 || c == 95)){			//underscore
		
		*w = '\0';
		return c;
		
	}
	
	for ( ; --lim > 0; w++)
	{
		
		if (!isalnum(*w = getch()) && !(*w == 45 || *w == 95)){
			
			ungetch(*w);
			break;
			
		}
		
	}
	
	*w = '\0';
	return word[0];
	
}

int aToi(const char* str){
	
	int i, bool, strToInt;
	strToInt = 0;
	
	while(*str != '\0' && *str != 10){			//10 -> newline feed \n
		
		strToInt = strToInt * 10;
		
		//48 -> 57: 0 - 9
		i = 48;
		bool = 0;
		for(; i <= 57; i++){
			if(i == *str){
				bool = 1;
				break;
			}
		}
		if(!bool) return 0;
		
		strToInt = strToInt + *str - 48;
		*str++;
		
	}
	
	return strToInt;
	
}