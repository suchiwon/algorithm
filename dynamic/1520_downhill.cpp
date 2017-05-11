#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 500
#define NOT_INIT -1

int arr[MAX_SIZE + 1][MAX_SIZE + 1];
int dp[MAX_SIZE + 1][MAX_SIZE + 1];

int N, M;

int dfs(int col, int row) {
	if (col == N && row == M) {
		return 1;
	} else if (dp[col][row] == NOT_INIT) {
			dp[col][row] = 0;
		if (col > 1) {
			if (arr[col - 1][row] < arr[col][row]) {
				dp[col][row] += dfs(col - 1, row);
			}
		}

		if (col < N) {
			if (arr[col + 1][row] < arr[col][row]) {
				dp[col][row] += dfs(col + 1,row);
			}
		}

		if (row > 1) {
			if (arr[col][row - 1] < arr[col][row]) {
				dp[col][row] += dfs(col, row - 1);
			}
		}

		if (row < M) {
			if (arr[col][row + 1] < arr[col][row]) {
				dp[col][row] += dfs(col, row + 1);
			}
		}
	}

	return dp[col][row];
}

int main() {
	scanf("%d %d",&N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d",&arr[i][j]);
		}
	}

	memset(dp,NOT_INIT,sizeof(dp));

	int ans = dfs(1,1);

	printf("%d\n",ans);

	return 0;
}