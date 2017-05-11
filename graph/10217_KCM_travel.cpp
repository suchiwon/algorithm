#include <stdio.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <iostream>
#include <string>

#define NOT_INIT -1
#define MAX 2147483647

using namespace std;

struct edge {
	int idx;
	int cost;
	int time;

	bool operator < (const edge &e) const {
		return cost > e.cost;
	}
};

string no = "Poor KCM";

vector< edge > graph[101];

int dp[101][10001];

int main() {
	int T;
	int N,M,K;
	int idx, next_idx;
	int time, cost, ans;

	edge e;

	scanf("%d",&T);

	while (T--) {


		scanf("%d %d %d",&N,&M,&K);

		for (int i = 0; i <= N; i++) {
			graph[i].clear();
		}

		memset(dp,NOT_INIT,sizeof(dp));

		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d",&idx, &next_idx, &cost, &time);
			e.idx = next_idx;
			e.cost = cost;
			e.time = time;

			graph[idx].push_back(e);
		}

		e.idx = 1;
		e.cost = 0;
		e.time = 0;

		dp[1][0] = 0;

		priority_queue<edge> pq;

		pq.push(e);

		while (!pq.empty()) {
			edge node = pq.top();
			pq.pop();

			if (node.cost > dp[node.idx][node.time]) {
				continue;
			}

			dp[node.idx][node.time] = node.cost;

			for (int i = 0; i < graph[node.idx].size(); i++) {
				edge next = graph[node.idx][i];

				time = node.time + next.time;
				cost = node.cost + next.cost;

				if (time > M) {
					continue;
				}

				if (dp[next.idx][time] == NOT_INIT || dp[next.idx][time] > cost) {
					dp[next.idx][time] = cost;

					e.idx = next.idx;
					e.cost = cost;
					e.time = time;

					pq.push(e);
				}
			}
		}

		ans = MAX;

		for (int i = 0; i <= M; i++) {
			if (dp[N][i] != NOT_INIT && ans > dp[N][i]) {
				ans = dp[N][i];
			}
		}

		if (ans != MAX) {
			printf("%d\n",ans);
		} else {
			cout << no << endl;
		}
	}

	return 0;
}