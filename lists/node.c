#include <stdlib.h>

#include "node.h"

node *nodeconstructor(data_type value) {
	node *newnode = (node *) malloc(sizeof(node));
	
	newnode->value = value;
	newnode->next = NULL;

	return newnode;
}


node *emptynodeconstructor() {
	node *newnode = (node *) malloc(sizeof(node));
	
	newnode->value = 0;
	newnode->next = NULL;

	return newnode;
}
