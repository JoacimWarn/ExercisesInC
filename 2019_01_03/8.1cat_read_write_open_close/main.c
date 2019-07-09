#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#define PERMS 0666     /* RW for owner, group, others */
#define BUFSIZE 1024

void error(char*, ...);

/* strcat:  concatenate t to end of s; s must be big enough */
void str_cat(char* s, char* t){
	
	while(*s++ = *t++);
	
}

/* return length of string s */
int str_len(char* s){
	
	char* p = s;
	
	while(*p++);
	
	return (p-s-1);
	
}

/* concatenate f1 and f2 */
void fileCopy(int f1, int f2){
	
	int c;
	char bufferFile2[BUFSIZE];
	char bufferFile1[BUFSIZE];
	
	while(c = read(f2, bufferFile2, BUFSIZE));
	while(c = read(f1, bufferFile1, BUFSIZE));
	printf("%s\n", bufferFile2);
	printf("%s\n", bufferFile1);
	
	//str_cat(&bufferFile2[str_len(bufferFile2)], bufferFile1);
	str_cat(bufferFile2, bufferFile1);
	printf("%s\n", bufferFile2);
	
	write(f2, bufferFile2, str_len(bufferFile2));
	//while file2 -> write
	//while file1 -> write
	
}

int main(int argc, char* argv[]){
	
	int f1, f2, n1, n2;
	
	if(argc == 1){
		
		error("Too few arguments");
		return 1;
		
	}
	else{
		
		if((f1 = open(argv[1], O_RDONLY, 0)) == -1){
			
			error("Cannot open file:%s", argv[1]);
			return 1;
			
		}
		if((f2 = open(argv[2], PERMS, 0)) == -1){
			
			error("Cannot open file:%s", argv[2]);
			return 1;
			
		}
		
	}
	//both files opened succesfully
	fileCopy(f1, f2);
	
	close(f1);
	close(f2);
	
	return 0;
	
}

void error(char* format, ...){
	
	va_list args;
	va_start(args, format);
	
	fprintf(stderr, "error: ");
	vprintf(format, args);
	fprintf(stderr, "\n");
	
	va_end(args);
	
}