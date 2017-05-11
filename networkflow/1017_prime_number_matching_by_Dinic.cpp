#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <set>

#define MAX_SIZE 50
#define NOT_INIT -1

using namespace std;

vector< vector<int> > graph;
int v[MAX_SIZE + 1];
int dist[MAX_SIZE + 1];
int pair_u[MAX_SIZE + 1];
int pair_v[MAX_SIZE + 1];
int num[2][MAX_SIZE + 1];
bool bPrime[2001];
int vcnt;

void swap(int size)
{
	int temp;

	for(int i = 0; i < size; i++)
	{
		temp = num[0][i];
		num[0][i] = num[1][i];
		num[1][i] = temp;
	}
}

void makePrime()
{
	memset(bPrime,true,sizeof(bPrime));

	for (int i = 2; i < 50; i++){
		if(bPrime[i])
		{
			for(int j = 2 * i; j < 2001; j += i)
			{
				bPrime[j] = false;
			}
		}
    }
}

bool bfs(int size)
{
	queue<int> q;
	int cur, adj;

	for(int i = 1; i < size; i++)
	{
		if(pair_u[i] == NOT_INIT)
		{
			dist[i] = 0;
			q.push(i);
		}
		else
			dist[i] = NOT_INIT;
	}

	while(!q.empty())
	{
		cur = q.front();
		q.pop();

		for(int i = 0; i < graph[cur].size(); i++)
		{
			adj = graph[cur][i];

			if(pair_v[adj] == NOT_INIT)
				return true;

			if(dist[pair_v[adj]] == NOT_INIT)
			{
				dist[pair_v[adj]] = dist[cur] + 1;
				q.push(pair_v[adj]);
			}
		}
	}

	return false;
}

bool dfs(int size, int idx, int except)
{
	v[idx] = vcnt;

	for(int i = 0; i < graph[idx].size(); i++)
	{
		int adj = graph[idx][i];
		int next = pair_v[adj];

		if(adj == except || (next >= 0 && (v[next] == vcnt || dist[next] != dist[idx] + 1)))
			continue;

		if(next == NOT_INIT || dfs(size, next, except))
		{
			pair_u[idx] = adj;
			pair_v[adj] = idx;

			return true;
		}
	}

	return false;
}

int matching(int size, int accept)
{
	memset(pair_u,NOT_INIT,sizeof(pair_u));
	memset(pair_v,NOT_INIT,sizeof(pair_v));

	pair_u[0] = accept;
	pair_v[accept] = 0;

	int ans = 1;
	vcnt = 0;

	while(bfs(size))
	{
		vcnt++;
		for(int i = 1; i < size; i++)
		{
			if(dist[i] == 0 && dfs(size, i, accept))
				ans++;
		}
	}

	return ans;
}

int main()
{
	int N;
	int leftCount = 0, rightCount = 0, temp;
	bool bFirstOdd;
	set<int> ansSet;

	scanf("%d",&N);

	scanf("%d",&temp);

	if(temp%2 == 0)
	{
		bFirstOdd = false;
		leftCount++;
	}
	else
	{
		bFirstOdd = true;
		rightCount++;
	}

	num[temp%2][0] = temp;

	for(int i = 1; i < N; i++)
	{
		scanf("%d",&temp);

		if(temp%2 == 0)
			num[0][leftCount++] = temp;
		else
			num[1][rightCount++] = temp;
	}

	if(leftCount != rightCount)
	{
		puts("-1");
		return 0;
	}

	graph.resize(leftCount);

	if(bFirstOdd)
		swap(leftCount);

	makePrime();

	for(int i = 0; i < leftCount; i++)
	{
		for(int j = 0; j < leftCount; j++)
		{
			int n = num[0][i] + num[1][j];

			if(bPrime[n])
				graph[i].push_back(j);

		}
	}

	for(int i = 0; i < graph[0].size(); i++)
	{
		if(leftCount == matching(leftCount,graph[0][i]))
			ansSet.insert(num[1][graph[0][i]]);
	}

	if(ansSet.empty())
		puts("-1");
	else
	{
		for(set<int>::iterator iter = ansSet.begin(); iter != ansSet.end(); iter++)
			printf("%d ",(*iter));
	}

	return 0;
}