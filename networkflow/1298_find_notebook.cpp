#include <stdio.h>
#include <string.h>
#include <vector>

#define NOT_INIT -1

using namespace std;

int matching[5001];
vector< vector<int> > graph;
int visited[101];

bool dps(int idx)
{
	if(visited[idx])
		return false;
	else
	{
		visited[idx] = true;

		for(int i = 0; i < graph[idx].size(); i++)
		{
			if(matching[graph[idx][i]] == NOT_INIT || dps(graph[idx][i]))
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
	int N, M, temp, temp2, matched = 0;

	scanf("%d %d",&N, &M);

	graph.resize(101);

	for(int i = 0; i < M; i++)
	{
		scanf("%d %d",&temp, &temp2);

		graph[temp - 1].push_back(temp2);

	}

	memset(matching,NOT_INIT,sizeof(matching));

	for(int i = 0; i < N; i++)
	{
		memset(visited,0,sizeof(visited));

		if(dps(i))
			matched++;
	}
	
	printf("%d\n",matched);

	return 0;
}