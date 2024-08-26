#include <stdio.h>

#include "coloring.h"
#include "../utilities/utilities.h"
#include "../MIS/mis.h"

int main() {
	graph *G;
	uint size = 1000;

	// Construction of a random graph
	G = randomsymmetricgraphconstructor(size);
	if(size < 20) {
		graphprinter(G);
	}
	graphwriter(G);

	// Test naive coloring technique
	int *colors = naivecoloring(G);
	if(size < 20) {
		printf("vertex -> color\n");
		for(uint i = 0; i < size; ++i) {
			printf("%d -> %d\n", i, colors[i]);
		}
	}
	coloringwriter(colors, size);
	
	// Computing the mis
	//list *I = mis(G);
	

	// Testing the python checker
	

	graphdeconstructor(G);

	return 0;
}
