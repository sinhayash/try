#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

//Attempted questions at http://cslibrary.stanford.edu/105/LinkedListProblems.pdf
//Linked List Problems, CS Library, Stanford.

/*
 Build the list {1, 2, 3} in the heap and store
 its head pointer in a local stack variable.
 Returns the head pointer to the caller.
*/
list buildOneTwoThree() {
	list head = (node*)malloc(sizeof(node));
	list second = (node*)malloc(sizeof(node));
	list third = (node*)malloc(sizeof(node));
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	return head;
}

int main(int argc, char const *argv[]) {
	list l = buildOneTwoThree();
	return 0;
}