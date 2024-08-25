#include "utilities.h"

int main() {
	// Graph writing test
	graph *G = randomgraphconstructor(10);
	graphwriter(G);
	graphprinter(G);

	// Memory checker test
	randomgraphconstructor(100000);

	return 0;
}
