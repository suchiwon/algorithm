#include <stdio.h>
#include <math.h>

#define MAX_SIZE 20

int n;
long long x[MAX_SIZE + 1];
long long y[MAX_SIZE + 1];
long long min;


void brute(int idx, long long x_val, long long y_val, int visited_num) {


	if (visited_num == 0) {
		for (int i = idx + 1; i <= n; i++) {
			x_val -= x[i];
			y_val -= y[i];
		}
		long long temp_long = (long long)(x_val * x_val) + (long long)(y_val * y_val);

		if (min > temp_long) {
			min = temp_long;
		}
	} else if (idx < n) {
		for (int i = idx + 1; i <= n; i++) {
			x_val += x[i];
			y_val += y[i];
			brute(i, x_val, y_val, visited_num - 1);
			x_val -= 2 * x[i];
			y_val -= 2 * y[i];
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);

	while (T--) {
		scanf("%d",&n);

		min = 9223372036854775807;

		for (int i = 1; i <= n; i++) {
			scanf("%lld %lld",&x[i], &y[i]);
		}

		brute(0,0,0,n/2);


		printf("%.6lf\n",(double)sqrt((long double)min));
	}

	return 0;
}