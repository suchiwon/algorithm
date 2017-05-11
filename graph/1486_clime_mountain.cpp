#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>

#define MAX_SIZE 25
#define INF 9999999

using namespace std;


//int path[MAX_SIZE * MAX_SIZE + 1][MAX_SIZE * MAX_SIZE + 1];
int mountain[MAX_SIZE * MAX_SIZE + 1];
vector< vector< pair<int, int> > > pathFrom;
vector< vector< pair<int, int> > > pathTo;
int costFrom[MAX_SIZE * MAX_SIZE + 1];
int costTo[MAX_SIZE * MAX_SIZE + 1];

void getPath(int a, int b, int T)
{
	if(abs(mountain[a] - mountain[b]) <= T)
	{
		int temp = abs(mountain[b] - mountain[a]);

		if(mountain[a] > mountain[b])
		{
			//path[a][b] = 1;
			pathFrom[a].push_back(make_pair(b,1));
			pathTo[a].push_back(make_pair(b,temp * temp));
		}
		else if(mountain[b] > mountain[a])
		{
			//path[a][b] = temp * temp;
			pathFrom[a].push_back(make_pair(b,temp * temp));
			pathTo[a].push_back(make_pair(b,1));
		}
		else
		{
			pathFrom[a].push_back(make_pair(b,1));
			pathTo[a].push_back(make_pair(b,1));
		}
	}
}

void dijkstra()
{
	queue<int> q;

	memset(costFrom,INF,sizeof(costFrom));
	memset(costTo,INF,sizeof(costTo));

	costFrom[0] = 0;
	costTo[0] = 0;

	q.push(0);

	while(!q.empty())
	{
		int idx = q.front();

		q.pop();

		for(int i = 0; i < pathFrom[idx].size(); i++)
		{
			int to = pathFrom[idx][i].first;

			if(costFrom[to] > pathFrom[idx][i].second + costFrom[idx])
			{
				costFrom[to] = pathFrom[idx][i].second + costFrom[idx];
				q.push(to);
			}
		}
	}

	q.push(0);

	while(!q.empty())
	{
		int idx = q.front();

		q.pop();

		for(int i = 0; i < pathTo[idx].size(); i++)
		{
			int to = pathTo[idx][i].first;

			if(costTo[to] > pathTo[idx][i].second + costTo[idx])
			{
				costTo[to] = pathTo[idx][i].second + costTo[idx];
				q.push(to);
			}
		}
	}
}

int main()
{
	int N, M;
	int T, D;
	int max = 0;

	char str[MAX_SIZE + 1];

	scanf("%d %d %d %d",&N, &M, &T, &D);

	for(int i = 0; i < N; i++)
	{
		scanf("%s",str);

		for(int j = 0; j < M; j++)
		{
			if(str[j] >= 'A' && str[j] <= 'Z')
				mountain[M * i + j] = str[j] - 'A';
			else if(str[j] >= 'a' && str[j] <= 'z')
				mountain[M * i + j] = str[j] - 'a' + 26;
		}
	}

	pathFrom.resize(N * M);
	pathTo.resize(N * M);

	for(int i = 0; i < N * M; i++)
	{
		if(i%M > 0)
			getPath(i,i - 1, T);

		if(i%M < M - 1)
			getPath(i,i + 1, T);

		if(i/M > 0)
			getPath(i,i - M, T);

		if(i/M < N - 1)
			getPath(i,i + M, T);
	}

	/*
	for(int k = 0; k < N * M; k++)
	{
		for(int i = 0; i < N * M; i++)
		{
			for(int j = 0; j < N * M; j++)
			{
				if(path[i][j] > path[i][k] + path[k][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}


	for(int i = 1; i < N * M; i++)
	{
		if(path[0][i] + path[i][0] <= D && max < mountain[i])
			max = mountain[i];
	}
	*/

	dijkstra();

	for(int i = 0; i < N * M; i++)
	{
		if(costFrom[i] == INF || costTo[i] == INF) continue;
		if(costFrom[i] + costTo[i] <= D && max < mountain[i])
			max = mountain[i];
	}

	printf("%d\n",max);

	return 0;
}