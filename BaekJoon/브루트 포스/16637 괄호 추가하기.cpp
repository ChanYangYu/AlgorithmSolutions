#include <bits/stdc++.h>
using namespace std;
char op[10];
int num[11];
char ex[20];
int n;
int mx = INT_MIN;

int calc(int a, int b, char o){
	if(o == '-')
		return a-b;
	else if(o == '+')
		return a+b;
	else if(o == '*')
		return a*b;
}

void solve(int idx, int nidx, int oidx){
	//기저 사례 
	if(idx >= n-1){
		//수 하나가 남은 경우 
		if(idx == n-1)
			num[nidx++] = ex[idx] - '0';
		
		//숫자 하나인 경우 
		if(nidx == 1){
			if(mx < num[0])
				mx = num[0];
			return;
		}
		//초깃값 계산 
		int res = calc(num[0], num[1], op[0]);
		
		//이 후 계산 
		for(int i = 2; i < nidx; i++)
			res = calc(res, num[i], op[i-1]);
		if(mx < res)
			mx = res;
	}
	else{
		num[nidx] = ex[idx] - '0';
		op[oidx] = ex[idx+1];
		//안묶은 경우 
		solve(idx+2, nidx+1, oidx+1);
		
		num[nidx] = calc(ex[idx] - '0', ex[idx+2] - '0', ex[idx+1]);
		
		//묶은 다음 연산할 수가 있는 경우 
		if(idx + 4 < n){
			op[oidx] = ex[idx+3];
			solve(idx+4, nidx+1, oidx+1);
		}
		//묶은 다음 더이상 연산이 없는 경우 
		else
			solve(idx+4, nidx+1, oidx);
	}
}
int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin>>n;
	cin>>ex;
	
	if(n == 1)
		cout<<ex;
	else{
		solve(0,0,0);
		cout<<mx;
	}
	return 0;
}
