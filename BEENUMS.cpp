/*
LINK: http://www.spoj.com/problems/BEENUMS/
TASK: math
*/

#include <cstdio>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	ll p, d, rt;
	while(scanf("%lld", &p) == 1 && p > 0) {
		d = 9 + 12 * (p - 1);
		rt = (ll)sqrt((double)d);
		if(rt * rt == d) {
			rt -= 3;
			if(rt % 6 == 0) puts("Y");
			else puts("N");
		}
		else puts("N");
	}
	return 0;
}
