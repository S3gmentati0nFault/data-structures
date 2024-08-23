#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "node.h"

list *emptylistconstructor() {
	list *list = malloc(sizeof(list));

	list->head = NULL;
	list->length = 0;

	return list;
}


void listdeconstructor(list *list) {
	node *i = list->head;

	while(i->next != NULL) {
		node *j = i->next;
		free(i);
		i = j;
	}

free(i);
	free(list);
	return;
}


void push(list *list, data_type value) {
	node *newnode = nodeconstructor(value);

	if(list->head == NULL) {
		list->head = newnode;
		return;
	}

	newnode->next = list->head;
	list->head = newnode;
}


void listprinter(list *list) {
	node *i = list->head;

	while(i != NULL) {
		printf("%d\n", i->value);
		i = i->next;
	}

	return;
}


node *pop(list *list) {
	node *i = list->head;

	list->head = list->head->next;

	return i;
}
