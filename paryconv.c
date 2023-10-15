#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 10

void init_stack(int* top) {
	*top = -1;
}

void push(char stack[], char num, int* top) {
	if (*top >= MAX-1) {
		printf("Stack is Full");
		return;
	}
	stack[++(*top)] = num;
}

char pop(char stack[], int* top) {
	if (*top < 0) {
		printf("Stack is empty");
		return;
	}
	return(stack[(*top)--]);
}

void paryconvert(int dec, int p) {
	int top;
	char stack[MAX];
	char num[17] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','\0' };
	init_stack(&top);

	while (dec >= p) {
		push(stack, num[dec % p], &top);
		dec /= p;
	}
	push(stack,num[dec], &top);

	printf("%d-ary number : ",p);

	while (top >= 0) {
		printf("%c", pop(stack, &top));
	}
	printf("\n");
}

int main() {
	int num, p;
	printf("****Convert a nonnegative decimal number to a p-ary number****\n");
	printf("Insert Decimal Number : ");
	scanf("%d", &num);
	printf("Insert p (2<= p <=16) : ");
	scanf("%d", &p);
	
	paryconvert(num, p);

	return 0;
}