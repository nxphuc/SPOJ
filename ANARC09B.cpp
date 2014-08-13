/*
LINK: http://www.spoj.com/problems/ANARC09B/
TAG: math
*/

#include <cstdio>

#define ll long long

ll gcd(ll a, ll b ){
	if(b) return gcd(b, a % b);
	return a;
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

int main(){
	int a, b;
	while(scanf("%d%d", &a, &b) && a) {
		ll LCM = lcm(a, b);
		printf("%lld\n", (LCM / a) * (LCM / b));
	}
	return 0;
}
