#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX_SIZE 32000

using namespace std;

vector < vector<int> > graph;
vector <bool> v_visited;
stack <int> top_sort;

bool sortFunc(int a, int b) {
	if (a > b) {
		return true;
	} else {
		return false;
	}
}

void dfs(int idx) {

	int next;

	std::sort(graph[idx].begin(),graph[idx].end(), sortFunc);
	
	for (int i = 0; i < graph[idx].size(); i++) {
		next = graph[idx][i];

		if (v_visited[next] == false) {
			v_visited[next] = true;

			dfs(next);
		}
	}

	top_sort.push(idx);
}

int main() {
	int N,M;
	int start, end;

	scanf("%d %d",&N,&M);

	graph.resize(N + 1);
	v_visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		scanf("%d %d",&start,&end);

		graph[start].push_back(end);
	}

	for (int i = N; i >= 1; i--) {
		if (v_visited[i] == false) {
			v_visited[i] = true;
			dfs(i);
		}
	}

	while (!top_sort.empty()) {
		if (top_sort.size() > 1) {
			printf("%d ",top_sort.top());
		} else {
			printf("%d\n",top_sort.top());
		}

		top_sort.pop();
	}

	return 0;
}

