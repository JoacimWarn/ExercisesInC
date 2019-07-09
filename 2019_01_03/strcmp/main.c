#include <stdio.h>

int str_cmp(char* s, char* t){
	
	while(*s++ == *t++){
		
		printf("%c %c\n", *s, *t);
		
		if(*s == '\0' && *t == '\0') return 0;
		
	}
	
	return 1;
	
}

int main(){
	
	char s[] = "hello";
	char t[] = "hello";
	
	//str_cmp(a,b);
	printf("%d\n", str_cmp(s,t));
	
	return 0;
	
}