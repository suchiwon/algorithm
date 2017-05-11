#include <stdio.h>

long long count[10] = {0,};
int pow10[11];

long long GetPrefix(int N, int size, int fix_size) {
	return N/pow10[size - fix_size];
}

long long GetPostfix(int N, int fix_size) {
	return N%pow10[fix_size];
}

int GetIdxNum(int N, int size, int idx) {
	int temp = GetPostfix(N, idx);

	return GetPrefix(temp, idx, 1);
}


int main() {
	int N, temp;
	int size = 0;
	long long pre_num, post_num;

	scanf("%d",&N);

	temp = N;

	pow10[0] = 1;

	for (int i = 1; i < 11; i++) {
		pow10[i] = pow10[i-1] * 10;
	}

	while (temp != 0) {
		temp /= 10;
		size++;
	}

	temp = GetIdxNum(N, size, size);
	post_num = GetPostfix(N, size - 1);

	for (int i = 1; i < temp; i++) {
		count[i] += pow10[size - 1];
	}

	count[temp] += post_num + 1;

	for (int i = size - 1; i >= 1; i--) {
		temp = GetIdxNum(N, size, i);

		pre_num = GetPrefix(N, size, size - i);
		post_num = GetPostfix(N, i - 1);

		if (temp == 0) {
			count[0] += pre_num * (post_num + 1);

			for (int j = 1; j <= 9; j++) {
				count[j] += pre_num * pow10[i-1];
			}
		} else {
			count[0] += pre_num * pow10[i-1];

			for (int j = 1; j < temp; j++) {
				count[j] += (pre_num + 1) * pow10[i-1];
			}

			count[temp] += post_num + 1;

			for (int j = temp; j <= 9; j++) {
				count[j] += pre_num * pow10[i-1];
			}
		}
	}


	for (int i = 0; i <= 9; i++) {
		printf("%lld ", count[i]);
	}

	puts("");

	return 0;

}