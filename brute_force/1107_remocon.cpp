#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define min(a,b) a>b?b:a

bool b_button[10];

int main() {
	int num, n, temp, saver;
	int down = 0, up = 0, idx = 0, ans = 0, idxSaver;
	bool b_cmp = true;
	int count;
	scanf("%d %d",&num,&n);

	ans = abs(num - 100);

	if (n == 10) {
		printf("%d\n",ans);
		return 0;
	}

	for (int i = 0; i < 10; i++) {
		b_button[i] = true;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d",&temp);
		b_button[temp] = false;
	}

	saver = num;

	if (num == 0) {
		if (b_button[0] == true) {
			printf("%d\n",1);
			return 0;
		}
		idx = 1;
	} else {
		while (saver != 0) {
			idx++;
			saver = saver/10;
		}
	}

	for (int i = num; i <= 1000000; i++) {

		b_cmp = true;
		saver = i;
		idxSaver = 0;

		if (i == 0) {
			continue;
		}

		while (saver != 0) {
			temp = saver%10;
			idxSaver++;
			if (b_button[temp] == false) {
				b_cmp = false;
				break;
			}

			saver = saver/10;
		}

		if (b_cmp == true) {
			ans = min(i - num + idxSaver, ans);
			break;
		}
	}

	for (int i = num - 1; i > 0; i--) {

		b_cmp = true;
		saver = i;
		idxSaver = 0;

		if (i == 0 && b_button[0] == true) {
			ans = min(num - i + 1, ans);
		} else{
			while (saver != 0) {
				temp = saver%10;
				idxSaver++;
				if (b_button[temp] == false) {
					b_cmp = false;
					break;
				}

				saver = saver/10;
			}

			if (b_cmp == true) {
				ans = min(num - i + idxSaver, ans);
				break;
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}