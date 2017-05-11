#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector < vector<int> > graph;
vector <int> vec_indegree;
priority_queue< int,vector<int>,greater<int> > pq;

int main() {
	int N, M;
	int start, end;

	scanf("%d %d",&N,&M);

	graph.resize(N + 1);
	vec_indegree.resize(N + 1);

	for (int i = 0; i < M; i++) {
		scanf("%d %d",&start, &end);

		graph[start].push_back(end);
		vec_indegree[end]++;
	}

	for (int i = 1; i <= N; i++) {
		if (vec_indegree[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		start = pq.top();
		pq.pop();

		printf("%d ",start);

		for (int i = 0; i < graph[start].size(); i++) {
			end = graph[start][i];

			vec_indegree[end]--;

			if (vec_indegree[end] == 0) {
				pq.push(end);
			}
		}
	}

	return 0;

}