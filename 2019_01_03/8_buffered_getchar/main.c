#include <stdio.h>

/* getchar:  simple buffered version */
int getchar(void)
{
	
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;

	if (n == 0){	/* buffer is empty */
	
		n = read(0, buf, sizeof buf);
		bufp = buf;
		
	}
	
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
	
}

int main(){
	
	char buf[BUFSIZ];
	int i, c;
	i = 0;
	
	do{
		
		c = getchar();
		buf[i++] = c;
		
	}while(c != EOF && c != '\n');
	buf[--i] = ' ';				//remove '\n' carriage return
	buf[i] = '\0';				//null terminated string
	
	printf("%s", buf);
	
	return 0;
	
}