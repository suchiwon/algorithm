#include <stdio.h>

int main() {

	int T;

	int a, b;

	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&a,&b);

		int diff = b - a;
		bool isSecond = true;
		int i = 1, time = 1, border = 1;

		while (diff > border && border > 0) {

			time++;
			
			if(!isSecond) {
				border += i;
				isSecond = true;
			} else {
				isSecond = false;
				border += i;
				i++;
			}
		}

		printf("%d\n",time);
	}

	return 0;
}
