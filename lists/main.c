#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
	// Empty list construction test
	list *list = emptylistconstructor();
	printf("%d\n", list->length);
	printf("\n\n\n");

	// Addition test
	push(list, 3);
	push(list, 4);
	push(list, 5);
	listprinter(list);
	printf("\n\n\n");


	// Removal test
	node *i = pop(list);
	printf("%d\n", i->value);
	free(i);
	printf("\n\n\n");

	// Deconstruction test
	listdeconstructor(list);

	return 0;
}
