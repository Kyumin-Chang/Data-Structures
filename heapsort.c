#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef char element;

typedef struct node {

	element key;

} node;

typedef struct _Heap {

	node heap[MAX_ELEMENTS];
	int heap_size;

}Heap;

void push(Heap* h, element item ) {
	
	if (HEAP_FULL((h->heap_size))) {
		printf("The heap is FULL. \n");
		exit(1);
	}

	int i;
	i = ++(h->heap_size);
	
	while ((i != 1) && (item > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i].key = item;
}

element pop(Heap *h) {
	if (HEAP_EMPTY(h->heap_size)) {
		printf("The heap is Empty. \n");
		exit(1);
	}

	int parent = 1;
	int child = 2;
	node item, tmp;

	item = h->heap[1];
	tmp = h->heap[(h->heap_size)--];

	while (h->heap_size >= child) {
		if ((h->heap_size > child) && (h->heap[child].key) < h->heap[child + 1].key) {
			child++;
		}

		if (tmp.key >= h->heap[child].key) {
			break;
		}

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent] = tmp;

	return item.key;
}

void printnode(element src[]) {
	for (int i = 1; i <= strlen(src); i++) {
		printf("%3c", src[i]);
		if (i == 1 || i == 3 || i == 6 || i == 10 || i == 15 || i == 21 || i == 28) { printf("\n"); }
	}
}

void EraseEmptySpace(char a[]) {
	char tmp[40];
	int index = 0;

	for (int i = 0; a[i] != 0; i++) {
		if (a[i] != ' ') {
			tmp[index] = a[i];
			index++;
		}
	}
	tmp[index] = 0;

	index = 0;
	for (int i = 0; tmp[i] != 0; i++) {
		a[index] = tmp[i];
		index++;
	}
	a[index] = 0;
}

int main() {

	char src[] = "I am a computer genius";
	EraseEmptySpace(src);

	int a = strlen(src);
	
	Heap h;
	h.heap_size = 0;


	for (int i = 0; i <= a; i++) {
		push(&h, src[i]);
	}

	
	for (int i = (a - 1); i >= 0; i--) {
		src[i] = pop(&h);
	}
	
	printnode(src);

	return 0;

}