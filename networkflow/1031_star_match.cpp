#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX_SIZE 100
#define SOURCE 0

using namespace std;

int graph[MAX_SIZE + 5][MAX_SIZE + 5];
bool visited[MAX_SIZE + 5];
int parent[MAX_SIZE + 5];

int N, M, sink;

bool dfs(int idx)
{
	if(idx == sink)
		return true;
	else
	{
		for(int i = SOURCE; i <= sink; i++)
		{
			if(graph[idx][i] > 0 && !visited[i])
			{
				visited[i] = true;
				//graph[idx][i]--;
				//graph[i][idx]++;
				parent[i] = idx;
				
				if(dfs(i))
					return true;
			}
		}
	}

	return false;
}

void backGraph()
{
	int idx = sink;

	while(idx != SOURCE)
	{
		graph[parent[idx]][idx]--;
		graph[idx][parent[idx]]++;

		idx = parent[idx];
	}
}

int maxFlow(int size)
{
	int flow = 0;

	for(int i = 0; i < size; i++)
	{
		memset(visited,false,sizeof(visited));

		if(dfs(SOURCE))
		{
			flow++;
			backGraph();
		}
	}

	return flow;
}

int main()
{
	int aMatch = 0, bMatch = 0;

	scanf("%d %d", &N, &M);
	sink = N + M + 1;

	memset(graph,0,sizeof(graph));

	for(int i = 1; i <= N; i++)
	{
		scanf("%d",&graph[SOURCE][i]);
		aMatch += graph[SOURCE][i];
	}

	for(int i = 1; i <= M; i++)
	{
		scanf("%d",&graph[N + i][sink]);
		bMatch += graph[N + i][sink];
	}

	if(aMatch != bMatch)
	{
		puts("-1");
		return 0;
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
			graph[i][N + j] = 1;
	}

	if(aMatch != maxFlow(aMatch))
	{
		puts("-1");
	}
	else
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= M; j++)
			{
				if(graph[i][N + j] == 0)
				{
					graph[SOURCE][i]++;
					graph[N + j][sink]++;

					memset(visited,0,sizeof(visited));

					if(dfs(0))
					{
						printf("0");
						backGraph();
					}
					else
					{
						printf("1");
						graph[SOURCE][i]--;
						graph[N + j][sink]--;
					}
				}
				else
					printf("0");

				graph[i][N + j] = 0;
			}

			puts("");
		}
	}


	return 0;
}
