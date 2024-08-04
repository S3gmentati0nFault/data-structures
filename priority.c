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

		// Update the parameters
		structupdate(queue, vector, size);
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
	structupdate(queue, vector, size);
}


// Implementation of the dequeue operation
data_type dequeue(pqueue *queue) {
	
	// If the queue is empty there is nothing to dequeue anymore
	if(queue->size == 0) {
		printf("The queue is already empty\n");
		return ERROR_VALUE;
	}

	// Otherwise create a new vector with one less element (the one at the top is cut
	// out)
	
	uint size = queue->size - 1;
	data_type element = queue->vector[0];
	// Checking if the queue is made of one element or less
	if (size < 1) {
		printf("Returning the last element of the queue\n");

		// Update the parameters
		structupdate(queue, NULL, size);

		return element;
	}
	
	data_type *vector = (data_type *)malloc((size) * sizeof(data_type));
	// Check for memory allocation errors
	if(!memcheck(vector)) {
		return ERROR_VALUE;
	}
	
	for(uint i = 0; i < size; i++) {
		vector[i] = queue->vector[i + 1];
	}

	// Update the parameters
	structupdate(queue, vector, size);

	return element;
}


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


// Implementation of a simple setter for the fields
void structupdate(pqueue *queue, data_type *vector, uint size) {

	free(queue->vector);
	queue->vector = vector;
	queue->size = size;
}
