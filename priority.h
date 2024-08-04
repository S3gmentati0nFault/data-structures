#include <stdbool.h>
#ifndef PRIORITY_H
#define PRIORITY_H
#define ERROR_VALUE -1234567890

	typedef int data_type;
	typedef unsigned int uint;

	typedef struct {
		data_type *vector;
		uint size;
	} pqueue;

	pqueue *voidconstructor();

	void enqueue(pqueue *queue, data_type element);

	data_type dequeue(pqueue *queue);

	bool memcheck(data_type *vector);

	void queueprinter(pqueue *queue);

	void deconstructor(pqueue *queue);

#endif
