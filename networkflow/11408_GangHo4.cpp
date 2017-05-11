#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

#define MAX_SIZE 810
#define SOURCE 0
#define SINK 1
#define INF 9999999

using namespace std;

pair<int, int> graph[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE];
int parent[MAX_SIZE];
bool bInQueue[MAX_SIZE];

bool bf(int size)
{
	int idx = SOURCE;
	queue<int> q;

	dist[SOURCE] = 0;

	for(int i = 1; i < size; i++)
	{
		dist[i] = INF;
		bInQueue[i] = false;
	}

	q.push(SOURCE);
	bInQueue[SOURCE] = true;

	while(!q.empty())
	{
		int idx = q.front();

		q.pop();
		bInQueue[idx] = false;

		for(int j = 0; j < size; j++)
		{
			if(graph[idx][j].first > 0)
			{
				if(dist[j] > dist[idx] + graph[idx][j].second)
				{
					dist[j] = dist[idx] + graph[idx][j].second;
					parent[j] = idx;

					if(!bInQueue[j])
					{
						q.push(j);
						bInQueue[j] = true;
					}
				}
			}
		}
	}

	if(dist[SINK] == INF)
		return false;
	else
		return true;
}

void backGraph()
{
	int idx = SINK;

	while(idx != SOURCE)
	{
		graph[parent[idx]][idx].first--;
		graph[idx][parent[idx]].first++;
		graph[idx][parent[idx]].second = -graph[parent[idx]][idx].second;

		idx = parent[idx];
	}
}

int main()
{
	int N, M;
	int num, temp, cost;
	int size, ans = 0, costSum = 0;

	scanf("%d %d",&N, &M);
	
	size = 2 + N + M;	

	for(int i = 0; i < N; i++)
	{
		scanf("%d",&num);

		for(int j = 0; j < num; j++)
		{
			scanf("%d %d",&temp, &cost);

			graph[2 + i][1 + N + temp].first = 1;
			graph[2 + i][1 + N + temp].second = -cost;
		}
	}

	for(int i = 0; i < N; i++)
	{
		graph[SOURCE][2 + i].first = 1;
		graph[SOURCE][2 + i].second = 0;
	}

	for(int i = 0; i < M; i++)
	{
		graph[2 + N + i][SINK].first = 1;
		graph[2 + N + i][SINK].second = 0;
	}

	for(int i = 0; i < N; i++)
	{
		if(bf(2 + N + M))
		{
			ans++;
			costSum += -dist[SINK];
			backGraph();
		}
	}

	printf("%d\n%d\n",ans,costSum);

	return 0;
}

