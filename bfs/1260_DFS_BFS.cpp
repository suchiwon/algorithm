#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define MAX_SIZE 1000

bool graph[MAX_SIZE + 1][MAX_SIZE + 1];
bool bVisited[MAX_SIZE + 1];
queue<int> qVisited;
stack<int> sVisited;

int main() {
	int N,M,V;
	int start, end, idx, count;

	scanf("%d %d %d",&N,&M,&V);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = false;
		}
		bVisited[i] = false;
	}


	for (int i = 0; i < M; i++) {
		scanf("%d %d",&start,&end);

		graph[start][end] = true;
		graph[end][start] = true;
	}

	//DFS

	sVisited.push(V);
	bVisited[V] = true;
	printf("%d ",V);

	while (!sVisited.empty()) {
		idx = sVisited.top();

		for (count = 1; count <= N; count++) {
			if (graph[idx][count] && !bVisited[count]) {
				bVisited[count] = true;
				sVisited.push(count);
				printf("%d ",count);
				break;
			}
		}

		if (count > N) {
			sVisited.pop();
		}
	}

	puts("");

	//BFS

	for (int i = 1; i <= N; i++) {
		bVisited[i] = false;
	}

	qVisited.push(V);
	bVisited[V] = true;
	printf("%d ",V);

	while (!qVisited.empty()) {
		idx = qVisited.front();

		for (count = 1; count <= N; count++) {
			if (graph[idx][count] && !bVisited[count]) {
				bVisited[count] = true;
				qVisited.push(count);
				printf("%d ",count);
			}
		}

		qVisited.pop();

	}

	puts("");

	return 0;
}