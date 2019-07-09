#include <stdio.h>

void iToa(const int n, char* str){
	
	int i, len;
	i = n;
	len = 0;
	
	do{
		
		*str++ = i % 10 + '0';
		i = i / 10;
		len++;
		
	}while(i > 0);
	
	*str = '\0';
	*str--;
	char reverse[len];
	
	for(i = 0; i < len; i++) reverse[i] = *str--;
	*str++;
	for(i = 0; i < len; i++) *str++ = reverse[i];
	
}

int main(){
	
	int a = 12345;
	char b[20];
	
	iToa(a, b);
	
	printf("%s\n", b);
	
	return 0;
	
}