#include <stdio.h>

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n)    /* return pointer to n characters */
{
	printf("%d\n", (allocbuf + ALLOCSIZE - allocp) );
	if (allocbuf + ALLOCSIZE - allocp >= n) {  /* it fits */
		allocp += n;
		return allocp - n; /* old p */
	} else      /* not enough room */
	return 0;
}

void afree(char *p)  /* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
	allocp = p;
}

int strr_len(char* s){
	
	int i;
	i = 0;
	
	while(*s++) i++;
	
	return i;
	
}

int str_len(char* s){
	
	char* p = s;
	
	while(*p++);
	
	return (p-s-1);
	
}

int main(){
	
	char a[] = "  ";
	char* aptr = a;
	
	printf("%d\n", str_len(aptr));
	
	char* memptr;
	memptr = alloc(2);
	memptr = alloc(2);
	memptr = alloc(100000);
	
}