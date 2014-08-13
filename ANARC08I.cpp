/*
LINK: http://www.spoj.com/problems/ANARC08I/
TAG: divide and conquer
*/

#include <cstdio>

#define ll long long


ll solve(int n, ll r, ll i, ll j, ll s, ll e) {
	if(i == s && j == e) {
		if(!r) return j - i + 1;
		return 0;
	}
	ll m, c, k;
	m = (i + j) >> 1; c = 1; c <<= n; k = 1;
	if (r >= (c >> 1)){
		r -= (c >> 1);
		k = -1;
	}
	if (e <= m)
		return solve(n - 1, r, i, m, s, e);
	else
		if (s > m) return solve(n - 1, r, m + 1, j, s, e) * k;
	return solve(n - 1, r, i, m, s, m) + solve(n - 1, r, m + 1, j, m + 1, e) * k;
}

int main() {
	ll r, s, e, k;
	int n;
	while( scanf("%d %lld %lld %lld", &n, &r, &s, &e) == 4 && n > -1) {
		k = 1; k <<= n;
		printf("%lld\n", solve(n, r, 0, k - 1, s, e));
	}
	return 0;
}
