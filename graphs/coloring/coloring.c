#include <stdio.h>
#include <stdlib.h>

#include "../../priority-queues/priority.h"
#include "coloring.h"


int *naivecoloring(graph *G) {
	// Construction of the pqueue
	data_type *vector = (data_type *) malloc(G->size * sizeof(data_type));
	for(uint i = 0; i < G->size; ++i) {
		vector[i] = i;
	}
	pqueue *queue = vectorconstructor(vector, G->size);

	// Resulting color array
	int *colors = (int *) malloc(G->size * sizeof(int));
	for(uint i = 0; i < G->size; ++i) {
		colors[i] = NO_COLOR;
	}

	// Until the pile of vertices to be colored has not been handled:
	while(!isempty(queue)) {
		// Pick one vertex
		uint vertex = dequeue(queue);

		// Pick the color in the neighbourhood
		uint color = colorpicker(vertex, G, colors);

		// Set the color for that element
		colors[vertex] = color;
	}

	deconstructor(queue);

	return colors;
}


uint colorpicker(uint vertex, graph *G, int *colors) {
	int maxcolor = -1;

	for(uint j = 0; j < G->size; ++j) {
		if(G->vertices[vertex][j] == 1 && colors[j] > maxcolor) {
			maxcolor = colors[j];
		}
	}

	return maxcolor + 1;
}
