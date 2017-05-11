#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long gcd(long long a, long long b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main() {
	long long a,b;

	scanf("%lld %lld",&a,&b);

	long long temp = gcd(a,b);

	if (a%temp == 0 || b%temp == 0) {
		for (long long i = 0; i < temp; i++) {
			printf("1");
		}
		puts("");
	} else {
		puts("1");
	}

	return 0;
}