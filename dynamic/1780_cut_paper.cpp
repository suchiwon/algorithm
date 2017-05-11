#include <stdio.h>

#define MAX_SIZE 2187
#define CUTTING -2

int arr[MAX_SIZE + 1][MAX_SIZE + 1];

int minus = 0;
int zero = 0;
int one = 0;

int cut(int lp_x, int lp_y, int size) {
	if (size == 1) {
		return arr[lp_x][lp_y];
	}

	int val[9];

	size = size/3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			val[i * 3 + j] = cut(lp_x + (size * i), lp_y + (size * j),size);
		}
	}

	for (int i = 1; i < 9; i++) {
		if (val[0] != val[i]) {
			for (int j = 0; j < 9; j++) {
				if (val[j] == -1) {
					minus++;
				} else if (val[j] == 0) {
					zero++;
				} else if (val[j] == 1) {
					one++;
				}
			}

			return CUTTING;
		}
	}

	return val[0];
}

int main() {
	int N;

	scanf("%d",&N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d",&arr[i][j]);
		}
	}

	cut(0,0,N);

	printf("%d\n%d\n%d\n",minus,zero,one);

	return 0;
}