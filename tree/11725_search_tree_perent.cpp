#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_SIZE 100000

#define NONE -1

vector< vector<int> > tree;
bool is_visited[MAX_SIZE + 1] = {false,};
int parent[MAX_SIZE + 1];

void search(int idx) {
	if (!is_visited[idx]) {
		is_visited[idx] = true;

		for (int i = 0; i < tree[idx].size(); i++) {
			if (!is_visited[tree[idx][i]]) {
				parent[tree[idx][i]] = idx;
				search(tree[idx][i]);
			}
		}
	}
}

int main() {
	int N;
	scanf("%d",&N);
	tree.resize(N + 1);

	int a, b;

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d",&a,&b);

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	search(1);

	for (int i = 2; i <= N; i++) {
		printf("%d\n",parent[i]);
	}

	return 0;
}