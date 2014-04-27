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

int main(int argc, char const *argv[]) {
	list l = newNode(1);
	list second = newNode(2);
	list third = newNode(3);
	l->next = second;
	second->next = third;
	print(l);
	printf("Count is %d\n", lengthIter(l));
	printf("Count is %d\n", lengthRecur(l));
	return 0;
}