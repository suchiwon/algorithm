#include <stdio.h>

#define MAX_SIZE 500

int floor[MAX_SIZE + 1];
int saver[MAX_SIZE + 1];
int temp[MAX_SIZE + 1];

int max(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int main() {
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; i++) {
		floor[i] = 0;
	}

	scanf("%d",&floor[0]);

	for (int i = 2; i <= n; i++) {
		
		for (int j = 0; j < i; j++) {
			scanf("%d",&temp[j]);
		}

		saver[0] = temp[0] + floor[0];
		saver[i - 1] = temp[i - 1] + floor[i - 2];

		for (int j = 1; j < i - 1; j++) {
			saver[j] = max(floor[j - 1],floor[j]) + temp[j];
		}

		for (int j = 0; j < i; j++) {
			floor[j] = saver[j];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (ans < floor[i]) {
			ans = floor[i];
		}
	}

	printf("%d\n",ans);

	return 0;
}