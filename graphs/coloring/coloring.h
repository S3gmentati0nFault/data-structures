#include <stdbool.h>

#ifndef COLORING_H
#define COLORING_H

#define NO_COLOR -1

	typedef unsigned int uint;

	typedef struct {
		uint size;
		uint **vertices;
	} graph;

	graph *randomgraphconstructor(uint size);

	void graphdeconstructor(graph *G);

	bool checkvertex(uint vertex, graph *G);
	
	int *naivecoloring(graph *G);

	void graphprinter(graph *G);

	uint colorpicker(uint vertex, graph *G, int *colors);

#endif
