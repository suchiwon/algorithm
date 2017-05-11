#include <stdio.h>

int room[15][15];

int main() {
	int T;
	int a,b;

	scanf("%d",&T);

	for (int i = 1; i <= 14; i++) {
		room[0][i] = i;
	}

	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			room[i][j] = 0;

			for (int k = 1; k <= j; k++) {
				room[i][j] += room[i - 1][k];
			}
		}
	}

	while (T--) {
		scanf("%d %d",&a,&b);
		
		printf("%d\n",room[a][b]);
	}

	return 0;
}