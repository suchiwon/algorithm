#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#define MAX_SIZE 1000
#define NOT_INIT -1

using namespace std;

int dp[MAX_SIZE + 1][MAX_SIZE + 1];
vector< pair<int,int> > mission;
int size;

int getDp(int first, int second, int M)
{
	if(first == M || second == M)
		return 0;
	else if(dp[first][second] == NOT_INIT)
	{
		int idx = max(first, second) + 1;

		int diff, cop1, cop2;

		if(first == 0)
			cop1 = mission[idx].first + mission[idx].second - 2;
		else
			cop1 = abs(mission[idx].first - mission[first].first) + abs(mission[idx].second - mission[first].second);

		cop1 += getDp(idx, second, M);

		if(second == 0)
			cop2 = abs(size - mission[idx].first) + abs(size - mission[idx].second);
		else
			cop2 = abs(mission[idx].first - mission[second].first) + abs(mission[idx].second - mission[second].second);

		cop2 += getDp(first, idx, M);

		dp[first][second] = min(cop1,cop2);	
	}

	return dp[first][second];
}

void getPath(int first, int second, int M)
{
	int idx = 0, cop1 = 0, cop2 = 0;

	if(first == M || second == M)
		return;
	else
	{
		idx = max(first, second) + 1;

		if(first == 0)
			cop1 = mission[idx].first + mission[idx].second - 2;
		else
			cop1 = abs(mission[idx].first - mission[first].first) + abs(mission[idx].second - mission[first].second);

		cop1 += dp[idx][second];

		if(second == 0)
			cop2 = abs(size - mission[idx].first) + abs(size - mission[idx].second);
		else
			cop2 = abs(mission[idx].first - mission[second].first) + abs(mission[idx].second - mission[second].second);

		cop2 += dp[first][idx];

		if(cop1 < cop2)
		{
			puts("1");
			getPath(idx, second, M);
		}
		else
		{
			puts("2");
			getPath(first, idx, M);
		}
	}

}


int main()
{
	int M;
	int x, y;
	scanf("%d %d",&size, &M);

	mission.push_back(make_pair(0,0));

	for(int i = 1; i <= M; i++)
	{
		scanf("%d %d",&x,&y);
		mission.push_back(make_pair(x,y));
	}

	memset(dp,NOT_INIT,sizeof(dp));

	printf("%d\n",getDp(0, 0, M));
	getPath(0,0,M);

	return 0;
}