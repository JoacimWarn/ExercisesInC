#include <stdio.h>
#include <ctype.h>

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	printf("hey\n");
	
	while (isspace(c = getch()))   /* skip white space */
	;
	printf("hey\n");
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);  /* it is not a number */
		return 0;
	}
	
	printf("hey\n");
	
	sign = (c == '-') ? -1 : 1;
	
	if (c == '+' || c == '-') c = getch();
	printf("hey\n");
	
	for (*pn = 0; isdigit(c), c = getch();) *pn = 10 * *pn + (c - '0');	//stuck here
	printf("hey\n");
	*pn *= sign;
	
	if (c != EOF) ungetch(c);
	
	return c;
	
}

int main(){
	
	int r, i;
	
	while(r = getint(&i) != 0){
		
		if(r != 0) printf("%d", i);
		
	}
	
	return 0;
	
}