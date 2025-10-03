#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "barcode.h"

struct barCode generateBarCode(unsigned int size) {
	unsigned int    *t;
	struct barCode	r;

	t = malloc(sizeof(unsigned int) * size);
	if (t == NULL) {
		exit(EXIT_FAILURE);
		fprintf(stderr, "Memory allocation failed \n");
	}
	for (int i = 0; i < size; i++) {
		t[i] = (rand() % 5)+1;
	}
	r.size = size;
	r.code = t;
	return (r);
}

void freeBarCode(struct barCode b) {
	free(b.code);
}

void printLine(struct barCode b) {
	for (int i = 0; i < b.size; i++) {
		for (int j = 0; j < b.code[i]; j++) {
			if (i %2 == 0)
				printf("*");
			if (i %2 == 1)
				printf(" ");
		}
		
	}
	printf("\n");
}
// void printBarCode(struct barCode b, unsigned int h) {}


/** This main function is given as a sample and can
 * be changed as needed for debugging purpose
 **/
int main(int argc, char*argv[]) {
    struct barCode b;
    int seed = time(NULL);
    srand(seed); //initialize the pseudo random generator seed
    unsigned int randSize= rand()%10; // generate a random number between 0 and 9;
	while(randSize+1 < 3){
		randSize= rand()%10;
	}
    printf("Generating a bar code of size %u\n",randSize+1);
    b=generateBarCode(randSize+1); // function to be defined
    printLine(b); // given function
    freeBarCode(b); // given function
    return EXIT_SUCCESS;
}