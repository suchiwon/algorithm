#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>

using namespace std;

int arr[10001];
int num[100];

int gcd(int a,int b)
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
	int N;
	int count = 0;

	scanf("%d",&N);

	for (int i = 0; i < N; i++) {
		scanf("%d",&num[i]);
	}

	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			arr[count++] = abs(num[i] - num[j]);
		}
	}

	int temp = arr[0];

	for (int i = 1; i < count; i++) {
		temp = gcd(temp, arr[i]);
	}

	set<int> s;

	s.insert(temp);

	for (int i = 2; (i * i) <= temp; i++) {
		if (temp%i == 0) {
			s.insert(i);
			s.insert(temp/i);
		}
	}

	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		printf("%d ",(*iter));
	}

	return 0;
}