/*
LINK: http://www.spoj.com/problems/ALCHE/
TASK: ad-hoc
*/

#include <cstdio>

int main() {
	int L, W;
	while(scanf("%d%d", &L, &W) == 2) {
		if(L == -1 && W == -1) break;
		if(37 * L == 1000 * W)
		  puts("Y");
		else
		  puts("N");
	}
	return 0;
}
