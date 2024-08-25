#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef MUTILS_H
#define MUTILS_H

	static inline void *mallocordie(size_t memsize) {
		 void *allocmem = malloc(memsize);
		    /* Some implementations return null on a 0 length alloc,
		     * we may as well allow this as it increases compatibility
		     * with very few side effects */
		    if(!allocmem && memsize)
		    {
			printf("Could not allocate memory!");
			exit(-1);
		    }
		    return allocmem;
	}

#endif
