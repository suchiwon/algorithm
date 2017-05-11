#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

set<long long> divisor_set;
vector<long long> divisor_vector;
long long N;
long long ans = 0;

void GetDivisor(long long N) {

	for (long long i = 2; i * i <= N;) {
		if (N%i == 0) {
			divisor_set.insert(i);
			N  = N/i;
			i = 2;
		} else {
			i++;
		}
	}

	if (N != 1) {
		divisor_set.insert(N);
	}
}

void dfs(long long div, int idx, int level) {
	if (level >= 1 && level <= divisor_vector.size()) {
		if (level%2 == 0) {
			ans += N/div;
		} else {
			ans -= N/div;
		}
	}

	for (int i = idx + 1; i < divisor_vector.size(); i++) {
		div *= divisor_vector[i];
		dfs(div,i,level+1);
		div /= divisor_vector[i];
	}	
}

int main() {

	scanf("%lld",&N);

	ans = N;

	if (N == 1) {
		printf("1\n");
		return 0;
	}

	GetDivisor(N);

	for (set<long long>::iterator iter_i = divisor_set.begin(); iter_i != divisor_set.end(); iter_i++) {
		divisor_vector.push_back((*iter_i));
	}

	/*
	for (set<long long>::iterator iter_i = divisor_set.begin(); iter_i != divisor_set.end(); iter_i++) {
		ans -= N/(*iter_i);

		for (set<long long>::iterator iter_j = iter_i; iter_j != divisor_set.end();) {
			iter_j++;
			if (iter_j == divisor_set.end()) {
				break;
			}
			ans += N/((*iter_i) * (*iter_j));
		}
	}

	ans -= ((divisor_size - 1) * (divisor_size - 2));
	*/
	int idx = 0;


	for (set<long long>::iterator iter_i = divisor_set.begin(); iter_i != divisor_set.end(); iter_i++) {
		dfs((*iter_i),idx,1);
		idx++;
	}

	printf("%lld\n",ans);

	return 0;
}