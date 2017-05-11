#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define MAX_SIZE 50
#define NOT_INIT -1

using namespace std;

int matching[MAX_SIZE + 1];
bool visited[MAX_SIZE + 1];
vector< vector<int> > graph;
vector< vector<int> > edge;
vector<int> matchSet;

bool dps(int idx)
{
	if(visited[idx])

		return false;
	else
	{
		visited[idx] = true;

		for(int i = 0; i < graph[idx].size(); i++)
		{
			if(matching[graph[idx][i]] == NOT_INIT || dps(matching[graph[idx][i]]))
			{
				matching[graph[idx][i]] = idx;

				return true;
			}
		}

		return false;
	}
}

int main()
{
	int N, temp, matched = 0;

	bool bFirstOdd = true;

	edge.resize(2);

	scanf("%d",&N);

	scanf("%d",&temp);

	if(temp%2 == 0)
		bFirstOdd = false;
	else
		bFirstOdd = true;

	edge[temp%2].push_back(temp);

	for(int i = 1; i < N; i++)
	{
		scanf("%d",&temp);

		edge[temp%2].push_back(temp);
	}

	if(bFirstOdd)
		swap(edge[0],edge[1]);

	if(edge[0].size() != edge[1].size())
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		graph.resize(edge[0].size());

		for(int i = 0; i < edge[0].size(); i++)
		{
			for(int j = 0; j < edge[0].size(); j++)
			{
				int num = edge[0][i] + edge[1][j];
				int k;

				for(k = 2; k * k <= num; k++)
					if(num%k == 0) break;

				if(k * k > num)
					graph[i].push_back(j);
			}
		}
	}

	for(int i = 0; i < graph[0].size(); i++)
	{
		memset(matching,NOT_INIT,sizeof(matching));

		matching[graph[0][i]] = 0;
		matched = 1;

		for(int j = 1; j < edge[0].size(); j++)
		{
			memset(visited,false,sizeof(visited));
			visited[0] = true;

			if(dps(j))
				matched++;
		}

		if(matched == edge[0].size())
			matchSet.push_back(edge[1][i]);
	}

	if(matchSet.empty())
		printf("-1\n");
	else
	{
		sort(matchSet.begin(), matchSet.end());
		for(int i = 0; i < matchSet.size(); i++)
			printf("%d ",matchSet[i]);
	}

	return 0;
}