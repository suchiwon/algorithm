#include <stdio.h>
#include <stack>

#define MAX_SIZE 100000

bool bUsedArr[MAX_SIZE + 1];
char commandArr[2 * MAX_SIZE + 1];

using namespace std;

int main() {
	int N, point = 1, temp, commandIdx = 0;

	scanf("%d",&N);

	stack<int> stackA;

	for (int i = 1; i <= N; i++) {
		bUsedArr[i] = false;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d",&temp);

		if (temp >= point) {

			if (bUsedArr[temp]) {
				puts("NO");
				return 0;
			}

			for (int j = point; j <= temp; j++) {
				if (!bUsedArr[j]) {
					bUsedArr[j] = true;
					stackA.push(j);
					commandArr[commandIdx++] = '+';
				}
			}

			stackA.pop();
			commandArr[commandIdx++] = '-';
		} else {
			while (!stackA.empty() && stackA.top() != temp) {
				stackA.pop();
				commandArr[commandIdx++] = '-';
			}

			if (stackA.empty()) {
				puts("NO");
				return 0;
			} else {
				stackA.pop();
				commandArr[commandIdx++] = '-';
			}
		}

		point = temp;
	}

	for (int i = 0; i < commandIdx; i++) {
		printf("%c\n",commandArr[i]);
	}

	return 0;
}