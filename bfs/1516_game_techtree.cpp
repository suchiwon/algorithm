#include <stdio.h>
#include <vector>

using namespace std;

#define NOT_INIT -1

vector < vector<int> > graph;
vector <int> vec_cost;
vector <int> vec_node;

int dfs(int idx) {
	if (vec_cost[idx] != NOT_INIT) {
		return vec_cost[idx];
	} else {
		int max = 0, temp;

		for (int i = 0; i < graph[idx].size(); i++) {
			temp = dfs(graph[idx][i]);

			if (max < temp) {
				max = temp;
			}
		}

		vec_cost[idx] = max + vec_node[idx];
		return vec_cost[idx];
	}
}

int main() {
	int N;

	scanf("%d",&N);

	graph.resize(N + 1);
	vec_cost.resize(N + 1);
	vec_node.resize(N + 1);
	
	int cost, prev;

	for (int i = 1; i <= N; i++) {
		vec_cost[i] = NOT_INIT;
		scanf("%d",&vec_node[i]);

		while (true) {
			scanf("%d",&prev);

			if (prev == -1) {
				break;
			} else {
				graph[i].push_back(prev);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n",dfs(i));
	}

	return 0;
}