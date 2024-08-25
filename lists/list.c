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

	while(i != NULL) {
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
		list->length = 1;
		return;
	}

	newnode->next = list->head;
	list->head = newnode;
	list->length = list->length + 1;
}


node *pop(list *list) {
	node *i = list->head;

	list->head = list->head->next;
	list->length = list->length - 1;

	return i;
}


node *delete(list *list, data_type value) {
	node *curr = list->head;
	node *prev = NULL;

	if(curr == NULL) {
		printf("The list is empty\n");
		return NULL;
	}

	if(curr->value == value) {
		list->head = curr->next;
		list->length = list->length - 1;
		return curr;
	}

	while(curr != NULL) {
		if(curr->value == value) {
			prev->next = curr->next;
			list->length = list->length - 1;
			return curr;
		}
		prev = curr;
		curr = curr->next;
	}

	printf("The element was not in the list\n");
	return NULL;
}


void listprinter(list *list) {
	node *i = list->head;

	while(i != NULL) {
		printf("%d\n", i->value);
		i = i->next;
	}

	return;
}


bool isempty(list *list) {
	if(list->length == 0) {
		return true;
	}

	return false;
}
