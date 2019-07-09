#include <stdio.h>

/* strcat:  concatenate t to end of s; s must be big enough */
void str_cat(char* s, char* t){
	
	while(*s++ = *t++);
	
}

int str_len(char* str){
	
	int i = 0;
	
	while(*str++){
		
		i++;
		
	}
	
	return i;
	
}

int main(){
	
	char s[40] =	"hello ";
	char t[] =		 "world";
	
	printf("%d\n", str_len(s));
	
	str_cat(&s[str_len(s)], t);
	
	printf("%s", s);
	
	return 0;
	
}