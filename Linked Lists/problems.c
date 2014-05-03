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

/*
 Given a list and an int, return the number of times that int occurs
 in the list.
*/
int count(list head, int searchFor) {
	int count = 0;
	while(head != NULL) {
		if(head->data == searchFor) count++;
		head = head->next;
	}
	return count;
}

/*
 Given a list and an index, return the data
 in the nth node of the list. The nodes are numbered from 0.
 Assert fails if the index is invalid (outside 0..lengh-1).
*/
int getNth(list head, int index) {
	int current = 0;//current index

	while(head != NULL) {
		if(current == index)
			return head->data;
		current++;
		head = head->next;
	}
	return -1;//returns -1 by default if index not found
}


/*
 deallocates all of its memory and sets its head pointer to NULL
*/
void deleteList(list* headRef) {
	list current = *headRef;
	list next;
	while(current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	*headRef = NULL;
}

int main(int argc, char const *argv[]) {
	list l = buildOneTwoThree();
	printf("Count of 2 in list is %d.\n", count(l, 2));
	printf("Data at 2nd index in list l is %d.\n", getNth(l, 2));
	deleteList(&l);
	return 0;
}