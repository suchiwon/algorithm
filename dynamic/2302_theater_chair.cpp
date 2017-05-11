#include <stdio.h>
#include <string.h>
#define NOT_INIT -1

int dp[41];

int get_dp(int n)
{
	if(dp[n] != NOT_INIT)
		return dp[n];
	else
	{
		dp[n] = get_dp(n - 1) + get_dp(n - 2);
		return dp[n];
	}
}

int main()
{
	int N, K, temp = 0, temp2, i, count = 1;

	memset(dp,NOT_INIT,sizeof(dp));

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	scanf("%d",&N);
	scanf("%d",&K);

	for(i = 0; i < K; i++)
	{
		scanf("%d",&temp2);

		count *= get_dp(temp2 - 1 - temp);

		temp = temp2;
	}

	count *= get_dp(N - temp);

	printf("%d\n",count);

	return 0;
}