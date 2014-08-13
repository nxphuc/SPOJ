/*
NAME: Glass Beads
LINK:
 - SPOJ: http://www.spoj.com/problems/BEADS/
 - POJ: http://poj.org/problem?id=1509
 - UVa: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=660
Result:
 - Solu 1:
  + SPOJ: AC (0.96s)
  + POJ: AC (188MS)
  + UVa: TLE (time limit 3s)
  
 - Solu 2:
  + SPOJ: AC (0.19s)
  + POJ: AC (47MS)
  + UVa: AC (1.192s)
TAG: ad-hoc, String Processing
*/


//=========== Solution 1 ===========//
//Source: zobayer
#include <cstdio>
#include <cstring>

char str[10001];

int mycmp(int i, int j, int len){
	int k;
	for(k = 0; k < len; k++, i++, j++){
		if(i == len) i = 0;
		if(j == len) j = 0;
		if(str[i] != str[j])
			return str[i]-str[j];
	}
	return 0;
}

int main(){
	int t, i, p, best, len;
	scanf("%d", &t);
	while(t--){
		best = 0;
		scanf("%s", str);
		len = strlen(str);
		for(i = 1; i < len; i++){
			p = mycmp(best, i, len);
			if(p > 0) best = i;
		}
		printf("%d\n", best + 1);
	}
	return 0;
}

//=========== Solution 2 ===========//
//Source: nxphuc

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;

#define MAX 100010
char T[MAX], P[MAX];
int n, m;
int RA[MAX], tempRA[MAX];
int SA[MAX], tempSA[MAX];
int c[MAX], phi[MAX];
int LCP[MAX], PLCP[MAX];

void countSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for (i = 0; i < n; i++)
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void makeSA() {
	int i, k, r;
	for (i = 0; i < n; i++) {
		RA[i] = T[i];
		SA[i] = i;
	}
	for (k = 1; k < n; k <<= 1) {
		countSort(k);
		countSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++)
			tempRA[SA[i]] =	(RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];
	}
}

int main() {
	int tc;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", P);
		m = strlen(P);
		T[0] = '\0';
		strcat(T, P);
		strcat(T, P);
		strcat(T, "{");
		n = strlen(T);
		makeSA();

		for (int i = 0; i <= n; i++)
			if (SA[i] < m) {
				printf("%d\n", SA[i] + 1);
				break;
			}
	}

	return 0;
}
