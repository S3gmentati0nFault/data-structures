#include "coloring.h"
#include <stdio.h>

int main() {
	graph *G;
	uint size = 4;

	// Construction of a random graph
	G = randomgraphconstructor(size);
	graphprinter(G);

	// Test naive coloring technique
	int *colors = naivecoloring(G);
	printf("vertex -> color\n");
	for(uint i = 0; i < size; ++i) {
		printf("%d -> %d\n", i, colors[i]);
	}

	graphdeconstructor(G);

	return 0;
}
