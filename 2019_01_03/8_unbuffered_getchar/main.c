#include <stdio.h>

/* getchar:  unbuffered single character input */
int getchar(void)
{
	
	char c;
	
	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
	
}

int main(){
	
	int c;
	
	c = getchar();
	
	printf("%c", c);
	
	return 0;
	
}