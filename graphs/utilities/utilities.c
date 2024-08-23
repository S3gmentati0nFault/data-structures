#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "utilities.h"


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
