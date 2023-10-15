#include <stdio.h>

int num = 0; 

void hanoi(int n, int a, int b, int c) { 
	
	if (n == 1) {
		printf("The upmost disk in rod %d is moved to rod %d\n", a, c);
		num++;
	}
	
	else {
		hanoi(n - 1, a, c, b);
		printf("The upmost disk in rod %d is moved to rod %d\n", a, c);
		num++;
		hanoi(n - 1, b, a, c);
	}

}

int main(void) {
	int n;
	printf("Enter the desired number (Hanoi_Tower) : ");
	scanf_s("%d", &n);
	hanoi(n, 1, 2, 3);
	printf("Thus the minimal number of moves is %d", num);

	return 0;
}