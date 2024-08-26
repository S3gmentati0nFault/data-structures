#include <stdbool.h>
#include "../utilities/utilities.h"

#ifndef COLORING_H
#define COLORING_H

#define NO_COLOR -1

	int *naivecoloring(graph *G);

	int *miscoloring(graph *G);

	int miscolorpicker(list *I, graph *G, int *colors);

	uint colorpicker(uint vertex, graph *G, int *colors);

	void coloringwriter(int *coloring, uint size);

#endif
