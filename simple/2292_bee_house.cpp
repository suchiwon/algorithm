#include <stdio.h>

int main() {
	int i = 1,b = 1;

	int N;

	scanf("%d",&N);

	while (N > b) {
		b += 6 * i;
		i++;
	}

	printf("%d\n",i);

	return 0;
}


