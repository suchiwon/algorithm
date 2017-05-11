#include <stdio.h>

int main() {
	int N, L, div, dum, start, end;

	scanf("%d %d",&N,&L);

	for (int i = L; i <= 100; i++) {
		div = N/i;

		dum = (i * (i-1))/2;

		start = 0;
		end = i - 1;

		for (int j = 1; j <= i; j++) {
			if (((div * i) + dum) == N && (div + start) >= 0) {
				for (int k = start; k <= end; k++) {
					if (k != end) {
						printf("%d ",div + k);
					} else {
						printf("%d\n",div + k);
					}
				}

				return 0;
			} else {
				start--;
				dum += start;
				dum -= end;
				end--;
			}
		}
	}

	puts("-1");
}