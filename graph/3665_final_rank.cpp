#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define MAX_SIZE 500

int indegree[MAX_SIZE + 1];
int graph[MAX_SIZE + 1][MAX_SIZE + 1];
queue<int> pq;

int main() {
	int T,N,M;
	scanf("%d",&T);

	while (T--) {
		memset(graph,0,sizeof(graph));
		memset(indegree,0,sizeof(indegree));
		while (!pq.empty()) {
			pq.pop();
		}

		scanf("%d",&N);

		vector<int> arr;
		vector<int> rank;
		arr.resize(N);

		for (int i = 0; i < N; i++) {
			scanf("%d",&arr[i]);
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				graph[arr[i]][arr[j]] = 1;
				indegree[arr[j]]++;
			}
		}

		scanf("%d",&M);

		int u,v;

		for (int i = 0; i < M; i++) {
			scanf("%d %d",&u, &v);

			if (graph[u][v] == 1) {
				graph[u][v] = 0;
				indegree[v]--;
			} else {
				graph[u][v] = 1;
				indegree[v]++;
			}

			if (graph[v][u] == 0) {
				graph[v][u] = 1;
				indegree[u]++;
			} else {
				graph[v][u] = 0;
				indegree[u]--;
			}
		}

		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				pq.push(i);
			}
		}

		int idx;

		while (!pq.empty()) {
			idx = pq.front();
			pq.pop();

			rank.push_back(idx);

			for (int i = 1; i <= N; i++) {
				if (graph[idx][i] == 1) {
					indegree[i]--;

					if (indegree[i] == 0) {
						pq.push(i);
					}
				}
			}
		}

		if (rank.size() == N) {
			for (int i = 0; i < N; i++) {
				printf("%d ", rank[i]);
			}

			puts("");
		} else {
			puts("IMPOSSIBLE");
		}
	}

	return 0;
}