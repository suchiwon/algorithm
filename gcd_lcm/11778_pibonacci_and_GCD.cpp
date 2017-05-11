#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DIV 1000000007

long long basicMat[4] = { 1, 1, 1, 0 };
long long calcMat[4];
 
long long* mul(long long mat1[4], long long mat2[4]) {
    long long i, newMat[4];
 
    newMat[0] = mat1[0]%DIV * mat2[0]%DIV + mat1[1]%DIV * mat2[2]%DIV;
    newMat[1] = mat1[0]%DIV * mat2[1]%DIV + mat1[1]%DIV * mat2[3]%DIV;
    newMat[2] = mat1[2]%DIV * mat2[0]%DIV + mat1[3]%DIV * mat2[2]%DIV;
    newMat[3] = mat1[2]%DIV * mat2[1]%DIV + mat1[3]%DIV * mat2[3]%DIV;
 
    for (i = 0; i < 4; ++i) {
        calcMat[i] = newMat[i]%DIV;
    }
 
    return calcMat;
}
 
long long* fib(long long n) {
    if (n == 1) {
        return basicMat;
    }
 
    long long* mat = fib(n / 2);
    mat = mul(mat, mat);
 
    if (n % 2 == 1) {
        mat = mul(mat, basicMat);
    }
 
    return mat;
}
 
long long fibonacci(long long n) {
    long long* mat = fib(n);
    return mat[1];
}

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

int main() {
	long long a, b;

	scanf("%lld %lld",&a,&b);

	long long ans = fibonacci(gcd(a,b));

	printf("%lld\n",ans);

	return 0;
}