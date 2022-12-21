#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;


void Hanoi(int n, int a, int b, int c) {
	if (n == 1) {
		printf("%d %d\n", a, c);
		return;
	}
	else {
		Hanoi(n - 1, a, c, b);
		printf("%d %d\n", a,c );
		Hanoi(n - 1, b, a, c);
	}

}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", (int)pow(2,N)-1);
	Hanoi(N, 1, 2, 3);
	
	return 0;
}