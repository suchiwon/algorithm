#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

#define MAX_SIZE 500
#define NOT_INIT -1

using namespace std;

vector< vector<int> > graph;
bool visited[MAX_SIZE + 1];
int matched[MAX_SIZE + 1];
int catVote[MAX_SIZE][2];
int dogVote[MAX_SIZE][2];


bool dfs(int idx)
{
	if(visited[idx])
		return false;
	else
	{
		visited[idx] = true;

		for(int i = 0; i < graph[idx].size(); i++)
		{
			int adj = graph[idx][i];
			if(matched[adj] == NOT_INIT || dfs(matched[adj]))
			{
				
				matched[adj] = idx;

				return true;
			}
		}

		return false;
	}
}

int main()
{
	int cat, dog, N, match = 0, T;
	int catVoter = 0, dogVoter = 0;
	string temp;
	vector<int> adder;

	cin >> T;

	while(T--)
	{
		cin >> cat >> dog >> N;
		catVoter = 0;
		dogVoter = 0;
		match = 0;
		graph.clear();

		for(int i = 0; i < N; i++)
		{
			cin >> temp;

			if(temp.at(0) == 'C')
			{
				graph.push_back(adder);
				catVote[catVoter][0] = atoi(temp.substr(1,temp.length() - 1).c_str());

				cin >> temp;

				catVote[catVoter++][1] = atoi(temp.substr(1,temp.length() - 1).c_str());
			}
			else
			{
				dogVote[dogVoter][0] = atoi(temp.substr(1,temp.length() - 1).c_str());

				cin >> temp;

				dogVote[dogVoter++][1] = atoi(temp.substr(1,temp.length() - 1).c_str());
			}
		}

		for(int i = 0; i < catVoter; i++)
		{
			for(int j = 0; j < dogVoter; j++)
			{
				if(catVote[i][0] == dogVote[j][1] || catVote[i][1] == dogVote[j][0])
					graph[i].push_back(j);
			}
		}

		memset(matched,NOT_INIT,sizeof(matched));

		for(int i = 0; i < catVoter; i++)
		{
			memset(visited,false,sizeof(visited));

			if(dfs(i))
				match++;
		}

		cout << N - match << endl;
	}

	return 0;
}