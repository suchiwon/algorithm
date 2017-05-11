#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 0x7FFFFFFFFFFFFF

vector< vector< pair<int, int> > > graph;
vector<long long> vec_cost;
int N;

void dijk(int start) {
	
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

	vec_cost.assign(N + 1,INF);

	pq.push(make_pair(0,start));
	vec_cost[start] = 0;

	int idx, cost, next;

	while (!pq.empty()) {
		idx = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[idx].size(); i++) {
			next = graph[idx][i].first;
			cost = graph[idx][i].second;

			if (vec_cost[next] > vec_cost[idx] + cost) {
				vec_cost[next] = vec_cost[idx] + cost;
				pq.push(make_pair(vec_cost[next],next));
			}
		}
	}
}

int main() {
	int M;
	int prev, next, cost;
	int p1,p2;

	scanf("%d %d",&N,&M);

	vec_cost.resize(N+1);
	graph.resize(N+1);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d",&prev, &next, &cost);

		graph[prev].push_back(make_pair(next,cost));
		graph[next].push_back(make_pair(prev,cost));
	}

	scanf("%d %d",&p1, &p2);

	long long dist1 = 0, dist2 = 0;

	dijk(1);
	dist1 += vec_cost[p1];
	dist2 += vec_cost[p2];
	dijk(p1);
	dist1 += vec_cost[p2];
	dist2 += vec_cost[N];
	dijk(p2);
	dist1 += vec_cost[N];
	dist2 += vec_cost[p1];

	if (dist1 < INF && dist2 < INF) {

		if (dist1 > dist2) {
			printf("%lld\n",dist2);
		} else {
			printf("%lld\n",dist1);
		}
	} else {
		puts("-1");
	}

	return 0;
}