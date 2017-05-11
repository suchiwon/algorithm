#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX_SIZE 3010
#define NOT_INIT -1
#define SOURCE 0
#define SINK 1
#define SECOND_LINE 2

using namespace std;

bool visited[MAX_SIZE];
int parent[MAX_SIZE];
int graph[MAX_SIZE][MAX_SIZE];

bool dfs(int idx, int size)
{
	if(idx == SINK)
		return true;
	else
	{
		for(int i = 0; i < size; i++)
		{
			if(graph[idx][i] > 0 && !visited[i])
			{
				visited[i] = true;
				parent[i] = idx;

				if(dfs(i, size))
					return true;
			}
		}

		return false;
	}
}

void backGraph()
{
	int idx = SINK;

	while(idx != SOURCE)
	{
		graph[parent[idx]][idx]--;
		graph[idx][parent[idx]]++;

		idx = parent[idx];
	}
}

int main()
{
	int N, M, K;
	int maxFlow = 0, temp, num;

	scanf("%d %d %d",&N, &M, &K);

	memset(graph,0,sizeof(graph));
	memset(visited,0,sizeof(visited));
	memset(parent,0,sizeof(parent));

	graph[SOURCE][SECOND_LINE] = K;

	for(int i = 0; i < N; i++)
	{
		graph[SOURCE][3 + i] = 1;
		graph[SECOND_LINE][3 + i] = 1;
	}

	for(int i = 0; i < M; i++)
	{
		graph[3 + N + i][SINK] = 1;
	}

	for(int i = 0; i < N; i++)
	{
		scanf("%d",&num);

		for(int j = 0; j < num; j++)
		{
			scanf("%d",&temp);

			graph[3 + i][2 + N + temp] = 1;
		}
	}

	while(dfs(SOURCE, 3 + N + M))
	{
		maxFlow++;
		backGraph();

		memset(visited,0,sizeof(visited));
	}

	printf("%d\n",maxFlow);

	return 0;
}


