#include <stdio.h>

int strend(char* s, char* t){
	
	int i;
	i = 0;
	
	while(*s++);
	while(*t++) i++;
	
	t = t - 1;
	s = s - 1;
	
	for(; i >= 0; i--) if(*s-- != *t--) return 0;
	
	return 1;
	
}

int str_len(char* str){
	
	char* ptr;
	ptr = str;
	
	while(*ptr++);
	
	return (ptr-str-1);
	
}

int main(){
	
	char s[] = "something";
	char t[] = "thing";
	
	printf("%d\n", strend(s, t));
	
}