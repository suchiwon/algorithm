#include <stdio.h>

bool is_key(int n, int ans) {
    int sum = 0;
	int saver = n;
    int temp;
    while (n != 0) {
        temp = n%10;
        sum += temp;
        n = n/10;
    }
    
    if (ans - saver == sum) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    
    scanf("%d",&n);
    
    for (int i = 1; i < n; i++) {
        if (is_key(i,n) == true) {
            printf("%d\n",i);
            return 0;
        }
    }
    
    printf("0\n");
    
    return 0;
}