#include "../utilities/utilities.h"
#include "../../lists/simple/list.h"

#ifndef MIS_H
#define MIS_H

	list *mis(graph *G);

	void deleteneighbours(list *V, uint vertex, graph *G);

	void writemis(list *mis);

#endif
