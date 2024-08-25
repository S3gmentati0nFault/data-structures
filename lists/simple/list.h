#include <stdbool.h>

#include "../utilities/node.h"

#ifndef LIST_H
#define LIST_H

	typedef unsigned int uint;
	
	typedef struct{
		node *head;
		uint length;
	} list;

	list *emptylistconstructor();

	void listdeconstructor(list *list);

	bool isempty(list *list);

	void push(list *list, data_type value);

	node *pop(list *list);

	node *removelement(list *list, data_type value);

	void enqueue(list *list, data_type value);

	node *dequeue(list *list);

	void listprinter(list *list);

#endif
