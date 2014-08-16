/*
LINK: http://vn.spoj.com/problems/PTQMSEQ/
TAG: ad-hoc
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long resMax, resMin, tmpMax, tmpMin, S, n, first, last;

int main() {
	scanf("%lld", &n);
	scanf("%lld", &first);
	resMax = resMin = tmpMax = tmpMin = S = first;
	for (long i = 1; i < n; i++){
		scanf("%lld", &last);
		S += last;
		tmpMax = max(last, tmpMax + last);
		tmpMin = min(last, tmpMin + last);
		resMax = max(resMax, tmpMax);
		resMin = min(resMin, tmpMin);
	}
	
	if (S == resMax)
		resMax = max(resMax - first, resMax - last);
	if (S == resMin)
		resMin = min(resMin - first, resMin - last);
		
	printf("%lld", max(resMax, S - resMin));
	
	return 0;
}
