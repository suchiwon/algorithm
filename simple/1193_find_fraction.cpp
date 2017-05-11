#include <stdio.h>

int main() {

	int N;
	scanf("%d",&N);
	int i = 3;
	int start = 2;
	int end = 3;

	if (N == 1) {
		puts("1/1");
		return 0;
	}

	while (N > end) {
		start = end + 1;
		end += i++;
	}

	if (i%2 == 0) {
		printf("%d/%d\n",i - 1 - (N - start), N - start + 1);
	} else {
		printf("%d/%d\n",N - start + 1, i - 1 - (N - start));
	}

	return 0;
}