#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 0x7FFFFFFF

vector< vector< pair<int, int> > > graph;
vector<int> vec_cost;

int main() {
	int N,M;
	int start;

	int prev, next, cost;

	scanf("%d %d %d",&N,&M,&start);

	graph.resize(N+1);
	vec_cost.resize(N+1,INF);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d",&prev,&next,&cost);

		graph[prev].push_back(make_pair(next,cost));
	}

	priority_queue<int, vector<int>, greater<int> > pq;

	pq.push(start);
	vec_cost[start] = 0;

	while (!pq.empty()) {
		prev = pq.top();
		pq.pop();

		for (int i = 0; i < graph[prev].size(); i++) {
			next = graph[prev][i].first;
			cost = graph[prev][i].second;

			if (vec_cost[next] > vec_cost[prev] + cost) {
				vec_cost[next] = vec_cost[prev] + cost;
				pq.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (vec_cost[i] != INF) {
			printf("%d\n",vec_cost[i]);
		} else {
			puts("INF");
		}
	}

	return 0;
}

