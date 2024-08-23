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

	// Deletion test
	push(list, 7);
	push(list, 8);
	push(list, 9);
	listprinter(list);
	delete(list, 3);
	delete(list, 2);

	// Deconstruction test
	listdeconstructor(list);

	return 0;
}
