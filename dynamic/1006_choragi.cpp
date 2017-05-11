#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

#define MAX	2147483647

int arr[MAX_SIZE + 1][2];
int W;

int dp[MAX_SIZE + 1][4];

void GetNext(int idx, int next_idx) {

	dp[next_idx][0] = dp[idx][3];

	if (arr[idx][0] + arr[next_idx][0] <= W) {
		dp[next_idx][1] = std::min(dp[idx][2],dp[idx][3]) + 1;
	} else {
		dp[next_idx][1] = dp[idx][3] + 1;
	}

	if (arr[idx][1] + arr[next_idx][1] <= W) {
		dp[next_idx][2] = std::min(dp[idx][1],dp[idx][3]) + 1;
	} else {
		dp[next_idx][2] = dp[idx][3] + 1;
	}

	dp[next_idx][3] = MAX;

	if (arr[next_idx][0] + arr[next_idx][1] <= W) {
		dp[next_idx][3] = dp[idx][3] + 1;
	} 

	if (arr[idx][0] + arr[next_idx][0] <= W && arr[idx][1] + arr[next_idx][1] <= W) {
		dp[next_idx][3] = std::min(dp[idx][0] + 2,dp[next_idx][3]);
	} 

	dp[next_idx][3] = std::min(dp[next_idx][3],std::min(dp[next_idx][1],dp[next_idx][2]) + 1);
}

int algorithm(int start, int end, int flag) {

	for (int i = start; i <= end; i++) {

		GetNext(i-1,i);
	}

	return dp[end][flag];
}

int main() {
	int T;

	scanf("%d",&T);

	while (T--) {
		int N;
		int ans = MAX, temp;

		scanf("%d %d",&N,&W);

		for (int i = 0; i < N; i++) {
			scanf("%d",&arr[i][0]);
		}

		for (int i = 0; i < N; i++) {
			scanf("%d",&arr[i][1]);
		}

		if (N == 1) {
			if (arr[0][0] + arr[0][1] <= W) {
				puts("1");
			} else {
				puts("2");
			}

			continue;
		}

		/*
			case 1. from 0 to N - 1
		*/
		dp[0][0] = 0;
		dp[0][1] = 1;
		dp[0][2] = 1;

		if (arr[0][0] + arr[0][1] <= W) {
			dp[0][3] = 1;
		} else {
			dp[0][3] = 2;
		}

		temp = algorithm(1,N-1,3);

		if (ans > temp) {
			ans = temp;
		}

		/*
			case 2. pre-calc N - 1, 0 and from 1 to N - 2
		*/
		dp[N-1][0] = 0;
		dp[N-1][1] = 1;
		dp[N-1][2] = 1;

		if (arr[N-1][0] + arr[N-1][1] <= W) {
			dp[N-1][3] = 1;
		} else {
			dp[N-1][3] = 2;
		}

		GetNext(N-1,0);

		temp = algorithm(1,N-2,3);

		if (ans > temp) {
			ans = temp;
		}

		/*
			case 3. pre-calc N - 1, 0 bind arr[n-1][0] && arr[0][0] and from 1 to N - 1
		*/

		if (arr[N-1][0] + arr[0][0] <= W) {
			dp[0][0] = 1;
			dp[0][1] = 1;
			dp[0][2] = 2;
			dp[0][3] = 2;

			temp = algorithm(1,N-1,2);

			if (ans > temp) {
				ans = temp;
			}
		}

		if (arr[N-1][1] + arr[0][1] <= W) {
			dp[0][0] = 1;
			dp[0][1] = 2;
			dp[0][2] = 1;
			dp[0][3] = 2;

			temp = algorithm(1,N-1,1);

			if (ans > temp) {
				ans = temp;
			}
		}

		printf("%d\n",ans);
	}

	return 0;
}
