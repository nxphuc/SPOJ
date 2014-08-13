/*
LINK: http://www.spoj.com/problems/BITMAP/
TAG: bfs
*/

#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;


#define ll long long
#define eps 1e-10

#define LET(x,p) __typeof(p) x
#define FORIT(it,p) for(__typeof(p.end()) it=p.begin();it!=p.end();it++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define ALL(p) p.begin(),p.end()
#define CLR(p) p.clear()
#define pb(p) push_back(p)
#define pii pair< int, int >
#define mset(p,v) memset(p,v,sizeof(p))
#define UB(p,v) upper_bound(ALL(p),v)
#define LB(p,v) lower_bound(ALL(p),v)

#define MAX 185
#define INF (1<<30)
char grid[MAX][MAX];
int graph[MAX][MAX];
int R, C;

inline bool inRange(int i, int j)
{
	return (i>=0 && i<R && j>=0 && j<C);
}

void bfs(pii s){
	pii u;
	int d;
	queue< pii > Q;
	Q.push(s);
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		FOR(i, (u.first-1), (u.first+1))
			FOR(j, (u.second-1), (u.second+1))
				if(inRange(i,j)){
					d = abs(i-s.first) + abs(j-s.second);
					if(graph[i][j] > d){
						graph[i][j] = d;
						Q.push(pii(i,j));
					}
				}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &R, &C);
		REP(i,R) scanf("%s", grid[i]);

		REP(i,R) REP(j,C) graph[i][j] = (grid[i][j]=='0')? INF : 0;

		REP(i,R)
			REP(j,C)
				if(grid[i][j]=='1')
					bfs(pii(i,j));

		REP(i,R){
			printf("%d", graph[i][0]);
			FOR(j,1,(C-1)) printf(" %d", graph[i][j]);
			printf("\n");
		}
	}
	return 0;
}
