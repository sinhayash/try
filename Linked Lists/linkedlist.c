#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* next;
	int data;
};

typedef struct node node;
typedef node* list;

list newNode(int d) {
	list node = (list)malloc(sizeof(node));
	node->next = NULL;
	node->data = d;
	return node;
}

void print(list l) {
	if(l == NULL)
		printf("NULL\n");
	else {
		while(l != NULL) {
			printf("%d->", l->data);
			l = l->next;
		}
		printf("NULL\n");
	}
	return;
}

int lengthIter(list l) {
	list cur = l;
	int count = 0;

	while(cur != NULL) {
		count++;
		cur = cur->next;
	}
	return count;
}

int __lengthRecur(list l, int count) {
	if(l == NULL)
		return count;
	return __lengthRecur(l->next, count+1);
}

int lengthRecur(list l) {
	return __lengthRecur(l, 0);
}

void push(list* headRef, int data) {
	//Using pointer to list (pointer to pointer to node)
	list n = newNode(data);
	n->next = *headRef;
	*headRef = n;
}

list push2(list headRef, int data) {
	//returning updated list, caller has to take care.
	list n = newNode(data);
	n->next = headRef;
	headRef = n;
	return n;
}

list appendNode(list* headRef, int data) {
	list n = newNode(data);
	list current = *headRef;

	if(current == NULL)
		*headRef = n;
	else {
		while(current->next != NULL)
			current = current->next;
		current->next = n;
	}
}

list appendNode2(list headRef, int data) {
	//returning updated list, caller has to take care.
	list n = newNode(data);
	list current = headRef;

	if(current == NULL)
		headRef = n;
	else {
		while(current->next != NULL)
			current = current->next;
		current->next = n;
	}
	return headRef;
}

list appendNodewithPush(list* headRef, int data) {
	list current = *headRef;

	if(current == NULL)
		push(headRef, data);
	else {
		while(current->next != NULL)
			current = current->next;
		push(&(current->next), data);
	}
}

list copyList(list l) {
	list current = l;
	list newList = NULL;
	list tail = NULL; //tail of newList

	if(current == NULL)
		return newList;
	else {
		while(current != NULL) {
			if(newList == NULL) {
				//special case: push head to newList
				push(&newList, current->data);
				tail = newList;
			}
			else {
				appendNode(&newList, current->data);
				tail = tail->next;
			}
			current = current->next;
		}
	}
	return newList;
}

list copyListRecur(list l) {
	// uses stack space proportional to the length of its list, hence not good for production.
	if(l == NULL)
		return NULL;
	list newList = newNode(l->data);
	newList-> next = copyListRecur(l->next);

	return newList;
}

int main(int argc, char const *argv[]) {
	list l = newNode(1);
	appendNode(&l, 2);
	l = appendNode2(l, 6);
	appendNodewithPush(&l, 3);
	push(&l, 4);
	l = push2(l, 5);
	print(l);
	printf("Count is %d\n", lengthIter(l));
	printf("Count is %d\n", lengthRecur(l));
	list l2 = copyList(l);
	print(l2);
	list l3 = copyListRecur(l);
	print(l3);
	return 0;
}