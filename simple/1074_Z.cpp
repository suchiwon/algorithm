#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int r,c;

void search(int x_start, int y_start, int size, long long b_start) {
	if (size == 1 && x_start == r && y_start == c) {
		printf("%lld\n",b_start);
	} else if (size > 1) {
		size = size/2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (r >= x_start + (i * size) && r < x_start + ((i + 1) * size) && c >= y_start + (j * size) && c < y_start + ((j + 1) * size)) {
					search(x_start + (i * size), y_start + (j * size), size, b_start + ((i * 2 + j) * size * size));
				}
			}
		}
	}
}

int main() {
	int N;

	while (scanf("%d %d %d",&N,&r,&c) != EOF) {

		int temp = (int)pow(2.0,N);

		search(0,0,temp,0);
	}

	return 0;
}