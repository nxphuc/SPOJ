/*
LINK: http://www.spoj.com/problems/ARITH2/
TASK: ad-hoc
*/

#include <cstdio>
#define ll long long

bool isnum(char *str, ll &n, char &op){
	n = 0;
	if(str[0] < '0' || str[0] > '9'){
		op = str[0];
		return false;
	}
	for(int i = 0; str[i]; i++)
		n = n * 10 + (str[i] - '0');
	return true;
}

int main(){
	char token[30], op;
	int n;
	ll ans, num;
	scanf("%d", &n);
	while(n--){
		ans = 0;
		op = '+';
		while(scanf("%s", token) == 1){
			if(isnum(token, num, op)){
				switch(op){
					case '+': ans += num; break;
					case '-': ans -= num; break;
					case '*': ans *= num; break;
					case '/': ans /= num; break;
				}
			}
			else
				if(op == '='){
					printf("%lld\n", ans);
					break;
				}
		}
	}
	return 0;
}
