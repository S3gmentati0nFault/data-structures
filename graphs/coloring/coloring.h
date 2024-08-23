#include <stdbool.h>
#include "../utilities/utilities.h"

#ifndef COLORING_H
#define COLORING_H

#define NO_COLOR -1

	int *naivecoloring(graph *G);

	uint colorpicker(uint vertex, graph *G, int *colors);

#endif
