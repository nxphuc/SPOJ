/*
LINK: http://www.spoj.com/problems/BOMARBLE/
TAG: math
*/

#include <cstdio>

int main() {
	int n;
	while(scanf("%d", &n) && n) {
		n++;
		printf("%d\n", n * (3 * n - 1) / 2);
	}
	return 0;
}
