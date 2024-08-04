#import "priority.h"
#include <stdio.h>

#import <stdlib.h>

int main(int argc, char *argv[]) {
	pqueue *queue = voidconstructor();

	// Testing the empty queue
	queueprinter(queue);
	printf("\n\n\n");

	// Test immediate removal
	dequeue(queue);
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

	// Test repeated deletions
	for(int i = 0; i < 5; ++i) {
		printf("%d\n", dequeue(queue));
		queueprinter(queue);
		printf("\n\n");
	}

	// Clean the memory
	deconstructor(queue);

	return 0;
}
