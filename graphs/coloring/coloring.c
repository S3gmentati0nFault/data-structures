#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../priority-queues/priority.h"
#include "coloring.h"

graph *randomgraphconstructor(uint size) {
	uint **vertices = (uint **) malloc(size * sizeof(uint *));

	srand(time(NULL));
	for(uint i = 0; i < size; ++i) {
		vertices[i] = (uint *) malloc(size * sizeof(uint));

		for(uint j = 0; j < size; ++j) {
			vertices[i][j] = (uint) rand() % 2;
		}
	}

	graph *G = (graph *) malloc(sizeof(graph));
	G->vertices = vertices;
	G->size = size;

	return G;
}


void graphdeconstructor(graph *G) {
	for(uint i = 0; i < G->size; ++i) {
		free(G->vertices[i]);
	}
	free(G->vertices);

	G->size = 0;
	G->vertices = NULL;
}


bool checkvertex(uint vertex, graph *G) {
	if(vertex > G->size) {
		printf("Trying to access an invalid vertex\n");
		return false;
	}
	return true;
}


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


void graphprinter(graph *G) {
	uint size = G->size;

	for(uint i = 0; i < size; ++i) {
		for(uint j = 0; j < size - 1; ++j) {
			printf("%d  ", G->vertices[i][j]);
		}
		printf("%d\n", G->vertices[i][size - 1]);
	}

	return;
}
