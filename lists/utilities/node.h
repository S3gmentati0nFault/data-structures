#ifndef NODE_H
#define NODE_H

	typedef int data_type;
	typedef struct node node;

	struct node {
		data_type value;
		struct node *next;
	};

	node *nodeconstructor(data_type value);

	node *emptynodeconstructor();

#endif
