/*
LINK: http://www.spoj.com/problems/ANDROUND/
TAG: segment tree
*/

#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1 << 15;

int T[MAX << 1], a[MAX];

void build(int node, int i, int j) {
	if(i == j) {
		T[node] = a[i];
		return;
	}
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	build(lt, i, mid);
	build(rt, mid + 1, j);
	T[node] = T[lt] & T[rt];
}

int query(int node, int i, int j, int s, int e) {
	if(i == s && j == e)
		return T[node];
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	if(e <= mid)
		return query(lt, i, mid, s, e);
	else
		if(s > mid)
			return query(rt, mid + 1, j, s, e);
		else
			return query(lt, i, mid, s, mid) & query(rt, mid + 1, j, mid + 1, e);
}

int main() {
	int test, cs, i, n, k, s, e, res;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		k = min(k, n - 1);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		build(1, 0, n - 1);
		for(i = 0; i < n; i++) {
			s = (i - k + n) % n;
			e = (i + k) % n;
			res = -1;
			if (s < i)
				res &= query(1, 0, n - 1, s, i);
			else
				res &= query(1, 0, n - 1, 0, i) & query(1, 0, n - 1, s, n - 1);
			if (e > i)
				res &= query(1, 0, n - 1, i, e);
			else
				res &= query(1, 0, n - 1, i, n - 1) & query(1, 0, n - 1, 0, e);
			if (i)
				printf(" "); printf("%d", res);
		}
		printf("\n");
	}
	return 0;
}
