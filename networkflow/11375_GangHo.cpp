#include <stdio.h>
#include <string.h>
#include <vector>

#define NOT_INIT -1
#define MAX_SIZE 1000

using namespace std;

int match[MAX_SIZE + 1];
bool visited[MAX_SIZE + 1];
vector< vector<int> > graph;

bool matching(int idx)
{
	if(visited[idx])
		return false;
	else
	{
		visited[idx] = true;

		for(int i = 0; i < graph[idx].size(); i++)
		{
			if(match[graph[idx][i]] == NOT_INIT || matching(match[graph[idx][i]]))
			{
				match[graph[idx][i]] = idx;

				return true;
			}
		}

		return false;
	}
}

int main()
{
	int N, M, num, temp, count = 0;

	scanf("%d %d",&N, &M);

	graph.resize(N + 1);

	for(int i = 1; i <= N; i++)
	{
		scanf("%d",&num);

		for(int j = 0; j < num; j++)
		{
			scanf("%d",&temp);

			graph[i].push_back(temp);
		}
	}

	memset(match,NOT_INIT,sizeof(match));

	for(int i = 0; i < N; i++)
	{
		memset(visited,false,sizeof(visited));

		if(matching(i + 1))
			count++;
	}

	printf("%d\n",count);

	return 0;
}