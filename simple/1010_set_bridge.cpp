#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30
#define NOT_INIT -1

long long dp[MAX_SIZE + 2][MAX_SIZE + 2];

long long algorithm(int left, int right) {
	if (dp[left][right] == NOT_INIT) {
		dp[left][right] = 0;
		dp[left][right] += 2 * algorithm(left, right - 1);
		dp[left][right] -= algorithm(left, right - 2);
	}

	return dp[left][right];
}

int main() {
	int T;
	int left, right;

	scanf("%d",&T);

	memset(dp,NOT_INIT,sizeof(dp));

	for (int i = 0; i <= MAX_SIZE; i++) {
		dp[i][i] = 1;
		dp[i][i+1] = i+1;
	}

	for (int i = 2; i <= MAX_SIZE; i++) {
		dp[0][i] = 1;
		dp[1][i] = i;
	}

	while (T--) {
		scanf("%d %d",&left, &right);

		printf("%lld\n",algorithm(left,right));
	}
}