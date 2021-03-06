/*
LINK: http://www.spoj.com/problems/ABSYS/
TAG: Ad-hoc
*/

#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

char str[100], *p;
int t, i, a[3];

int getint(char *s){
	int i, n = 0;
	for(i=0;s[i];i++){
		if(!isdigit(s[i])) return -1;
		n = n*10+s[i]-'0';
	}
	return n;
}

int main(){
	scanf("%d", &t);
	for(gets(str); t; t--){
		gets(str);
		gets(str);
		i = 0;
		p = strtok(str," +=");
		while(p){
			a[i++] = getint(p);
			p = strtok(0," +=");
		}
		if (a[0] == -1)
		  printf("%d + %d = %d\n", a[2] - a[1], a[1], a[2]);
		else
		  if(a[1] == -1)
		    printf("%d + %d = %d\n", a[0], a[2] - a[0], a[2]);
		  else
		    printf("%d + %d = %d\n", a[0], a[1], a[0] + a[1]);
	}
	return 0;
}
