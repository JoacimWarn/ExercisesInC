#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

int getword(char *, int);

struct tnode {     /* the tree node: */
	char *word;           /* points to the text */
	int count;            /* number of occurrences */
	struct tnode *left;   /* left child */
	struct tnode *right;  /* right child */
};

char *strDup(char *s)   /* make a duplicate of s */
{
	char *p;

	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
	if (p != NULL)
	strcpy(p, s);
	return p;
}

/* talloc:  make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* treeprint:  in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* addtree:  add a node with w, at or below p */
struct treenode *addtree(struct tnode *p, char *w)
{
	int cond;
	
	if (p == NULL){							/* a new word has arrived */
		
		p = talloc();    					/* make a new node */
		p->word = strDup(w);
		p->count = 1;
		p->left = p->right = NULL;
		
	}
	
	else if ((cond = strcmp(w, p->word)) == 0){
		
		p->count++;							/* repeated word */
		
	}
	else if (cond < 0){
		
		p->left = addtree(p->left, w);		/* less than into left subtree */
		
	}
	else{
		
		p->right = addtree(p->right, w);	/* greater than into right subtree */
		
	}
	
	return p;
	
}

/* word frequency count */
int main(){
	
	struct tnode *root;
	char word[MAXWORD];
	int count = 0;
	
	root = NULL;
	while (count < 10 && getword(word, MAXWORD) != EOF){
		
		if (isalpha(word[0])){
			
			root = addtree(root, word);
			treeprint(root);
			printf("\n");
			count++;
			
		}
		
	}

	treeprint(root);
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