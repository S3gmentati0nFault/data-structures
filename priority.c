#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "priority.h"

// Implementation of a "void constructor" for the queue
pqueue *voidconstructor() {
	pqueue *queue = (pqueue *)malloc(sizeof(pqueue));

	queue->vector = NULL;
	queue->size = 0;
	return queue;
}

// Implementation of a deconstructor for the queue
void deconstructor(pqueue *queue) {
	// Free the internal vector
	free(queue->vector);
	// Free the queue structure
	free(queue);
}

// Implementation of the enqueue operation
void enqueue(pqueue *queue, data_type element) {
	data_type *vector;
	uint size;

	// If the queue is empty just put the element as first element in the queue
	if (queue->vector == NULL) {
		size = 1;
		vector = (data_type *)malloc(sizeof(data_type));
		// Check for memory allocation errors
		if(!memcheck(vector)) {
			return;
		}

		vector[0] = element;

		queue->vector = vector;
		queue->size = size;
		return;
	}

	// Otherwise the element has to be added at the end of the queue
	size = queue->size + 1;
	vector = (data_type *)malloc(size * sizeof(data_type));
	// Check for memory allocation errors
	if(!memcheck(vector)) {
		return;
	}
	
	// Copy the contents of the other vector in the new one
	for (uint i = 0; i < size - 1; ++i) {
		vector[i] = queue->vector[i];
	}
	vector[size - 1] = element;

	// Update the parameters
	free(queue->vector);
	queue->vector = vector;
	queue->size = size;
}


// Implementation of the dequeue operation


// Implementation of a simple memory checker
bool memcheck(data_type *vector) {
	if(vector == NULL) {
		printf("There was a problem during the memory allocation process");
		free(vector);
		return false;
	}

	return true;
}


// Implementation of a simple printer
void queueprinter(pqueue *queue) {
	for(uint i = 0; i < queue->size; ++i) {
		printf("%d\t", queue->vector[i]);
	}
}
