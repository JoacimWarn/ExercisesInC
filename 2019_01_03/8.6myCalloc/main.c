#include <stdio.h>
#include <stdlib.h>

typedef long Align;

union header{
	
	struct{
		
		union header* ptr;
		unsigned size;
		
	}block;
	Align x;		//force alignment of blocks, memory padding
};

typedef union header Header;
static Header base;					//empty list to get started
static Header* freep = NULL;		//start of free list


/* allocate memory, n -> number of items, size -> number of bytes */
void* myCalloc(unsigned int size){
	
	Header* p;
	Header* prevp;
	unsigned nrOfUnits;
	
	nrOfUnits = (size + sizeof(Header)-1 / (sizeof(Header) + 1));
	if((prevp = freep) == NULL){		//no free list yet
	
		base.block.ptr = freep = prevp = &base;
		base.block.size = 0;
		
	}
	printf("block size:%d, nrOfUnits:%d\n", p->block.size, nrOfUnits);
	for(p = prevp->block.ptr;; prevp = p, p = p->block.ptr){
		printf("hej\n");
		if(p->block.size >= nrOfUnits){		//big enough
		printf("hej\n");
			if(p->block.size == nrOfUnits){	//exactly same size
			
				prevp->block.ptr = p->block.ptr;
				
			}
			else{		//allocate at tail end
				
				p->block.size = p->block.size - nrOfUnits;
				p = p + p->block.size;
				p->block.size = nrOfUnits;
				
			}
			
			freep = prevp;
			return (void*)(p + 1);
			
		}
		
		if(p == freep) return NULL;		//wrapped around free list, no more memory
		
	}
	
}

int main(){
	
	int* ptrCalloc;
	ptrCalloc = (int*) calloc(1, sizeof(int));
	*ptrCalloc = 4;
	
	printf("%d at memory location %p\n", *ptrCalloc, ptrCalloc);
	printf("%d at memory location %u\n", *ptrCalloc, ptrCalloc);
	/*
	int* ptrMyCalloc;
	ptrMyCalloc = (int*) myCalloc(1, sizeof(int));
	printf("%s", ptrMyCalloc);
	*ptrMyCalloc = 5;
	*/
	int listMyCalloc[10];
	int i;
	for(i = 0; i < 10; i++){
		
		listMyCalloc[i] = (int) myCalloc(1, sizeof(int));
		listMyCalloc[i] = i;
		printf("memory location:%u\n", &listMyCalloc[i]);
		
	}
	
	//printf("%d at memory location %p\n", *ptrMyCalloc, ptrMyCalloc);
	//printf("%d at memory location %u\n", *ptrMyCalloc, ptrMyCalloc);
	
	return 0;
	
}