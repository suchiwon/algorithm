#include <stdio.h>
#include <string.h>

#define MAX_SIZE 2010

int graph[MAX_SIZE][MAX_SIZE];

int parent[MAX_SIZE];
int visited[MAX_SIZE];
int sink, N, M;

void backGraph(int idx)
{
	while(idx != 0)
	{
		graph[parent[idx]][idx]--;
		graph[idx][parent[idx]]++;

		idx = parent[idx];
	}
}

bool dps(int idx)
{
	if(idx == sink)
		return true;
	else
	{
		for(int i = 0; i <= sink; i++)
		{
			if(graph[idx][i] > 0 && !visited[i])
			{
				visited[i] = true;
				
				parent[i] = idx;

				if(dps(i))
					return true;
			}
		}

		return false;
	}
}

int main()
{
	int maxFlow = 0, num, temp;

	scanf("%d %d",&N, &M);

	sink = N + M + 1;

	memset(graph,0,sizeof(graph));
	memset(visited,0,sizeof(visited));
	memset(parent,0,sizeof(parent));

	for(int i = 1; i <= N; i++)
	{
		scanf("%d",&num);

		for(int j = 0; j < num; j++)
		{
			scanf("%d",&temp);

			graph[i][N + temp] = 1;
		}
	}

	for(int i = 1; i <= N; i++)
		graph[0][i] = 2;

	for(int i = N + 1; i <= N + M; i++)
		graph[i][sink] = 1;

	while(dps(0))
	{
		maxFlow++;
		backGraph(sink);

		memset(visited,0,sizeof(visited));
	}

	printf("%d\n",maxFlow);

	return 0;
}