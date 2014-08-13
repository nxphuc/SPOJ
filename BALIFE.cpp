/*
LINK: http://www.spoj.com/problems/BALIFE/
TAG: simulation
*/

#include <cstdio>

int main() {
	int a[9000], m, n, i, val, diff;
	while(scanf("%d", &n) == 1 && n > 0) {
		for(i = 0, val = 0; i < n; i++) {
			scanf("%d", &a[i]);
			val += a[i];
		}
		if(val % n)
			printf("-1\n");
		else {
			val /= n;
			for(i = 0, m = 0; i < n - 1; i++) {
				diff = a[i] - val;
				a[i+1] += diff;
				if(diff < 0) diff = -diff;
				m = m > diff ? m : diff;
			}
			printf("%d\n", m);
		}
	}
	return 0;
}
