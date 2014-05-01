#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
	struct node* next;
	int data;
};

typedef struct node node;
typedef node* list;

#endif /*LINKEDLIST_H*/