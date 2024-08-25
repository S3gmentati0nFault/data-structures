#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "utilities.h"
#include "../../master-utilities/mutils.h"


// Random constructor for a directed graph
graph *randomgraphconstructor(uint size) {
	uint **vertices = (uint **) mallocordie(size * sizeof(uint *));

	srand(time(NULL));
	for(uint i = 0; i < size; ++i) {
		vertices[i] = (uint *) mallocordie(size * sizeof(uint));

		for(uint j = 0; j < size; ++j) {
			vertices[i][j] = (uint) rand() % 2;
		}
	}

	graph *G = (graph *) mallocordie(sizeof(graph));
	G->vertices = vertices;
	G->size = size;

	return G;
}


// Random constructor for an undirected graph
graph *randomsymmetricgraphconstructor(uint size) {
	uint **vertices = (uint **) mallocordie(size * sizeof(uint *));

	srand(time(NULL));
	for(uint i = 0; i < size; ++i) {
		vertices[i] = (uint *) mallocordie(size * sizeof(uint));

		for(uint j = 0; j < i; ++j) {
			vertices[i][j] = (uint) rand() % 2;
			vertices[j][i] = vertices[i][j];
		}
	}

	graph *G = (graph *) mallocordie(sizeof(graph));
	G->vertices = vertices;
	G->size = size;

	return G;
}


// Graph deconstructor
void graphdeconstructor(graph *G) {
	for(uint i = 0; i < G->size; ++i) {
		free(G->vertices[i]);
	}
	free(G->vertices);

	G->size = 0;
	G->vertices = NULL;
}


// The copyconstructor for the graph
graph *copyconstructor(graph *G) {
	graph *H = (graph *) mallocordie(sizeof(graph));

	// Copy the vertices
	uint **vertices = (uint **) mallocordie(G->size * sizeof(uint *));
	for(uint i = 0; i < G->size; ++i) {
		vertices[i] = (uint *) mallocordie(G->size * sizeof(uint));
		for(uint j = 0; j < G->size; ++j) {
			vertices[i][j] = G->vertices[i][j];
		}
	}

	// Set the struct variables
	H->vertices = vertices;
	H->size = G->size;

	return H;
}


// Simple function that checks if a vertex is valid, if the uint passed as argument is greater than
// the graph size then it's definitely not valid
bool checkvertex(uint vertex, graph *G) {
	if(vertex > G->size) {
		printf("Trying to access an invalid vertex\n");
		return false;
	}
	return true;
}


// Simple function that prints the adjacency matrix for the graph G passed as argument
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


// Function that writes a file .txt containing the graph G that has been passed as argument
void graphwriter(graph *G) {
	char path[] = "../../testing-files/graph.txt";
	FILE *fptr;

	// Open the file in writing mode
	fptr = fopen(path, "w");

	// Write down the size of the graph
	fprintf(fptr, "%d\n", G->size);

	// Write the adjacency lists
	for(uint i = 0; i < G->size; ++i) {
		for(uint j = 0; j < G->size; ++j) {
			if(G->vertices[i][j] == 1) {
				fprintf(fptr, "%d,", j);
			}
		}
		fprintf(fptr, "\n");
	}

	// Close the file
	fclose(fptr);
}
