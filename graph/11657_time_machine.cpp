#include <stdio.h>
#include <vector>

using namespace std;

#define INF 0x7FFFFFFFFFFFFF

typedef struct {
	int from;
	int to;
	int cost;
} edge;

vector<edge> graph;
vector<long long> vec_cost;

int N;

bool bellmanford(int start) {
	
	vec_cost.assign(N+1,INF);
	vec_cost[start] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < graph.size(); j++) {
			if (vec_cost[graph[j].to] > vec_cost[graph[j].from] + graph[j].cost) {
				vec_cost[graph[j].to] = vec_cost[graph[j].from] + graph[j].cost;
			}
		}
	}

	for (int j = 0; j < graph.size(); j++) {
		if (vec_cost[graph[j].to] > vec_cost[graph[j].from] + graph[j].cost) {
			return false;
		}
	}

	return true;
}

int main() {
	int M;
	edge e;

	scanf("%d %d",&N, &M);

	vec_cost.resize(N + 1);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d",&e.from, &e.to, &e.cost);
		graph.push_back(e);
	}

	if (bellmanford(1) == false) {
		puts("-1");
	} else {
		for (int i = 2; i <= N; i++) {
			if (vec_cost[i] == INF) {
				puts("-1");
			} else {
				printf("%lld\n",vec_cost[i]);
			}
		}
	}

	return 0;
}