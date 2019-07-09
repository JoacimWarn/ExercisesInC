/* Lookup table */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 100
#define MAXWORD   10


int getword(char *, int);
unsigned hash(char*);
struct defnList* lookup(char*);
struct defnList* install(char*, char*);
char *strDup(char*);


struct defnList{
	
	struct defnList* next;
	char* name;
	char* defn;
	
};
static struct defnList* hashtab[HASHSIZE];

int undef(char* name){
	
	struct defnList* ptr;
	
	if((ptr = lookup(name)) != NULL){
		
		printf("removing %s\n", ptr->name);
		//found the entry, freeing memory location
		free((void*) ptr);
		ptr->name = NULL;
		ptr->defn = NULL;
		ptr = NULL;
		return 1;
		
	}
	
	return 0;		//unsuccesful free
	
}

struct defnList* install(char* name, char* defn){
	
	struct defnList* ptr;
	unsigned hashval;
	
	if((ptr = lookup(name)) == NULL){
		printf("new entry\n");
		//did not find the entry, create new allocation
		ptr = (struct defnList*) malloc(sizeof(*ptr));
		if(ptr == NULL || (ptr->name = strdup(name)) == NULL) return NULL;
		
		printf("%s\n", ptr->name);
		hashval = hash(name);
		ptr->next = hashtab[hashval];
		hashtab[hashval] = ptr;
		
	}
	else free((void*) ptr->defn);
	if((ptr->defn = strdup(defn)) == NULL) return NULL;
	
	return ptr;
	
}

int main(){
	
	char word[MAXWORD];
	char *name, *defn;
	unsigned short int count = 0;
	
	while(count < 2 && getword(word, MAXWORD) != EOF){
		
		if(isalpha(word[0])){
			
			printf("name: %s\n", word);
			name = word;
			getword(word, MAXWORD);
			printf("defn: %s\n", word);
			defn = word;
			
			install(name, defn);
			putchar('\n');
			
		}
		
		count++;
		
	}
	
	int i;
	struct defnList* ptr;
	for(i = 0; i < HASHSIZE; i++){
		
		if(hashtab[i] != NULL){
			
			ptr = hashtab[i];
			printf("%s\n", ptr->defn);
			
		}
		
	}
	
	//free memory
	printf("%d", undef(name));
	
	printf("after removing entry\n");
	
	for(i = 0; i < HASHSIZE; i++){
		
		if(hashtab[i] != NULL){
			
			ptr = hashtab[i];
			printf("%s\n", ptr->defn);
			
		}
		
	}
	
	return 0;
	
}

//getword()
int getword(char *word, int lim)
{
	
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	while (isspace(c = getch()));
	
	if (c != EOF){
		
		*w++ = c;
		
	}
	
	if (!isalpha(c) && !(c == 45 || c == 95)){			//underscore
		
		*w = '\0';
		return c;
		
	}
	
	for ( ; --lim > 0; w++)
	{
		
		if (!isalnum(*w = getch()) && !(*w == 45 || *w == 95)){
			
			ungetch(*w);
			break;
			
		}
		
	}
	
	*w = '\0';
	return word[0];
	
}

/* look for s in hashtab */
struct defnList* lookup(char* s){
	
	struct defnList* ptr;
	
	for(ptr = hashtab[hash(s)]; ptr != NULL; ptr = ptr->next){
		
		if(strcmp(s, ptr->name) == 0) return ptr;
		
	}
	
	return NULL;
	
}

unsigned hash(char* s){
	
	unsigned hashval;
	
	for(hashval = 0; *s; *s++) hashval = *s + 31 * hashval;
	
	return (hashval % HASHSIZE);
	
}

char *strDup(char *s)   /* make a duplicate of s */
{
	char *p;

	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
	if (p != NULL)
	strcpy(p, s);
	return p;
}