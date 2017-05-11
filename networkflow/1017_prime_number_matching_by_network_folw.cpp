#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;

#define MAX_SIZE 50
#define SOURCE 0
#define SINK 1

bool visited[MAX_SIZE + 3];
int graph[MAX_SIZE + 3][MAX_SIZE + 3];
int parent[MAX_SIZE + 3];
int graphNum[2][MAX_SIZE + 1];
int check[MAX_SIZE];
bool bPrime[2001];

bool bfs(int size, int except)
{
	int idx = SOURCE;
	int cur;
	queue<int> q;

	q.push(idx);

	while(!q.empty())
	{	
		cur = q.front();
		q.pop();

		if(cur == SINK)
			return true;

		for(int i = 0; i < size; i++)
		{
			if(graph[cur][i] > 0 && !visited[i] && i != except && i != 2)
			{
				visited[i] = true;
				parent[i] = cur;
				q.push(i);
			}
		}
	}

	return false;
}

void backGraph()
{
	int cur = SINK;

	while(cur != SOURCE)
	{
		graph[parent[cur]][cur]--;
		graph[cur][parent[cur]]++;
		cur = parent[cur];
	}
}

void makeFlow(int size)
{
	memset(graph,0,sizeof(graph));
	memset(visited,false,sizeof(visited));

	for(int i = 2; i < 2 + size; i++)
	{
		graph[SOURCE][i] = 1;
	}

	for(int i = 2 + size; i < 2 + (2 * size); i++)
	{
		graph[i][SINK] = 1;
	}

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(bPrime[graphNum[0][i] + graphNum[1][j]])
			{
				graph[2 + i][2 + size + j] = 1;
			}
		}
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

void swap(int size)
{
	int temp;

	for(int i = 0; i < size; i++)
	{
		temp = graphNum[0][i];
		graphNum[0][i] = graphNum[1][i];
		graphNum[1][i] = temp;
	}
}

int main()
{
	int N, matched;
	bool bFirstOdd;
	int temp;
	int left = 0, right = 0;
	int checkNum = 0;

	set<int> matchSet;

	scanf("%d",&N);

	scanf("%d",&temp);

	if(temp%2 == 0)
	{
		bFirstOdd = false;
		left++;
	}
	else
	{
		bFirstOdd = true;
		right++;
	}

	graphNum[temp%2][0] = temp;

	for(int i = 1; i < N; i++)
	{
		scanf("%d",&temp);

		if(temp%2 == 0)
			graphNum[0][left++] = temp;
		else
			graphNum[1][right++] = temp;
	}

	if(left != right)
	{
		puts("-1\n");
		return 0;
	}

	if(bFirstOdd)
		swap(left);

	makePrime();

	for(int i = 0; i < left; i++)
	{
		if(bPrime[graphNum[0][0] + graphNum[1][i]])
			check[checkNum++] = i;
	}

	for(int i = 0; i < checkNum; i++)
	{
		makeFlow(left);
		matched = 1;
		
		while(bfs(2 + N,2 + left + check[i]))
		{
			matched++;
			backGraph();
			memset(visited,false,sizeof(visited));
		}

		if(matched == left)
		{
			matchSet.insert(graphNum[1][check[i]]);
		}
	}

	if(matchSet.empty())
		puts("-1");

	for(set<int>::iterator iter = matchSet.begin(); iter != matchSet.end(); iter++)
	{
		printf("%d ",(*iter));
	}
	
	return 0;
}
