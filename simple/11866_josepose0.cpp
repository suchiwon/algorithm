#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int N, J, point = 1, count = 0, jump_count;
    
    vector<bool> jumper;
    
    scanf("%d %d", &N, &J);
    
    jumper.resize(N + 1);
    
    fill(jumper.begin(),jumper.end(),false);
    jumper[0] = true;
    
    printf("<");
    
    while (count < N) {
        jump_count = 0;
        while (true) {
            if (!jumper[point]) {
                jump_count++;
            }

			if (jump_count >= J) {
				break;
			}
            
            point++;
            
            if (point > N) {
                point = 1;
            }
        }
        
        jumper[point] = true;
        
        count++;
        
        if (count < N) {
            printf("%d, ", point);
        } else {
            printf("%d>\n", point);
        }
    }
    
    return 0;
}