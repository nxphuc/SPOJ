/*
LINK: http://www.spoj.com/problems/BRCKTS2/
TAG: recursion
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
#define MAX 500000

char str[MAX + 1];

void solve(ll &h, ll &w, int d, int &pos, ll &area){
	ll maxH = 0, newW, newH;
	pos++;
	while(str[pos] == '(' ){
		newH = newW = 1;
		solve(newH, newW, d + 1, pos, area);
		w += newW + 1;
		maxH = max(newH, maxH);
		pos++;
	}
	h = maxH + 1;
	if(d & 1)
		area += w * h;
	else
		area -= w*h;
}

int main(){
	int t, len, i;
	ll w, h, area;
	scanf("%d", &t);
	while(t--){
		scanf("%s", str);
		len = strlen(str);
		area = 0;
		for(i = 0; i < len; i++){
			h = w = 1;
			solve(h, w, 1, i, area);
		}
		printf("%lld\n", area);
	}
	return 0;
}
