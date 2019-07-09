#include <stdio.h>

/* getline:  get line into s, return length */
int getline(char* ptr, int lim){
	
	int i, c;
	i = 0;
	
	while(--lim > 0 && (c = getchar()) != EOF && c != '\0'){
		
		*ptr++ = c;
		i++;
		
	}
	
	return i;
	
}

int main(){
	
	const int SIZE = 10;
	char string[SIZE];
	
	printf("%d\n", getline(string, SIZE));
	
	return 0;
	
}