#include <stdio.h>

int strCpy(char* dest, const char* src){
	
	while(*dest++ = *src++);
	
}

int main(){
	
	char a[10];
	char b[] = "hello";
	
	printf("%s\n", a);
	strCpy(a, b);
	printf("%s\n", a);
	
	return 0;
	
}