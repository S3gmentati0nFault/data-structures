#include <stdbool.h>
#ifndef PRIORITY_H
#define PRIORITY_H

	typedef int data_type;
	typedef unsigned int uint;

	typedef struct {
		data_type *vector;
		uint size;
	} pqueue;

	void enqueue(pqueue *queue, data_type element);

	data_type dequeue(pqueue *queue);

	bool memcheck(data_type *vector);

	void queueprinter(pqueue *queue);

#endif
