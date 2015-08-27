#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int c[] = {5, 3, 2};
int ct = 0;
int step(int depth, int maxDiv, int dynAmount, int amount) {
	int rem, i, temp;
	temp = maxDiv;
	if (maxDiv == -2) {
		maxDiv = floor(dynAmount/c[depth]);
	}
	
	for (maxDiv; maxDiv >=0; maxDiv--) {
		rem = dynAmount - maxDiv * c[depth];
		if (rem == 0) {
			ct++;
		} else {
			step(depth, --maxDiv, rem, amount);
		}
		
		step(depth, --maxDiv, amount, amount);
	}
	
	if (--depth >= 0 && temp == -2)
	step(depth, -2, amount, amount);
	
	return 0;
	
}

int main() {
	int n;
	scanf("%d", &n);
	step(2, -2, n, n);
	printf("%d", ct);
	return 0;
}