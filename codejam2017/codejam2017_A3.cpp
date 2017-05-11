
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define MAX_SIZE 1000

long long arr[MAX_SIZE + 1][MAX_SIZE + 1];
long long R[MAX_SIZE + 1];

priority_queue< pair<long long, long long> > pancakes;
vector<long long> multi;

int main() {
	int T;
	int N, K;
	int H;

	FILE* in = fopen("A-small-attempt0.in","r");
	FILE* out = fopen("result.txt","w");

	fscanf(in,"%d",&T);

	for (int t = 1; t <= T; ++t) {
		fscanf(in,"%d %d",&N, &K);

		multi.clear();
		multi.resize(N);

		for (int i = 0; i < N; ++i) {
			fscanf(in,"%lld %d",&R[i], &H);

			pancakes.push(make_pair(R[i], H));
		}

		for (int i = 0; i < N; ++i) {
			pair<long long, long long> temp = pancakes.top();
			pancakes.pop();

			multi[i] = temp.first * temp.second;

			R[i] = temp.first;
		}

		for (int i = N - 1; i >= 0; --i) {
			arr[0][i] = multi[i];
		}

		for (int i = 1; i < K; ++i) {

			arr[i][N - i - 1] = arr[i-1][N - i] + multi[N - i - 1];

			long long max_temp = max(arr[i-1][N - i - 1],arr[i-1][N - i]);

			for (int j = N - i - 2; j >= 0; --j) {
				arr[i][j] = max_temp + multi[j];

				if (max_temp < arr[i - 1][j]) {
					max_temp = arr[i - 1][j];
				}
			}
		}

		long double ans = 0;
		for (int i = 0; i <= N - K; ++i) {
			
			long double temp = (R[i] * R[i] + 2 * arr[K - 1][i]) * (long double)3.141592653589793238462;
			if (temp > ans) {
				ans = temp;
			}
		}

		fprintf(out,"Case #%d: %.9lf\n",t,ans);
	}

	fclose(in);
	fclose(out);

	return 0;
}