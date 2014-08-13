/*
LINK: http://www.spoj.com/problems/AMR10F/
TAG: math
*/

#include <cstdio>

int main() {
	int t, n, a, d;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &a, &d);
		printf("%d\n", n * (2 * a + (n - 1) * d) / 2);
	}
	return 0;
}
