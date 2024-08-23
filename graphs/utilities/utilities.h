#include <stdbool.h>

#ifndef UTILITIES_H
#define UTILITIES_H

	typedef unsigned int uint;

	typedef struct {
		uint size;
		uint **vertices;
	} graph;

	graph *randomgraphconstructor(uint size);

	void graphdeconstructor(graph *G);

	bool checkvertex(uint vertex, graph *G);

	void graphprinter(graph *G);

#endif
