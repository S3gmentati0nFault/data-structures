#import "priority.h"
#include <stdio.h>

#import <stdlib.h>

int main(int argc, char *argv[]) {
	pqueue *queue = (pqueue *)malloc(sizeof(pqueue));

	// Testing the empty queue
	queueprinter(queue);
	printf("\n\n\n");

	// Test simple insertion
	enqueue(queue, 10);
	queueprinter(queue);
	printf("\n\n\n");

	// Test repeated insertions
	enqueue(queue, 11);
	enqueue(queue, 12);
	enqueue(queue, 13);
	queueprinter(queue);
	printf("\n\n\n");

	return 0;
}
