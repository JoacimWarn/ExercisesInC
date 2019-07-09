#include <stdio.h>
#include <string.h>
#include <fcntl.h>
//#include <sys/types.h>

#include <sys/stat.h>
//#include <dir.h>
//#include <dirent.h>

#define MAX_PATH 1024

#define NAME_MAX   14  /* longest filename component; */
/* system-dependent */

typedef struct {       /* portable directory entry */
	long ino;                  /* inode number */
	char name[NAME_MAX+1];     /* name + '\0' terminator */
} Dirent;

typedef struct {       /* minimal DIR: no buffering, etc. */
	int fd;               /* file descriptor for the directory */
	Dirent d;             /* the directory entry */
} DIR;

#ifndef DIRSIZ 
#define DIRSIZ  14 
#endif
struct direct {   /* directory entry */
	ino_t d_ino;           /* inode number */
	char  d_name[DIRSIZ];  /* long name does not have '\0' */
};

void fsize(char*);
void dirwalk(char *, void (*fcn)(char *));
DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);


int main(int argc, char** argv){
	
	if(argc == 1) fsize(".");		//default current directory
	else{
		
		while(--argc > 0) fsize(*++argv);
		
	}
	
	return 0;
	
}


/* fsize:  print the name of file "name" */
void fsize(char *name)
{
	
	struct stat stbuf;

	if (stat(name, &stbuf) == -1) {
		
		fprintf(stderr, "fsize: can't access %s\n", name); 
		return;
		
	} 
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR) dirwalk(name, fsize);
	
	printf("bytes\t\tname\n");
	
	printf("%ld", stbuf.st_size);
	putchar('\t');
	putchar('\t');
	printf("%s", name);
	putchar('\n');
	
}

/* dirwalk:  apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *)) 
{
	
	char name[MAX_PATH];
	Dirent *dp;
	DIR *dfd;

	//printf("%s\n", dir);
	
	if ((dfd = opendir(dir)) == NULL) {
		
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
		
	}
	while ((dp = readdir(dfd)) != NULL) {
		
		if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..")) continue;    /* skip self and parent */
		
		if (strlen(dir)+strlen(dp->name)+2 > sizeof(name)) fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name);
		else {
			
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
			
		}
		
	}
	
	closedir(dfd);
	
}