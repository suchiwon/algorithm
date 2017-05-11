#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

#define MAX_SIZE 100000
#define DIV 1000000007LL

map< int, map<int, int> > tree;

long long ans = 0;

long long algorithm(int prev, int idx, int parent) {

	map<int, int>::iterator iter, end;
	vector<int> factor;
	long long child_sum = 0;
	long long sum = 0;

		end = tree[idx].end();
		for (iter = tree[idx].begin(); iter != end; iter++ )
		{
			if (iter->first == prev) 
				continue;

			long long temp = algorithm(idx,iter->first,iter->second)%DIV;

			child_sum = (child_sum + temp)%DIV;
			factor.push_back(temp);
		}

		sum = child_sum;

		ans = (ans + sum)%DIV;

		for (int i = 0; i < factor.size(); i++) {

			if (child_sum < factor[i]) {
				child_sum += DIV;	
			}

			child_sum = (child_sum - factor[i])%DIV;

			ans = (ans + ((child_sum * factor[i])%DIV))%DIV;
		}

		return ((sum + 1)%DIV * parent)%DIV;
}

int main() {
	int N;
	int A,B,W;

	scanf("%d",&N);

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &A, &B, &W);
		tree[A][B] = tree[B][A] = W;
	}

	algorithm(-1,1,0);

	printf("%lld\n",ans);

	return 0;
}
