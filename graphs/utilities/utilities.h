#include <stdbool.h>

#include "../../lists/simple/list.h"

#ifndef UTILITIES_H
#define UTILITIES_H

	typedef unsigned int uint;

	typedef struct {
		uint size;
		uint **vertices;
	} graph;

	graph *randomgraphconstructor(uint size);

	graph *randomsymmetricgraphconstructor(uint size);

	void graphdeconstructor(graph *G);

	graph *copyconstructor(graph *G);

	bool checkvertex(uint vertex, graph *G);

	void graphprinter(graph *G);

	void graphwriter(graph *G);

	list *adjacencylistbuilder(graph *G);

#endif
