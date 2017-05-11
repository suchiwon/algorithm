#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
	int N;
	int T;
	char stall[MAX_SIZE + 1];
	int color[6];

	int K, S;

	FILE *fp_in = fopen("A-large.in","r");
	FILE *fp_out = fopen("out.txt","w");

	fscanf(fp_in,"%d",&T);

	for (int i = 1; i <= T; ++i) {
		
		fscanf(fp_in, "%d",&N);

		for (int j = 0; j < 6; ++j) {
			fscanf
		}

		fscanf(fp_in, "%d %d %d %d %d %d",&R, &O, &Y, &G, &B, &V);

		



		fprintf(fp_out, "Case #%d: %lf\n", i, ans);

	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}