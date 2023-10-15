#include <stdio.h>

int num = 0;

void moveprint(int a, int b) {
	printf("The upmost disk in rod %d is moved to rod %d\n", a, b);
	num++;
}
void hanoi2(int n, int a, int b, int c) { 
	
	if (n == 1) {
		moveprint(a, b);
		moveprint(b, c);
	}
	
	else {
		hanoi2(n - 1, a, b, c);
		moveprint(a, b);
		hanoi2(n - 1, c, b, a);
		moveprint(b, c);
		hanoi2(n - 1, a, b, c);
	}

}

int main(void) {
	int n;
	scanf_s("%d", &n);
	hanoi2(n, 1, 2, 3);
	printf("Thus, the minimal number of moves is %d", num);

	return 0;
}