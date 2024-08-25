#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "mis.h"
#include "../../lists/simple/list.h"
#include "../utilities/utilities.h"

list *mis(graph *G) {
	// Construct the empty MIS
	list *mis = emptylistconstructor();
	
	// Create a list containing all of the vertices
	list *V = emptylistconstructor();
	for(uint i = 0; i < G->size; ++i) {
		push(V, i);
	}

	srand(time(NULL));
	while(!isempty(V)) {
		listprinter(V);
		// Take a random vertex
		uint i = (uint) rand() % V->length;
		printf("%d\t", i);
		node *n;
		for(n = V->head; i > 0; --i) {
			n = n->next;
		}
		printf("%d\n", n->value);
		
		// Put it in the MIS
		push(mis, n->value);

		// Remove all of its neighbours from it
		deleteneighbours(V, n->value, G);
	}

	// Cleanup
	listdeconstructor(V);

	return mis;
}


void deleteneighbours(list *V, uint vertex, graph *G) {
	// Delete all of the neighbours of vertex from V
	for(uint i = 0; i < G->size; ++i) {
		if (G->vertices[vertex][i] == 1) {
			printf("%d\t", i);
			free(removelement(V, i));
		}
	}
	printf("\n");

	free(removelement(V, vertex));
}
