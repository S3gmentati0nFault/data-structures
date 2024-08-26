#include <cstddef>
#include <stdlib.h>
#include <stdio.h>

#include "../../lists/simple/list.h"
#include "../MIS/mis.h"
#include "coloring.h"


int *naivecoloring(graph *G) {
	// List construction
	list *V = emptylistconstructor();
	for(uint i = 0; i < G->size; ++i) {
		push(V, i);
	}

	// Resulting color array
	int *colors = (int *) malloc(G->size * sizeof(int));
	for(uint i = 0; i < G->size; ++i) {
		colors[i] = NO_COLOR;
	}

	// Until the pile of vertices to be colored has not been handled:
	while(!isempty(V)) {
		// Pick one vertex
		node *v = pop(V);
		uint vertex = v->value;

		// Pick the color in the neighbourhood
		int color = colorpicker(vertex, G, colors);

		// Set the color for that element
		colors[vertex] = color;
	}

	listdeconstructor(V);

	return colors;
}


int *miscoloring(graph *G) {
	// List construction
	list *V = emptylistconstructor();
	for(uint i = 0; i < G->size; ++i) {
		push(V, i);
	}

	// Resulting color array
	int *colors = (int *) malloc(G->size * sizeof(int));
	for(uint i = 0; i < G->size; ++i) {
		colors[i] = NO_COLOR;
	}

	// Until the pile of vertices to be colored has not been handled:
	while(!isempty(V)) {
		// Pick one vertex
		node *v = pop(V);
		uint vertex = v->value;

		// Compute a maximally independent set
		list *I = mis(G);

		// Pick a color for the MIS
		int color = miscolorpicker(I, G, colors);

		// Color all the vertices in the MIS
		for(node *i = I->head; i != NULL; i = i->next){
			colors[i->value] = color;
			removelement(V, i->value);
		}

		listdeconstructor(I);
	}

	listdeconstructor(V);

	return colors;
}


int miscolorpicker(list *I, graph *G, int *colors) {
	int maxcolor = -1;

	for(node *i = I->head; i != NULL; i = i->next) {
		for(uint j = 0; j < G->size; ++j) {
			if(G->vertices[i->value][j] == 1 && colors[j] > maxcolor) {
				maxcolor = colors[j];
			}
		}
	}

	return maxcolor + 1;
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


void coloringwriter(int *coloring, uint size) {
	char path[] = "../../testing-files/coloring.txt";

	FILE *fptr = fopen(path, "w");

	for(uint i = 0; i < size; ++i) {
		fprintf(fptr, "%d,", coloring[i]);
	}
	fprintf(fptr, "\n");

	fclose(fptr);
}
