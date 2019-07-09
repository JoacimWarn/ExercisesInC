#include <stdio.h>

int aToi(const char* str){
	
	int i, bool, strToInt;
	strToInt = 0;
	
	while(*str != '\0'){
		
		strToInt = strToInt * 10;
		
		//48 -> 57: 0 - 9
		i = 48;
		bool = 0;
		for(; i <= 57; i++){
			if(i == *str){
				bool = 1;
				break;
			}
		}
		printf("aToi:%d\n", strToInt);
		if(!bool) return 0;
		
		strToInt = strToInt + *str - 48;
		*str++;
		
	}
	
	return strToInt;
	
}

int main(){
	
	char str[] = "1234567";
	int val;
	
	val = aToi(str);
	printf("\n%d", val);
	
	return 0;
	
}