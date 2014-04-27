#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* next;
	int data;
};

typedef struct node node;
typedef node* list;

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

int main(int argc, char const *argv[]) {
	list l = (list)malloc(sizeof(list));
	l->next = NULL;
	l->data = 1;
	print(l);
	return 0;
}