/*
LINK: http://www.spoj.com/problems/ASSIST/
TASK: simulation
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 34000
#define TAR 3000

int lucky[TAR+1];
bool flag[MAX+1];

int main() {
	for(int i = 1, k = 2; i <= TAR; i++, k++) {
		while(flag[k]) k++;
		lucky[i] = k;
		for(int j = k + 1, c = 0; j <= MAX; j++) {
			if(flag[j]) continue;
			c++;
			if(c == k) {
				flag[j] = 1;
				c = 0;
			}
		}
	}
	
	int n;
	while(scanf("%d", &n) == 1 && n) {
		printf("%d\n", lucky[n]);
	}
	return 0;
}
