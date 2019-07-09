#include <stdio.h>

/* converts c into lower case */
int toLower(int c){
	
	if(c >= 97 && c <= 122) return c;		//already lower case letter
	if(c < 65 || c > 90) 	return c;		//not a letter
	
	c = c + 32;
	
	return c;
	
}

/* converts c into upper case */
int toUpper(int c){
	
	if(c >= 65 && c <= 90) return c;		//already upper case letter
	if(c < 97 || c > 122) return c;			//not a letter
	
	c = c - 32;
	
	return c;
	
}

int main(){
	
	int c;
	
	c = getch();
	putchar('\n');
	
	c = toUpper(c);
	c = toLower(c);
	
	putchar(c);
	
	return 0;
	
}