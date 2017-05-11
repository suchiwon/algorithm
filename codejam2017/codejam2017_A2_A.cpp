#include <stdio.h>
#include <float.h>


int main() {
	int D, N;
	int T;
	double ans, temp;

	int K, S;

	FILE *fp_in = fopen("A-large.in","r");
	FILE *fp_out = fopen("out.txt","w");

	fscanf(fp_in,"%d",&T);

	for (int i = 1; i <= T; ++i) {

		ans = DBL_MAX;
		
		fscanf(fp_in, "%d %d",&D, &N);

		for (int j = 0; j < N; ++j) {
			fscanf(fp_in, "%d %d",&K, &S);

			temp = (double)D * S/(D-K);

			if (ans > temp) {
				ans = temp;
			}
		}

		fprintf(fp_out, "Case #%d: %lf\n", i, ans);

	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}