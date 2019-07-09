#include <stdio.h>

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

int main(){
	
	const int LIM = 5;
	char a[LIM];
	//char* a = "hej";
	
	getword(a, LIM);
	
	printf("%s", a);
	
	return 0;
	
}