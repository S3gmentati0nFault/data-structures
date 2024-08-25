#include <stdio.h>

#include "mis.h"
#include "../utilities/utilities.h"

int main() {
	// Generate a random graph
	uint size = 5;
	graph *G = randomsymmetricgraphconstructor(size);
	list *I = mis(G);
	graphprinter(G);
	listprinter(I);
	printf("\n\n\n");
}
