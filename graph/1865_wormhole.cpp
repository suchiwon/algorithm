#include <stdio.h>
#include <vector>

using namespace std;

#define INF 0x7FFFFFFFFFFFFF

typedef struct {
	int from;
	int to;
	int cost;
} edge;

vector< edge > graph;
vector< long long > vec_cost;
int N;

bool bellmanford(int start) {
	
	vec_cost.assign(N+1,INF);
	vec_cost[start] = 0;

	for (int idx = 1; idx <= N; idx++) {
		for (int i = 0; i < graph.size(); i++) {
			if (vec_cost[graph[i].from] != INF && vec_cost[graph[i].to] > vec_cost[graph[i].from] + graph[i].cost) {
				vec_cost[graph[i].to] = vec_cost[graph[i].from] + graph[i].cost;
			}
		}
	}

	for (int i = 0; i < graph.size(); i++) {
		if (vec_cost[graph[i].to] > vec_cost[graph[i].from] + graph[i].cost) {
			return true;
		}
	}

	return false;
}

int main() {
	int T;
	int M,W;
	int start, end, cost;

	edge e;

	scanf("%d",&T);

	while (T--) {
		graph.clear();
		vec_cost.clear();

		scanf("%d %d %d",&N,&M,&W);

		vec_cost.resize(N+1);

		for (int i = 0; i < M; i++) {
			scanf("%d %d %d",&start, &end, &cost);
			e.from = start;
			e.to = end;
			e.cost = cost;
			graph.push_back(e);
			e.to = start;
			e.from = end;
			graph.push_back(e);
		}

		for (int i = 0; i < W; i++) {
			scanf("%d %d %d",&start, &end, &cost);

			e.from = start;
			e.to = end;
			e.cost = -cost;
			graph.push_back(e);
		}

		if (bellmanford(1) == false) {
			puts("NO");
		} else {
			puts("YES");
		}
	}

	return 0;
}